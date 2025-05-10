#include "asm_generation.h"

namespace vt::back {

namespace {
template <typename... Args>
std::string Concat(const std::string& first, const Args&... args) {
    std::ostringstream oss;
    oss << first;
    int index = 0;
    ((oss << (++index > 1 ? ", " : " ") << args), ...);
    return oss.str();
}

std::string Get(const std::variant<std::string, int>& arg) {
    if (const auto* str = std::get_if<std::string>(&arg)) {
        return *str;
    }
    return std::to_string(std::get<int>(arg));
}

void MakeLabelsValid(ir::IR& ir) {
    /*
     * Transforms labels from L1' to L1 (valid asm label) etc.
     */
    for (auto& instr : ir) {
        if (ir::IsLabel(instr.result)) {
            instr.result = instr.result.substr(0, instr.result.size() - 1);
        }
        if (const auto* arg1 = std::get_if<std::string>(&instr.arg1)) {
            if (ir::IsLabel(*arg1)) {
                instr.arg1 = arg1->substr(0, arg1->size() - 1);
            }
        }
        if (const auto* arg2 = std::get_if<std::string>(&instr.arg2)) {
            if (ir::IsLabel(*arg2)) {
                instr.arg2 = arg2->substr(0, arg2->size() - 1);
            }
        }
    }
}

}  // namespace

Asm GenerateASM(const ir::IR& ir) {
    ir::IR cleaned_ir = ir;
    MakeLabelsValid(cleaned_ir);

    Asm asm_result;
    asm_result.reserve(cleaned_ir.size());
    for (const auto& instr : cleaned_ir) {
        std::string asm_instr;
        switch (instr.op) {
            case (Op::ASSIGNS):
            case (Op::ASSIGN): {
                asm_instr = Concat("addi", instr.result, Get(instr.arg1), 0);
            } break;
            case (Op::LOAD_CONST): {
                asm_instr = Concat("li", instr.result, Get(instr.arg1));
            } break;
            case (Op::ADD): {
                if (std::holds_alternative<int>(instr.arg2)) {
                    asm_instr = Concat("addi", instr.result, Get(instr.arg1),
                                       std::get<int>(instr.arg2));
                } else {
                    asm_instr = Concat("add", instr.result, Get(instr.arg1),
                                       Get(instr.arg2));
                }
            } break;
            case (Op::SUB): {
                asm_instr = Concat("sub", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::MUL): {
                asm_instr = Concat("mul", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::DIV): {
                asm_instr = Concat("div", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::MOD): {
                    asm_instr = Concat("rem", instr.result, Get(instr.arg1),
                                       Get(instr.arg2));
            } break;
            case (Op::NOT): {
                asm_instr =
                    Concat("xor", instr.result, Get(instr.arg1), "0xFFF");
            } break;
            case (Op::CMP_EQ): {
                if (std::holds_alternative<int>(instr.arg2) &&
                    std::get<int>(instr.arg2) == 0) {
                    asm_instr =
                        Concat("seq", instr.result, Get(instr.arg1), "x0");
                } else {
                    asm_instr = Concat("seq", instr.result, Get(instr.arg1),
                                       Get(instr.arg2));
                }
            } break;
            case (Op::CMP_NE): {
                asm_instr = Concat("sne", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::CMP_LT): {
                asm_instr = Concat("slt", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::CMP_GT): {
                asm_instr = Concat("slt", instr.result, Get(instr.arg2),
                                   Get(instr.arg1));
            } break;
            case (Op::CMP_LE): {
                asm_instr = Concat("sge", instr.result, Get(instr.arg2),
                                   Get(instr.arg1));
            } break;
            case (Op::CMP_GE): {
                asm_instr = Concat("sge", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::AND): {
                asm_instr = Concat("and", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::OR): {
                asm_instr = Concat("or", instr.result, Get(instr.arg1),
                                   Get(instr.arg2));
            } break;
            case (Op::PRINT): {
                asm_instr = Concat("ewrite", Get(instr.arg1));
            } break;
            case (Op::LABEL): {
                asm_instr = instr.result + ":";
            } break;
            case (Op::BRANCH_IF_ZERO): {
                asm_instr = Concat("beq", Get(instr.arg1), "x0", instr.result);
            } break;
            case (Op::GOTO): {
                asm_instr = Concat("jal", "x0", instr.result);
            } break;
            case (Op::LOADA): {
                asm_instr = Concat("lw", instr.result, Get(instr.arg1), 0);
            } break;
            case (Op::STOREA): {
                asm_instr = Concat("sw", Get(instr.arg1), 0, instr.result);
            } break;
            default: {
                throw std::runtime_error(
                    "Unsupported IR operation: " +
                    ir::IRInstruction::OpToString(instr.op));
            }
        }
        asm_result.push_back(asm_instr);
    }
    asm_result.emplace_back("ebreak");
    return asm_result;
}

}  // namespace vt::back
