#include "string_processing.h"

#include <unordered_set>

namespace vt::ir {

StringProcessor::StringProcessor(const IR& ir) : addr_(0), ir_(ir) {
    vreg_index_ = GetLargestVReg(ir_) + 1;
    label_index_ = GetLargestLabel(ir) + 1;
}

void StringProcessor::SetStringOperations() {
    std::unordered_set<std::string> string_regs;

    using Op = IRInstruction::Op;
    const std::unordered_map<Op, Op> kStringOp = {
        {Op::LOAD_CONST, Op::LOAD_STR}, {Op::ASSIGN, Op::ASSIGNS},
        {Op::ADD, Op::CONCAT},          {Op::CMP_EQ, Op::CMP_EQS},
        {Op::CMP_NE, Op::CMP_NES},      {Op::CMP_LT, Op::CMP_LTS},
        {Op::CMP_GT, Op::CMP_GTS},      {Op::CMP_LE, Op::CMP_LES},
        {Op::CMP_GE, Op::CMP_GES},
    };

    for (auto& instr : ir_) {
        if (instr.op == Op::LOAD_CONST) {
            if (std::holds_alternative<std::string>(instr.arg1)) {
                instr.op = Op::LOAD_STR;
                string_regs.insert(instr.result);
            } else {
                if (string_regs.contains(instr.result)) {
                    string_regs.erase(instr.result);
                }
            }

        } else if (kStringOp.contains(instr.op)) {
            if (string_regs.contains(std::get<std::string>(instr.arg1))) {
                instr.op = kStringOp.at(instr.op);
                string_regs.insert(instr.result);
            } else {
                if (string_regs.contains(instr.result)) {
                    string_regs.erase(instr.result);
                }
            }
        }
    }
}

void StringProcessor::UpdateVregToAddr(const IRInstruction& instr) {
    if (instr.op == Op::LOAD_CONST) {
        if (std::holds_alternative<std::string>(instr.arg1) &&
            ir::IsAddr(std::get<std::string>(instr.arg1))) {
            //
            vreg_to_addr_[instr.result] = std::get<std::string>(instr.arg1);
        }
    }
}

std::string StringProcessor::GetNextVReg() {
    return "v" + std::to_string(vreg_index_++) + "'";
}

std::string StringProcessor::GetNextAddr() {
    return "addr" + std::to_string(addr_++) + "'";
}

std::string StringProcessor::GetNextLabel() {
    return "L" + std::to_string(label_index_++) + "'";
}

void StringProcessor::GenerateLoadStr(const IRInstruction& instr, IR& ir) {
    /*
    LOAD_CONST          addr_reg, addr
    -----------------------------------
    LOAD_CONST          reg, str[i]
    STOREA              reg, addr_reg
    ADD                 addr_reg, addr_reg, 1
    -----------------------------------
    LOAD_CONST          reg, 0
    STOREA              reg, addr_reg
    */
    auto reg = instr.result;
    auto addr_reg = GetNextVReg();
    auto str = std::get<std::string>(instr.arg1);
    std::string addr = GetNextAddr();

    ir.push_back({Op::LOAD_CONST, addr_reg, addr, ""});

    for (int i = 0; i < std::ssize(str); ++i) {
        ir.push_back({Op::LOAD_CONST, reg, str[i], ""});
        ir.push_back({Op::STOREA, reg, addr_reg, 0});
        ir.push_back({Op::ADD, addr_reg, addr_reg, 1});
    }

    ir.push_back({Op::LOAD_CONST, reg, 0, ""});
    ir.push_back({Op::STOREA, reg, addr_reg, 0});
    ir.push_back({Op::LOAD_CONST, reg, addr, 0});
}

IR StringProcessor::UnrollLoadStr(const IR& ir) {
    IR new_ir;
    new_ir.reserve(ir.size());
    for (const auto& instr : ir) {
        if (instr.op == Op::LOAD_STR) {
            GenerateLoadStr(instr, new_ir);
        } else {
            new_ir.push_back(instr);
        }
    }
    return new_ir;
}

void StringProcessor::GenerateConcat(const IRInstruction& instr, IR& ir) {
    /*
    LOAD_CONST          res_index_reg, result_addr
    LOAD_CONST          index_reg, 0

    LABEL               loop_label1
    LOAD_CONST          addr_reg, left_addr
    ADD                 addr_reg, addr_reg, index_reg
    LOADA               reg, addr_reg
    CMP_EQ              comp_res_reg, reg, 0
    BRANCH_IF_ZERO      cont_loop1, comp_res_reg
    GOTO                stop_loop1

    LABEL               cont_loop1
    STOREA              reg, res_index_reg
    ADD                 res_index_reg, res_index_reg, 1
    ADD                 index_reg, index_reg, 1
    GOTO                loop_label1

    LABEL               stop_loop1
    LOAD_CONST          index_reg, 0

    LABEL               loop_label2
    LOAD_CONST          addr_reg, right_addr
    ADD                 addr_reg, addr_reg, index_reg
    LOADA               reg, addr_reg
    CMP_EQ              comp_res_reg, reg, 0
    BRANCH_IF_ZERO      cont_loop2, comp_res_reg
    GOTO                stop_loop2

    LABEL               cont_loop2
    STOREA              reg, res_index_reg
    ADD                 res_index_reg, res_index_reg, 1
    ADD                 index_reg, index_reg, 1
    GOTO                loop_label2

    LABEL               stop_loop2
    LOAD_CONST          reg, 0
    STOREA              reg, res_index_reg
    LOAD_CONST          instr.result, result_addr
    */
    auto lhs = std::get<std::string>(instr.arg1);
    auto rhs = std::get<std::string>(instr.arg2);

    auto left_addr = vreg_to_addr_[lhs];
    auto right_addr = vreg_to_addr_[rhs];

    auto reg = GetNextVReg();
    auto index_reg = GetNextVReg();
    auto res_index_reg = GetNextVReg();
    auto addr_reg = GetNextVReg();
    auto comp_res_reg = GetNextVReg();

    auto loop_label1 = GetNextLabel();
    auto cont_loop1 = GetNextLabel();
    auto stop_loop1 = GetNextLabel();
    auto loop_label2 = GetNextLabel();
    auto cont_loop2 = GetNextLabel();
    auto stop_loop2 = GetNextLabel();

    auto result_addr = GetNextAddr();

    ir.push_back({Op::LOAD_CONST, res_index_reg, result_addr, ""});
    ir.push_back({Op::LOAD_CONST, index_reg, 0, ""});

    ir.push_back({Op::LABEL, loop_label1, 0, 0});
    ir.push_back({Op::LOAD_CONST, addr_reg, left_addr, ""});
    ir.push_back({Op::ADD, addr_reg, addr_reg, index_reg});
    ir.push_back({Op::LOADA, reg, addr_reg, 0});
    ir.push_back({Op::CMP_EQ, comp_res_reg, reg, 0});
    ir.push_back({Op::BRANCH_IF_ZERO, cont_loop1, comp_res_reg, 0});
    ir.push_back({Op::GOTO, stop_loop1, 0, 0});

    ir.push_back({Op::LABEL, cont_loop1, 0, 0});
    ir.push_back({Op::STOREA, reg, res_index_reg, 0});
    ir.push_back({Op::ADD, res_index_reg, res_index_reg, 1});
    ir.push_back({Op::ADD, index_reg, index_reg, 1});
    ir.push_back({Op::GOTO, loop_label1, 0, 0});

    ir.push_back({Op::LABEL, stop_loop1, 0, 0});
    ir.push_back({Op::LOAD_CONST, index_reg, 0, ""});

    ir.push_back({Op::LABEL, loop_label2, 0, 0});
    ir.push_back({Op::LOAD_CONST, addr_reg, right_addr, ""});
    ir.push_back({Op::ADD, addr_reg, addr_reg, index_reg});
    ir.push_back({Op::LOADA, reg, addr_reg, 0});
    ir.push_back({Op::CMP_EQ, comp_res_reg, reg, 0});
    ir.push_back({Op::BRANCH_IF_ZERO, cont_loop2, comp_res_reg, 0});
    ir.push_back({Op::GOTO, stop_loop2, 0, 0});

    ir.push_back({Op::LABEL, cont_loop2, 0, 0});
    ir.push_back({Op::STOREA, reg, res_index_reg, 0});
    ir.push_back({Op::ADD, res_index_reg, res_index_reg, 1});
    ir.push_back({Op::ADD, index_reg, index_reg, 1});
    ir.push_back({Op::GOTO, loop_label2, 0, 0});

    ir.push_back({Op::LABEL, stop_loop2, 0, 0});
    ir.push_back({Op::LOAD_CONST, reg, 0, ""});
    ir.push_back({Op::STOREA, reg, res_index_reg, 0});
    ir.push_back({Op::LOAD_CONST, instr.result, result_addr, ""});
}

IR StringProcessor::UnrollConcat(const IR& ir) {
    IR new_ir;
    new_ir.reserve(ir.size());
    for (const auto& instr : ir) {
        UpdateVregToAddr(instr);
        if (instr.op == Op::CONCAT) {
            GenerateConcat(instr, new_ir);
            continue;
        }
        new_ir.push_back(instr);
    }
    return new_ir;
}

const std::unordered_map<Op, Op> StringProcessor::kStringCompToNumComp = {
    {Op::CMP_EQS, Op::CMP_EQ}, {Op::CMP_NES, Op::CMP_NE},
    {Op::CMP_LTS, Op::CMP_LT}, {Op::CMP_GTS, Op::CMP_GT},
    {Op::CMP_LES, Op::CMP_LE}, {Op::CMP_GES, Op::CMP_GE},
};

void StringProcessor::GenerateCompare(const IRInstruction& instr, IR& ir) {
    /*
    !!! Compare by first symbol !!!

    LOAD_CONST                  addr_reg, left_addr
    LOADA                       left_symbol_reg, addr_reg
    LOAD_CONST                  addr_reg, right_addr
    LOADA                       right_symbol_reg, addr_reg

    {NUMERIC CMP_OPERATION}     instr.result, left_symbol_reg, right_symbol_reg
    */

    auto left_addr = vreg_to_addr_[std::get<std::string>(instr.arg1)];
    auto right_addr = vreg_to_addr_[std::get<std::string>(instr.arg2)];

    auto addr_reg = GetNextVReg();
    auto left_symbol_reg = GetNextVReg();
    auto right_symbol_reg = GetNextVReg();

    ir.push_back({Op::LOAD_CONST, addr_reg, left_addr, ""});
    ir.push_back({Op::LOADA, left_symbol_reg, addr_reg, 0});
    ir.push_back({Op::LOAD_CONST, addr_reg, right_addr, ""});
    ir.push_back({Op::LOADA, right_symbol_reg, addr_reg, 0});
    ir.push_back({kStringCompToNumComp.at(instr.op), instr.result,
                  left_symbol_reg, right_symbol_reg});
}

IR StringProcessor::UnrollCompare(const IR& ir) {
    IR new_ir;
    new_ir.reserve(ir.size());
    for (const auto& instr : ir) {
        UpdateVregToAddr(instr);
        if (kStringCompToNumComp.contains(instr.op)) {
            GenerateCompare(instr, new_ir);
            continue;
        }
        new_ir.push_back(instr);
    }
    return new_ir;
}

void StringProcessor::GeneratePrint(const IRInstruction& instr, IR& ir) {
    /*
    LOAD_CONST          addr_reg, addr

    LABEL               loop_label
    LOADA               reg, addr_reg
    CMP_EQ              comp_reg_reg, reg, 0
    BRANCH_IF_ZERO      cont_loop, comp_reg_reg
    GOTO                stop_loop

    LABEL               cont_loop
    PRINT               reg
    ADD                 addr_reg, addr_reg, 1
    GOTO                loop_label

    LABEL               stop_loop
    */

    auto addr = vreg_to_addr_[std::get<std::string>(instr.arg1)];
    auto reg = GetNextVReg();
    auto addr_reg = GetNextVReg();
    auto comp_reg_reg = GetNextVReg();

    auto loop_label = GetNextLabel();
    auto cont_loop = GetNextLabel();
    auto stop_loop = GetNextLabel();

    ir.push_back({Op::LOAD_CONST, addr_reg, addr, ""});

    ir.push_back({Op::LABEL, loop_label, 0, 0});
    ir.push_back({Op::LOADA, reg, addr_reg, 0});
    ir.push_back({Op::CMP_EQ, comp_reg_reg, reg, 0});
    ir.push_back({Op::BRANCH_IF_ZERO, cont_loop, comp_reg_reg, 0});
    ir.push_back({Op::GOTO, stop_loop, 0, 0});

    ir.push_back({Op::LABEL, cont_loop, 0, 0});
    ir.push_back({Op::PRINT, "", reg, 0});
    ir.push_back({Op::ADD, addr_reg, addr_reg, 1});
    ir.push_back({Op::GOTO, loop_label, 0, 0});

    ir.push_back({Op::LABEL, stop_loop, 0, 0});
}

IR StringProcessor::UnrollPrint(const IR& ir) {
    IR new_ir;
    new_ir.reserve(ir.size());
    for (const auto& instr : ir) {
        UpdateVregToAddr(instr);
        if (instr.op == Op::PRINT) {
            GeneratePrint(instr, new_ir);
            continue;
        }
        new_ir.push_back(instr);
    }
    return new_ir;
}

IR StringProcessor::Process() {
    SetStringOperations();
    ir_ = UnrollLoadStr(ir_);
    ir_ = UnrollConcat(ir_);
    ir_ = UnrollCompare(ir_);
    ir_ = UnrollPrint(ir_);
    return ir_;
}

}  // namespace vt::ir
