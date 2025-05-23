#pragma once

#include "../ast.h"

namespace vt::ast {

void PrintAST(const std::shared_ptr<ASTNode>& node);
void PrintAST(const std::shared_ptr<ASTNode>& node, std::ostream& out);

}  // namespace vt::ast