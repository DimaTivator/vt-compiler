#include "ir_utils.h"

#include <iostream>
#include <string>
#include <variant>
#include <vector>

namespace vt::ir {

void PrintOperand(const std::variant<std::string, int>& arg) {
    if (std::holds_alternative<int>(arg)) {
        std::cout << std::get<int>(arg);
    } else {
        std::cout << std::get<std::string>(arg);
    }
}

void PrintIR(const IR& ir) {
    for (const auto& instr : ir) {
        using Op = IRInstruction::Op;
        switch (instr.op) {
            case Op::ASSIGN:
            case Op::LOAD_CONST: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
            } break;
            case Op::ADD: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
                std::cout << " + ";
                PrintOperand(instr.arg2);
            } break;
            case Op::SUB: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
                std::cout << " - ";
                PrintOperand(instr.arg2);
            } break;
            case Op::MUL: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
                std::cout << " * ";
                PrintOperand(instr.arg2);
            } break;
            case Op::DIV: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
                std::cout << " / ";
                PrintOperand(instr.arg2);
            } break;
            case Op::NOT: {
                std::cout << "not ";
                PrintOperand(instr.arg1);
            } break;
            case Op::AND: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
                std::cout << " and ";
                PrintOperand(instr.arg2);
            } break;
            case Op::OR: {
                std::cout << instr.result << " = ";
                PrintOperand(instr.arg1);
                std::cout << " or ";
                PrintOperand(instr.arg2);
            } break;
            case Op::PRINT: {
                std::cout << "print ";
                PrintOperand(instr.arg1);
            } break;
            case Op::LABEL: {
                std::cout << "\n";
                PrintOperand(instr.result);
                std::cout << ":";
            } break;
            case Op::BRANCH_IF_ZERO: {
                std::cout << "if ";
                PrintOperand(instr.arg1);
                std::cout << " == 0 goto ";
                PrintOperand(instr.result);
            } break;
            case Op::GOTO: {
                std::cout << "goto ";
                PrintOperand(instr.result);
            } break;
            case Op::LOAD: {
                std::cout << instr.result << " = LOAD ";
                PrintOperand(instr.arg1);
            } break;
            case Op::STORE: {
                std::cout << "STORE ";
                PrintOperand(instr.arg1);
                std::cout << ", " << instr.result;
            } break;
        }
        std::cout << "\n";
    }
}

}  // namespace vt::ir
