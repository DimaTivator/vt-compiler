#pragma once

#include "ast.h"
#include "symbol_table.h"

namespace vt::sem {

void ReportError(antlr4::Token* token, const std::string& msg);

class SemanticAnalyzer {
public:
    SemanticAnalyzer();

    void Analyze(const std::shared_ptr<ast::ASTNode>& root);

private:
    std::shared_ptr<Scope> current_scope_;
    std::unordered_map<ast::ASTNode*, Type> node_type_map_;

    void AnalyzeBlock(const std::shared_ptr<ast::BlockNode>& block);

    void AnalyzeVarDecl(const std::shared_ptr<ast::VarDeclNode>& node);
    void AnalyzeAssignment(const std::shared_ptr<ast::AssignmentNode>& node);
    void AnalyzeIf(const std::shared_ptr<ast::IfNode>& node);
    void AnalyzeWhile(const std::shared_ptr<ast::WhileNode>& node);

    void AnalyzeStatement(const std::shared_ptr<ast::ASTNode>& statement);

    Type AnalyzeBinOp(const std::shared_ptr<ast::BinaryOpNode>& node);
    Type AnalyzeUnaryOp(const std::shared_ptr<ast::UnaryOpNode>& node);
    Type AnalyzeValRefOp(const std::shared_ptr<ast::VarRefNode>& node);

    Type AnalyzeExpression(const std::shared_ptr<ast::ASTNode>& expr);

    void EnterScope();
    void ExitScope();
};

}  // namespace vt::sem
