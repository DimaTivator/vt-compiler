#pragma once

#include "../middle/ir.h"

namespace vt::back {

using IR = ir::IR;

// Reserve
// x31 -- section data address
static const std::vector<std::string> kPhysRegs = {
    "x1",  "x2",  "x3",  "x4",  "x5",  "x6",  "x7",  "x8",  "x9",  "x10", "x11",
    "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22",
    "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30"};

IR AllocateRegistersLinearScan(const ir::IR& ir);

}  // namespace vt::back
