#include "ir_generator.h"

#include <regex>
#include <unordered_map>

namespace vt::ir {

IRGenerator::IRGenerator() : temp_count_(0), label_count_(0) {}

IR IRGenerator::Generate(const std::shared_ptr<vt::ast::BlockNode>& root) {
    EmitBlock(root);
    return ir_;
}

IR IRGenerator::Generate(const std::shared_ptr<vt::ast::ASTNode>& root) {
    EmitBlockNode(root);
    return ir_;
}

std::string IRGenerator::NewRegister() {
    return "v" + std::to_string(temp_count_++) + "'";
}

std::string IRGenerator::NewLabel() {
    return "L" + std::to_string(label_count_++) + "'";
}

void IRGenerator::Emit(const IRInstruction& instr) { ir_.push_back(instr); }

std::string IRGenerator::ProcessUnaryOpNode(
    const std::shared_ptr<vt::ast::UnaryOpNode>& node) {
    //
    auto operand_t = EmitExpr(node->operand);
    auto reg = NewRegister();
    if (node->op == "-") {
        Emit({IRInstruction::Op::LOAD_CONST, reg, 0, 0});
        Emit({IRInstruction::Op::SUB, reg, reg, operand_t});
        return reg;
    }
    if (node->op == "not") {
        Emit({IRInstruction::Op::LOAD_CONST, reg, 0, 0});
        Emit({IRInstruction::Op::NOT, reg, operand_t, 0});
        return reg;
    }
    throw std::runtime_error("Unsupported unary op: " + node->op);
}

std::string IRGenerator::ProcessBinaryOpNode(
    const std::shared_ptr<vt::ast::BinaryOpNode>& node) {
    //
    auto lhs = EmitExpr(node->left);
    auto rhs = EmitExpr(node->right);
    auto reg = NewRegister();
    IRInstruction::Op op = IRInstruction::StringToBinOp(node->op);
    Emit({op, reg, lhs, rhs});
    return reg;
}

std::string IRGenerator::EmitExpr(const std::shared_ptr<ast::ASTNode>& node) {
    if (auto lit = std::dynamic_pointer_cast<ast::IntLiteralNode>(node)) {
        std::string reg = NewRegister();
        Emit({IRInstruction::Op::LOAD_CONST, reg, lit->value, 0});
        return reg;
    }

    if (auto lit = std::dynamic_pointer_cast<ast::StringLiteralNode>(node)) {
        std::string reg = NewRegister();
        Emit({IRInstruction::Op::LOAD_CONST, reg, lit->value, ""});
        return reg;
    }

    if (auto ref = std::dynamic_pointer_cast<ast::VarRefNode>(node)) {
        return ref->var_name;
    }

    if (auto un = std::dynamic_pointer_cast<ast::UnaryOpNode>(node)) {
        return ProcessUnaryOpNode(un);
    }

    if (auto bin = std::dynamic_pointer_cast<ast::BinaryOpNode>(node)) {
        return ProcessBinaryOpNode(bin);
    }

    throw std::runtime_error("Unsupported expr node");
}

void IRGenerator::ProcessIfNode(const std::shared_ptr<ast::IfNode>& node) {
    auto cond_t = EmitExpr(node->condition);
    auto else_l = NewLabel();
    auto end_l = NewLabel();

    Emit({IRInstruction::Op::BRANCH_IF_ZERO, else_l, cond_t, 0});
    EmitBlockNode(node->then_block);
    Emit({IRInstruction::Op::GOTO, end_l, 0, 0});
    Emit({IRInstruction::Op::LABEL, else_l, 0, 0});

    if (node->else_block) {
        EmitBlockNode(node->else_block);
    }

    Emit({IRInstruction::Op::LABEL, end_l, 0, 0});
}

void IRGenerator::ProcessWhileNode(
    const std::shared_ptr<ast::WhileNode>& node) {
    //
    auto start_l = NewLabel();
    auto end_l = NewLabel();

    Emit({IRInstruction::Op::LABEL, start_l, 0, 0});

    auto cond_t = EmitExpr(node->condition);

    Emit({IRInstruction::Op::BRANCH_IF_ZERO, end_l, cond_t, 0});
    EmitBlockNode(node->body);
    Emit({IRInstruction::Op::GOTO, start_l, 0, 0});
    Emit({IRInstruction::Op::LABEL, end_l, 0, 0});
}

void IRGenerator::EmitStatement(const std::shared_ptr<vt::ast::ASTNode>& node) {
    if (auto decl = std::dynamic_pointer_cast<ast::VarDeclNode>(node)) {
        auto rhs = EmitExpr(decl->init_expr);
        Emit({IRInstruction::Op::ASSIGN, decl->var_name, rhs, 0});
        return;
    }

    if (auto assign = std::dynamic_pointer_cast<ast::AssignmentNode>(node)) {
        auto rhs = EmitExpr(assign->expr);
        Emit({IRInstruction::Op::ASSIGN, assign->var_name, rhs, 0});
        return;
    }

    if (auto print = std::dynamic_pointer_cast<ast::PrintNode>(node)) {
        auto arg = EmitExpr(print->expr);
        Emit({IRInstruction::Op::PRINT, "", arg, 0});
        return;
    }

    if (auto block = std::dynamic_pointer_cast<ast::BlockNode>(node)) {
        EmitBlock(block);
        return;
    }

    if (auto if_node = std::dynamic_pointer_cast<ast::IfNode>(node)) {
        ProcessIfNode(if_node);
        return;
    }

    if (auto while_node = std::dynamic_pointer_cast<ast::WhileNode>(node)) {
        ProcessWhileNode(while_node);
        return;
    }

    throw std::runtime_error("Unsupported statement node");
}

void IRGenerator::EmitBlock(const std::shared_ptr<vt::ast::BlockNode>& block) {
    for (auto& stmt : block->statements) {
        EmitStatement(stmt);
    }
}

void IRGenerator::EmitBlockNode(const std::shared_ptr<vt::ast::ASTNode>& node) {
    auto block = std::dynamic_pointer_cast<vt::ast::BlockNode>(node);
    EmitBlock(block);
}

namespace {

bool IsVReg(const std::string& name) {
    return std::regex_match(name, std::regex("v[0-9]+'$"));
}

bool IsLabel(const std::string& name) {
    return std::regex_match(name, std::regex("L[0-9]+'$"));
}

IRInstruction::Op AssignVarToReg(
    IRInstruction instr,
    std::unordered_map<std::string, std::string>& var_to_reg) {
    //
    if (!IsVReg(instr.result)) {
        std::string var = instr.result;
        if (const auto* reg = std::get_if<std::string>(&instr.arg1)) {
            var_to_reg[var] = *reg;
        }
    }
}

IRInstruction ReplaceVarWithReg(
    IRInstruction instr,
    const std::unordered_map<std::string, std::string>& var_to_reg) {
    //
    IRInstruction new_instr = instr;
    if (!IsVReg(instr.result) && var_to_reg.contains(instr.result)) {
        new_instr.result = var_to_reg.at(instr.result);
    }
    if (const auto* arg1 = std::get_if<std::string>(&instr.arg1)) {
        if (!IsVReg(*arg1) && var_to_reg.contains(*arg1)) {
            new_instr.arg1 = var_to_reg.at(*arg1);
        }
    }
    if (const auto* arg2 = std::get_if<std::string>(&instr.arg2)) {
        if (!IsVReg(*arg2) && var_to_reg.contains(*arg2)) {
            new_instr.arg2 = var_to_reg.at(*arg2);
        }
    }
    return new_instr;
}

}  // namespace

IR RemoveVariableNames(const IR& ir) {
    IR result;
    std::unordered_map<std::string, std::string> var_to_reg;

    for (const auto& instr : ir) {
        switch (instr.op) {
            case IRInstruction::Op::ASSIGN: {
                AssignVarToReg(instr, var_to_reg);
            } break;
            case IRInstruction::Op::LABEL:
            case IRInstruction::Op::LOAD_CONST: {
                result.push_back(instr);
            } break;
            default: {
                result.push_back(ReplaceVarWithReg(instr, var_to_reg));
            }
        }
    }

    return result;
}

}  // namespace vt::ir
