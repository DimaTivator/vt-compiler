#include "string_processing.h"

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
                    next_free_addr += kStringLength;
                }
            }
        }
    }
}

}
