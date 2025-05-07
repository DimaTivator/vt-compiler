#pragma once

#include "../ast.h"

namespace vt::ast {

void PrintAST(const std::shared_ptr<ASTNode>& node);

}  // namespace vt::ast