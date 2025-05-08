#pragma once

#include <iostream>

#include "../ir.h"

namespace vt::ir {

void PrettyPrintIR(const IR& ir, std::ostream& out = std::cout);

void PrintIR(const IR& ir, std::ostream& out = std::cout);

}  // namespace vt::ir
