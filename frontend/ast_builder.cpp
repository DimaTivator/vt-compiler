#include "ast_builder.h"

namespace vt::ast {

std::any ASTBuilder::visitProgram(VtParser::ProgramContext* context) {
    std::vector<std::shared_ptr<ASTNode>> statements;
    for (auto* statement_context : context->statement()) {
        statements.push_back(
            std::any_cast<std::shared_ptr<ASTNode>>(visit(statement_context)));
    }
    return MakeNode<BlockNode>(context->start, std::move(statements));
}

std::any ASTBuilder::visitStatement(VtParser::StatementContext* context) {
    if (context->varDecl() != nullptr) {
        return visit(context->varDecl());
    }
    if (context->assignment() != nullptr) {
        return visit(context->assignment());
    }
    if (context->printStmt() != nullptr) {
        return visit(context->printStmt());
    }
    if (context->ifStmt() != nullptr) {
        return visit(context->ifStmt());
    }
    if (context->whileStmt() != nullptr) {
        return visit(context->whileStmt());
    }
    return visit(context->block());
}

std::any ASTBuilder::visitVarDecl(VtParser::VarDeclContext* context) {
    auto type = context->type()->getText();
    auto name = context->ID()->getText();
    auto init = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<VarDeclNode>(context->start, std::move(type),
                                 std::move(name), std::move(init));
}

std::any ASTBuilder::visitType(VtParser::TypeContext* /*context*/) {
    return std::shared_ptr<ASTNode>(nullptr);
}

std::any ASTBuilder::visitAssignment(VtParser::AssignmentContext* context) {
    auto name = context->ID()->getText();
    auto expr = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<AssignmentNode>(context->start, std::move(name),
                                    std::move(expr));
}

std::any ASTBuilder::visitPrintStmt(VtParser::PrintStmtContext* context) {
    auto expr = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<PrintNode>(context->start, std::move(expr));
}

std::any ASTBuilder::visitIfStmt(VtParser::IfStmtContext* context) {
    auto cond = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    auto then_block =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->block(0)));
    std::shared_ptr<ASTNode> else_block = nullptr;
    if (context->block().size() == 2) {
        else_block =
            std::any_cast<std::shared_ptr<ASTNode>>(visit(context->block(1)));
    }
    return MakeNode<IfNode>(context->start, std::move(cond),
                            std::move(then_block), std::move(else_block));
}

std::any ASTBuilder::visitWhileStmt(VtParser::WhileStmtContext* context) {
    auto cond = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    auto body =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->block()));
    return MakeNode<WhileNode>(context->start, std::move(cond),
                               std::move(body));
}

std::any ASTBuilder::visitBlock(VtParser::BlockContext* context) {
    std::vector<std::shared_ptr<ASTNode>> statements;
    for (auto* statement_context : context->statement()) {
        statements.push_back(
            std::any_cast<std::shared_ptr<ASTNode>>(visit(statement_context)));
    }
    return MakeNode<BlockNode>(context->start, std::move(statements));
}

std::any ASTBuilder::visitAndExpr(VtParser::AndExprContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>(context->start, "and", std::move(left),
                                  std::move(right));
}

std::any ASTBuilder::visitOrExpr(VtParser::OrExprContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>(context->start, "or", std::move(left),
                                  std::move(right));
}

std::any ASTBuilder::visitIntLiteral(VtParser::IntLiteralContext* context) {
    return MakeNode<IntLiteralNode>(context->start,
                                    std::stoi(context->getText()));
}

std::any ASTBuilder::visitStringLiteral(
    VtParser::StringLiteralContext* context) {
    auto txt = context->getText();
    return MakeNode<StringLiteralNode>(context->start,
                                       txt.substr(1, txt.size() - 2));
}

std::any ASTBuilder::visitIdExpr(VtParser::IdExprContext* context) {
    return MakeNode<VarRefNode>(context->start, context->getText());
}

std::any ASTBuilder::visitMulDiv(VtParser::MulDivContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>(context->start, context->op->getText(),
                                  std::move(left), std::move(right));
}

std::any ASTBuilder::visitAddSub(VtParser::AddSubContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>(context->start, context->op->getText(),
                                  std::move(left), std::move(right));
}

std::any ASTBuilder::visitComparison(VtParser::ComparisonContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>(context->start, context->op->getText(),
                                  std::move(left), std::move(right));
}

std::any ASTBuilder::visitNegExpr(VtParser::NegExprContext* context) {
    auto operand =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<UnaryOpNode>(context->start, "-", std::move(operand));
}

std::any ASTBuilder::visitNotExpr(VtParser::NotExprContext* context) {
    auto operand =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<UnaryOpNode>(context->start, "not", std::move(operand));
}

std::any ASTBuilder::visitParensExpr(VtParser::ParensExprContext* context) {
    return visit(context->expr());
}

}  // namespace vt::ast
