#pragma once

#include <string>
#include <variant>
#include <vector>

namespace vt::ir {

struct IRInstruction {
    enum class Op {
        ASSIGN,          // ASSIGN <reg>, <arg>, 0
        LOAD_CONST,      // LOAD_CONST <reg>, <value>, 0
        ADD,             // ADD <res>, <lhs>, <rhs>
        SUB,             // SUB <res>, <lhs>, <rhs>
        MUL,             // MUL <res>, <lhs>, <rhs>
        DIV,             // DIV <res>, <lhs>, <rhs>
        NOT,             // NOT <res>, <arg>
        AND,             // AND <res>, <lhs>, <rhs>
        OR,              // OR <res>, <lhs>, <rhs>
        PRINT,           // PRINT "", <arg>, 0
        LABEL,           // <label>:
        BRANCH_IF_ZERO,  // BRANCH_IF_ZERO <label>, <arg>, 0
        GOTO,            // GOTO <label>, 0, 0
        LOAD,            // LOAD  <phys_reg>, <spill_slot>, 0
        STORE,           // STORE <spill_slot>, <phys_reg>, 0
    } op;

    std::string result;
    std::variant<std::string, int> arg1, arg2;
};

using IR = std::vector<IRInstruction>;

}  // namespace vt::ir
