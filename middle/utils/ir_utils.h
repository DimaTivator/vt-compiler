#pragma once

#include <iostream>

#include "../ir.h"

namespace vt::ir {

IR RemoveVariableNames(const IR& ir);

void SetStringOperations(IR& ir);

void PrettyPrintIR(const IR& ir, std::ostream& out = std::cout);

void PrintIR(const IR& ir, std::ostream& out = std::cout);

}  // namespace vt::ir
