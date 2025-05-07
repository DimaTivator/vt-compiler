#pragma once

#include "ast.h"
#include "symbol_table.h"

namespace vt::sem {

class SemanticAnalyzer : public VtVisitor {
public:
    SemanticAnalyzer() : current_scope_(std::make_shared<Scope>(nullptr)) {}

    std::any visitProgram(VtParser::ProgramContext* context) override;

    std::any visitStatement(VtParser::StatementContext* context) override;

    std::any visitVarDecl(VtParser::VarDeclContext* context) override;

    std::any visitType(VtParser::TypeContext* context) override;

    std::any visitAssignment(VtParser::AssignmentContext* context) override;

    std::any visitPrintStmt(VtParser::PrintStmtContext* context) override;

    std::any visitIfStmt(VtParser::IfStmtContext* context) override;

    std::any visitWhileStmt(VtParser::WhileStmtContext* context) override;

    std::any visitBlock(VtParser::BlockContext* context) override;

    std::any visitAndExpr(VtParser::AndExprContext* context) override;

    std::any visitOrExpr(VtParser::OrExprContext* context) override;

    std::any visitIntLiteral(VtParser::IntLiteralContext* context) override;

    std::any visitStringLiteral(
        VtParser::StringLiteralContext* context) override;

    std::any visitIdExpr(VtParser::IdExprContext* context) override;

    std::any visitMulDiv(VtParser::MulDivContext* context) override;

    std::any visitAddSub(VtParser::AddSubContext* context) override;

    std::any visitComparison(VtParser::ComparisonContext* context) override;

    std::any visitNegExpr(VtParser::NegExprContext* context) override;

    std::any visitNotExpr(VtParser::NotExprContext* context) override;

    std::any visitParensExpr(VtParser::ParensExprContext* context) override;

private:
    std::shared_ptr<Scope> current_scope_;
    std::unordered_map<ast::ASTNode*, Type> node_type_map_;

    void EnterScope() {
        current_scope_ = std::make_shared<Scope>(current_scope_);
    }

    void ExitScope() { current_scope_ = current_scope_->Parent(); }
};

}  // namespace vt::sem
