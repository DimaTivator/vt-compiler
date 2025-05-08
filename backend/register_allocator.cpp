#include "register_allocator.h"

#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace vt::back {

namespace {

struct Interval {
    std::string reg;
    int start{};
    int end{};

    bool operator<(const Interval& other) const {
        if (start == other.start) {
            return end < other.end;
        }
        return start < other.start;
    }
};

using IR = ir::IR;

std::vector<Interval> ComputeLiveIntervals(const IR& ir) {
    std::unordered_map<std::string, Interval> intervals;
    for (int i = 0; i < std::ssize(ir); ++i) {
        const auto& instr = ir[i];
        auto process = [&](const std::string& reg) {
            if (!ir::IsVReg(reg)) {
                return;
            }
            if (!intervals.contains(reg)) {
                intervals[reg] = {reg, i, i};
            } else {
                intervals[reg].end = i;
            }
        };
        process(instr.result);
        if (const auto* arg1 = std::get_if<std::string>(&instr.arg1)) {
            process(*arg1);
        }
        if (const auto* arg1 = std::get_if<std::string>(&instr.arg2)) {
            process(*arg1);
        }
    }

    std::vector<Interval> result;
    result.reserve(intervals.size());
    for (auto& [_, interval] : intervals) {
        result.push_back(interval);
    }

    std::sort(result.begin(), result.end());

    return result;
}

void ExpireOldIntervals(
    int pos, std::set<Interval>& active, std::set<int>& free_regs,
    const std::unordered_map<std::string, std::string>& reg_map) {
    //
    std::set<Interval> remaining;
    for (const auto& interval : active) {
        if (interval.end >= pos) {
            remaining.insert(interval);
        } else {
            const auto& phys_reg = reg_map.at(interval.reg);
            auto phys_reg_index =
                std::find(kPhysRegs.begin(), kPhysRegs.end(), phys_reg) -
                kPhysRegs.begin();
            free_regs.insert(static_cast<int>(phys_reg_index));
        }
    }
    active.swap(remaining);
}

void AllocateIntervals(const std::vector<Interval>& intervals,
                       std::set<int>& free_regs,
                       std::unordered_map<std::string, std::string>& reg_map,
                       std::unordered_map<std::string, int>& spill_slot) {
    std::set<Interval> active;
    int next_slot = 0;
    for (const auto& interval : intervals) {
        ExpireOldIntervals(interval.start, active, free_regs, reg_map);
        if (active.size() == kPhysRegs.size()) {
            auto spill = *std::prev(active.end());
            if (spill.end > interval.end) {
                reg_map[interval.reg] = reg_map[spill.reg];
                spill_slot[spill.reg] = next_slot++;
                active.erase(std::prev(active.end()));
                active.insert(interval);
            } else {
                auto phys_reg = reg_map.at(spill.reg);
                reg_map[interval.reg] = phys_reg;
                spill_slot[interval.reg] = next_slot++;
            }
        } else {
            int phys_reg_index = *free_regs.begin();
            free_regs.erase(free_regs.begin());
            reg_map[interval.reg] = kPhysRegs[phys_reg_index];
            active.insert(interval);
        }
    }
}

IR RewriteIR(const IR& ir,
             const std::unordered_map<std::string, std::string>& reg_map,
             const std::unordered_map<std::string, int>& spill_slot) {
    IR new_ir;

    auto handle_arg = [&](auto& arg) {
        if (auto preg = std::get_if<std::string>(&arg)) {
            const auto& vr = *preg;
            if (ir::IsVReg(vr)) {
                const auto& phys_src = reg_map.at(vr);
                auto it = spill_slot.find(vr);
                if (it != spill_slot.end()) {
                    int slot = it->second;
                    new_ir.push_back({ir::IRInstruction::Op::LOAD, phys_src,
                                      std::to_string(slot)});
                }
                return phys_src;
            }
        }
        if (auto str = std::get_if<std::string>(&arg)) {
            return *str;
        }
        return std::string();
    };

    for (const auto& instr : ir) {
        auto new_instr = instr;

        if (ir::IsVReg(instr.result)) {
            new_instr.result = reg_map.at(instr.result);
        }

        if (std::holds_alternative<std::string>(new_instr.arg1)) {
            new_instr.arg1 = handle_arg(new_instr.arg1);
        }
        if (std::holds_alternative<std::string>(new_instr.arg2)) {
            new_instr.arg2 = handle_arg(new_instr.arg2);
        }

        new_ir.push_back(new_instr);

        if (ir::IsVReg(instr.result)) {
            auto it = spill_slot.find(instr.result);
            if (it != spill_slot.end()) {
                int slot = it->second;
                const auto& phys_reg = reg_map.at(instr.result);
                new_ir.push_back({ir::IRInstruction::Op::STORE,
                                  std::to_string(slot), phys_reg});
            }
        }
    }

    return new_ir;
}

}  // namespace

IR AllocateRegistersLinearScan(const ir::IR& ir) {
    auto intervals = ComputeLiveIntervals(ir);

    std::set<int> free_regs;
    for (int i = 0; i < std::ssize(kPhysRegs); ++i) {
        free_regs.insert(i);
    }

    std::unordered_map<std::string, std::string> reg_map;
    std::unordered_map<std::string, int> spill_slot;
    AllocateIntervals(intervals, free_regs, reg_map, spill_slot);
    return RewriteIR(ir, reg_map, spill_slot);
}

}  // namespace vt::back
