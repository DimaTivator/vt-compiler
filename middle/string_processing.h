#pragma once

#include "ir.h"

namespace vt::ir {

using Op = IRInstruction::Op;

class StringProcessor {
public:
    explicit StringProcessor(const IR& ir);

    IR Process();

private:
    static const std::unordered_map<Op, Op> kStringCompToNumComp;

    int addr_;
    int vreg_index_;
    int label_index_;
    IR ir_;

    std::unordered_map<std::string, std::string> vreg_to_addr_;

    void UpdateVregToAddr(const IRInstruction& instr);

    std::string GetNextVReg();
    std::string GetNextAddr();
    std::string GetNextLabel();

    void SetStringOperations();

    void GenerateLoadStr(const IRInstruction& instr, IR& ir);
    IR UnrollLoadStr(const IR& ir);

    void GenerateConcat(const IRInstruction& instr, IR& ir);
    IR UnrollConcat(const IR& ir);

    void GenerateCompare(const IRInstruction& instr, IR& ir);
    IR UnrollCompare(const IR& ir);


    void GeneratePrinti(const IRInstruction& instr, IR& ir);
    IR UnrollPrinti(const IR& ir);

    void GeneratePrints(const IRInstruction& instr, IR& ir);
    IR UnrollPrints(const IR& ir);
};

}  // namespace vt::ir