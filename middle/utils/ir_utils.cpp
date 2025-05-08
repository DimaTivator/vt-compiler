#include "ir_utils.h"

#include <iostream>
#include <string>
#include <variant>
#include <vector>

namespace vt::ir {

void PrintOperand(const std::variant<std::string, int>& arg,
                  std::ostream& out) {
    if (std::holds_alternative<int>(arg)) {
        out << std::get<int>(arg);
    } else {
        out << std::get<std::string>(arg);
    }
}

void PrettyPrintIR(const IR& ir, std::ostream& out) {
    for (const auto& instr : ir) {
        using Op = IRInstruction::Op;
        switch (instr.op) {
            case Op::ASSIGN:
            case Op::LOAD_CONST: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
            } break;
            case Op::ADD: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
                out << " + ";
                PrintOperand(instr.arg2, out);
            } break;
            case Op::SUB: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
                out << " - ";
                PrintOperand(instr.arg2, out);
            } break;
            case Op::MUL: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
                out << " * ";
                PrintOperand(instr.arg2, out);
            } break;
            case Op::DIV: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
                out << " / ";
                PrintOperand(instr.arg2, out);
            } break;
            case Op::NOT: {
                out << "not ";
                PrintOperand(instr.arg1, out);
            } break;
            case Op::CMP_EQ: {
                out << instr.result << " = (";
                PrintOperand(instr.arg1, out);
                out << " == ";
                PrintOperand(instr.arg2, out);
                out << ")";
            } break;
            case Op::CMP_NE: {
                out << instr.result << " = (";
                PrintOperand(instr.arg1, out);
                out << " != ";
                PrintOperand(instr.arg2, out);
                out << ")";
            } break;
            case Op::CMP_LT: {
                out << instr.result << " = (";
                PrintOperand(instr.arg1, out);
                out << " < ";
                PrintOperand(instr.arg2, out);
                out << ")";
            } break;
            case Op::CMP_GT: {
                out << instr.result << " = (";
                PrintOperand(instr.arg1, out);
                out << " > ";
                PrintOperand(instr.arg2, out);
                out << ")";
            } break;
            case Op::CMP_LE: {
                out << instr.result << " = (";
                PrintOperand(instr.arg1, out);
                out << " <= ";
                PrintOperand(instr.arg2, out);
                out << ")";
            } break;
            case Op::CMP_GE: {
                out << instr.result << " = (";
                PrintOperand(instr.arg1, out);
                out << " >= ";
                PrintOperand(instr.arg2, out);
                out << ")";
            } break;
            case Op::AND: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
                out << " and ";
                PrintOperand(instr.arg2, out);
            } break;
            case Op::OR: {
                out << instr.result << " = ";
                PrintOperand(instr.arg1, out);
                out << " or ";
                PrintOperand(instr.arg2, out);
            } break;
            case Op::PRINT: {
                out << "print ";
                PrintOperand(instr.arg1, out);
            } break;
            case Op::LABEL: {
                out << "\n";
                PrintOperand(instr.result, out);
                out << ":";
            } break;
            case Op::BRANCH_IF_ZERO: {
                out << "if ";
                PrintOperand(instr.arg1, out);
                out << " == 0 goto ";
                PrintOperand(instr.result, out);
            } break;
            case Op::GOTO: {
                out << "goto ";
                PrintOperand(instr.result, out);
            } break;
            case Op::LOAD: {
                out << instr.result << " = LOAD ";
                PrintOperand(instr.arg1, out);
            } break;
            case Op::STORE: {
                out << "STORE ";
                PrintOperand(instr.arg1, out);
                out << ", " << instr.result;
            } break;
        }
        out << "\n";
    }
}

void PrintIR(const IR& ir, std::ostream& out) {
    for (const auto& instr : ir) {
        out << IRInstruction::OpToString(instr.op) << " ";
        out << instr.result << ", ";
        PrintOperand(instr.arg1, out);
        out << ", ";
        PrintOperand(instr.arg2, out);
        out << "\n";
    }
}

}  // namespace vt::ir
