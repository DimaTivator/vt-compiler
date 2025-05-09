#pragma once

#include "../asm_generation.h"

namespace vt::back {

void PrintASM(const Asm& asm_code, std::ostream& os);

}  // namespace vt::back
