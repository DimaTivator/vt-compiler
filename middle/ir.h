#pragma once

#include <string>
#include <variant>
#include <vector>

namespace vt::ir {

struct IRInstruction {
    enum class Op {
        ASSIGN,
        LOAD_CONST,
        ADD,
        SUB,
        MUL,
        DIV,
        NOT,
        AND,
        OR,
        PRINT,
        LABEL,
        BRANCH_IF_ZERO,
        GOTO
    } op;

    std::string result;
    std::variant<std::string, int> arg1, arg2;
};

using IR = std::vector<IRInstruction>;

}  // namespace vt::ir
