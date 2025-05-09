#pragma once

#include "../middle/ir.h"

namespace vt::back {

using Op = ir::IRInstruction::Op;

const int kStringsSectionStart = 0xC000;
const int kStringLength = 256;  // including \0

void AllocateStrings(ir::IR& ir);

}  // namespace vt::back
