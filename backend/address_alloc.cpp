#include "address_alloc.h"

namespace vt::back {

void AllocateStrings(ir::IR& ir) {
    std::unordered_map<std::string, int> addr_label_to_phys;
    int next_free_addr = kStringsSectionStart;
    for (auto& instr : ir) {
        if (instr.op == Op::LOAD_CONST) {
            if (std::holds_alternative<std::string>(instr.arg1) &&
                ir::IsAddr(std::get<std::string>(instr.arg1))) {
                auto addr = std::get<std::string>(instr.arg1);
                if (addr_label_to_phys.contains(addr)) {
                    instr.arg1 = addr_label_to_phys.at(addr);
                } else {
                    addr_label_to_phys[addr] = next_free_addr;
                    instr.arg1 = next_free_addr;
                    next_free_addr += kStringLength;
                }
            }
        }
    }
}

ir::IR AllocateSpillSlots(const ir::IR& ir) {
    int next_free_slot = kSpillSectionStart;
    std::unordered_map<std::string, int> spill_to_phys;
    ir::IR new_ir;
    for (auto instr : ir) {
        if (instr.op == Op::STORE) {
            if (ir::IsSpill(instr.result)) {
                auto spill = instr.result;
                if (spill_to_phys.contains(spill)) {
                    auto addr = spill_to_phys.at(spill);
                    new_ir.push_back({Op::LOAD_CONST, kSpillAddrReg, addr, 0});
                } else {
                    spill_to_phys[spill] = next_free_slot++;
                    new_ir.push_back({Op::LOAD_CONST, kSpillAddrReg,
                                      spill_to_phys[spill], 0});
                }
                instr.op = Op::STOREA;
                instr.result = std::get<std::string>(instr.arg1);
                instr.arg1 = kSpillAddrReg;
            }
        } else if (instr.op == Op::LOAD) {
            if (std::holds_alternative<std::string>(instr.arg1) &&
                ir::IsSpill(std::get<std::string>(instr.arg1))) {
                //
                auto addr = spill_to_phys.at(std::get<std::string>(instr.arg1));
                new_ir.push_back({Op::LOAD_CONST, kSpillAddrReg, addr, 0});
                instr.op = Op::LOADA;
                instr.arg1 = kSpillAddrReg;
            }
        }
        new_ir.push_back(instr);
    }
    return new_ir;
}

}  // namespace vt::back
