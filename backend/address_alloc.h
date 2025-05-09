#pragma once

#include "../middle/ir.h"

namespace vt::back {

using Op = ir::IRInstruction::Op;

const int kSpillSectionStart = 0xA000;
const int kStringsSectionStart = 0xC000;
const int kStringLength = 256;  // including \0
const std::string kSpillAddrReg = "x31";

void AllocateStrings(ir::IR& ir);

ir::IR AllocateSpillSlots(const ir::IR& ir);

}  // namespace vt::back
