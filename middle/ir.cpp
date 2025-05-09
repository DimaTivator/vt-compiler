#include "ir.h"

#include <algorithm>
#include <regex>

namespace vt::ir {

const std::unordered_map<std::string, IRInstruction::Op>
    IRInstruction::kStringToBinOp = {
        {"+", IRInstruction::Op::ADD},     {"-", IRInstruction::Op::SUB},
        {"*", IRInstruction::Op::MUL},     {"/", IRInstruction::Op::DIV},
        {"==", IRInstruction::Op::CMP_EQ}, {"!=", IRInstruction::Op::CMP_NE},
        {"<", IRInstruction::Op::CMP_LT},  {">", IRInstruction::Op::CMP_GT},
        {"<=", IRInstruction::Op::CMP_LE}, {">=", IRInstruction::Op::CMP_GE},
        {"and", IRInstruction::Op::AND},   {"or", IRInstruction::Op::OR},
};

const std::unordered_map<IRInstruction::Op, std::string>
    IRInstruction::kOpToString = {
        {IRInstruction::Op::ASSIGN, "ASSIGN"},
        {IRInstruction::Op::ASSIGNS, "ASSIGNS"},
        {IRInstruction::Op::LOAD_CONST, "LOAD_CONST"},
        {IRInstruction::Op::LOAD_STR, "LOAD_STR"},
        {IRInstruction::Op::ADD, "ADD"},
        {IRInstruction::Op::SUB, "SUB"},
        {IRInstruction::Op::MUL, "MUL"},
        {IRInstruction::Op::DIV, "DIV"},
        {IRInstruction::Op::NOT, "NOT"},
        {IRInstruction::Op::CONCAT, "CONCAT"},
        {IRInstruction::Op::CMP_EQ, "CMP_EQ"},
        {IRInstruction::Op::CMP_EQS, "CMP_EQS"},
        {IRInstruction::Op::CMP_NE, "CMP_NE"},
        {IRInstruction::Op::CMP_NES, "CMP_NES"},
        {IRInstruction::Op::CMP_LT, "CMP_LT"},
        {IRInstruction::Op::CMP_LTS, "CMP_LTS"},
        {IRInstruction::Op::CMP_GT, "CMP_GT"},
        {IRInstruction::Op::CMP_GTS, "CMP_GTS"},
        {IRInstruction::Op::CMP_LE, "CMP_LE"},
        {IRInstruction::Op::CMP_LES, "CMP_LES"},
        {IRInstruction::Op::CMP_GE, "CMP_GE"},
        {IRInstruction::Op::CMP_GES, "CMP_GES"},
        {IRInstruction::Op::AND, "AND"},
        {IRInstruction::Op::OR, "OR"},
        {IRInstruction::Op::PRINT, "PRINT"},
        {IRInstruction::Op::LABEL, "LABEL"},
        {IRInstruction::Op::BRANCH_IF_ZERO, "BRANCH_IF_ZERO"},
        {IRInstruction::Op::GOTO, "GOTO"},
        {IRInstruction::Op::LOAD, "LOAD"},
        {IRInstruction::Op::LOADA, "LOADA"},
        {IRInstruction::Op::STORE, "STORE"},
        {IRInstruction::Op::STOREA, "STOREA"}};

IRInstruction::Op IRInstruction::StringToBinOp(const std::string& op) {
    if (IRInstruction::kStringToBinOp.contains(op)) {
        return IRInstruction::kStringToBinOp.at(op);
    }
    throw std::runtime_error("Unsupported binary op: " + op);
}

std::string IRInstruction::OpToString(IRInstruction::Op op) {
    return kOpToString.at(op);
}

bool IsVReg(const std::string& name) {
    return std::regex_match(name, std::regex("v[0-9]+'"));
}

bool IsLabel(const std::string& name) {
    return std::regex_match(name, std::regex("L[0-9]+'$"));
}

bool IsAddr(const std::string& name) {
    return std::regex_match(name, std::regex("addr[0-9]+'"));
}

bool IsSpill(const std::string& name) {
    return std::regex_match(name, std::regex("spill[0-9]+'"));
}

int GetLargestVReg(const IR& ir) {
    int max = 0;
    for (const auto& instr : ir) {
        if (IsVReg(instr.result)) {
            std::string reg_num =
                instr.result.substr(1, instr.result.size() - 2);
            int num = std::stoi(reg_num);
            max = std::max(num, max);
        }
    }
    return max;
}

int GetLargestLabel(const IR& ir) {
    int max = 0;
    for (const auto& instr : ir) {
        if (instr.op == IRInstruction::Op::LABEL) {
            std::string label_num =
                instr.result.substr(1, instr.result.size() - 2);
            int num = std::stoi(label_num);
            max = std::max(num, max);
        }
    }
    return max;
}

}  // namespace vt::ir
