#pragma once

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace vt::ir {

struct IRInstruction {
    // clang-format off
    enum class Op {
        ASSIGN,          // ASSIGN <reg>, <arg>, 0
        ASSIGNS,         // ASSIGNS <reg>, <arg>, 0              [for string]
        LOAD_CONST,      // LOAD_CONST <reg>, <value>, 0         [for numeric]
        LOAD_STR,        // LOAD_STR <reg>, <value>, 0           [for string]
        ADD,             // ADD <res>, <lhs>, <rhs>
        SUB,             // SUB <res>, <lhs>, <rhs>
        MUL,             // MUL <res>, <lhs>, <rhs>
        DIV,             // DIV <res>, <lhs>, <rhs>
        NOT,             // NOT <res>, <arg>
        CONCAT,          // CONCAT <res>, <lhs>, <rhs>           [for string]
        CMP_EQ,          // CMP_EQ <res>, <lhs>, <rhs>
        CMP_EQS,         // CMP_EQS <res>, <lhs>, <rhs>          [for string]
        CMP_NE,          // CMP_NE <res>, <lhs>, <rhs>
        CMP_NES,         // CMP_NES <res>, <lhs>, <rhs>          [for string]
        CMP_LT,          // CMP_LT <res>, <lhs>, <rhs>
        CMP_LTS,         // CMP_LTS <res>, <lhs>, <rhs>          [for string]
        CMP_GT,          // CMP_GT <res>, <lhs>, <rhs>
        CMP_GTS,         // CMP_GTS <res>, <lhs>, <rhs>          [for string]
        CMP_LE,          // CMP_LE <res>, <lhs>, <rhs>
        CMP_LES,         // CMP_LES <res>, <lhs>, <rhs>          [for string]
        CMP_GE,          // CMP_GE <res>, <lhs>, <rhs>
        CMP_GES,         // CMP_GES <res>, <lhs>, <rhs>          [for string]
        AND,             // AND <res>, <lhs>, <rhs>
        OR,              // OR <res>, <lhs>, <rhs>
        PRINT,           // PRINT "", <arg>, 0
        LABEL,           // LABEL <label>, 0, 0
        BRANCH_IF_ZERO,  // BRANCH_IF_ZERO <label>, <arg>, 0
        GOTO,            // GOTO <label>, 0, 0

        LOAD,            // LOAD    <phys_reg>, <spill_slot>, 0
        STORE,           // STORE   <phys_reg>, <spill_slot>, 0

        LOADA,           // LOADA    <phys_reg>, <addr>, 0
        STOREA,          // STOREA   <phys_reg>, <addr>, 0
    } op;
    // clang-format on

    std::string result;
    std::variant<std::string, int> arg1, arg2;

    static Op StringToBinOp(const std::string& op);
    static std::string OpToString(Op op);

private:
    static const std::unordered_map<std::string, Op> kStringToBinOp;
    static const std::unordered_map<Op, std::string> kOpToString;
};

bool IsVReg(const std::string& name);
bool IsLabel(const std::string& name);
bool IsAddr(const std::string& name);

int GetLargestVReg(const std::vector<IRInstruction>& ir);
int GetLargestLabel(const std::vector<IRInstruction>& ir);

using IR = std::vector<IRInstruction>;

}  // namespace vt::ir
