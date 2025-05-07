#include "ast.h"

namespace vt::ast {

template <typename Derived, typename... Args>
std::any MakeNode(Args&&... args) {
    auto derived = std::make_shared<Derived>(std::forward<Args>(args)...);
    std::shared_ptr<ASTNode> base = derived;
    return base;
}

std::any ASTBuilder::visitProgram(VtParser::ProgramContext* context) {
    std::vector<std::shared_ptr<ASTNode>> statements;
    for (auto* statement_context : context->statement()) {
        statements.push_back(
            std::any_cast<std::shared_ptr<ASTNode>>(visit(statement_context)));
    }
    return MakeNode<BlockNode>(std::move(statements));
}

std::any ASTBuilder::visitStatement(VtParser::StatementContext* context) {
    if (context->varDecl() != nullptr) {
        return visitVarDecl(context->varDecl());
    }
    if (context->assignment() != nullptr) {
        return visitAssignment(context->assignment());
    }
    if (context->printStmt() != nullptr) {
        return visitPrintStmt(context->printStmt());
    }
    if (context->ifStmt() != nullptr) {
        return visitIfStmt(context->ifStmt());
    }
    if (context->whileStmt() != nullptr) {
        return visitWhileStmt(context->whileStmt());
    }
    if (context->block() != nullptr) {
        return visitBlock(context->block());
    }
    return std::shared_ptr<ASTNode>(nullptr);
}

std::any ASTBuilder::visitVarDecl(VtParser::VarDeclContext* context) {
    std::string type_name = context->type()->getText();
    std::string var_name = context->ID()->getText();
    auto init_expr =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<VarDeclNode>(type_name, var_name, init_expr);
}

std::any ASTBuilder::visitType(VtParser::TypeContext* context) {
    return context->getText();
}

std::any ASTBuilder::visitAssignment(VtParser::AssignmentContext* context) {
    std::string var_name = context->ID()->getText();
    auto expr = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<AssignmentNode>(var_name, expr);
}

std::any ASTBuilder::visitPrintStmt(VtParser::PrintStmtContext* context) {
    auto expr = std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<PrintNode>(expr);
}

std::any ASTBuilder::visitIfStmt(VtParser::IfStmtContext* context) {
    auto condition =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    auto then_block =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->block(0)));
    std::shared_ptr<ASTNode> else_block = nullptr;
    if (context->block().size() > 1) {
        else_block =
            std::any_cast<std::shared_ptr<ASTNode>>(visit(context->block(1)));
    }
    return MakeNode<IfNode>(condition, then_block, else_block);
}

std::any ASTBuilder::visitWhileStmt(VtParser::WhileStmtContext* context) {
    auto condition =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    auto body =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->block()));
    return MakeNode<WhileNode>(condition, body);
}

std::any ASTBuilder::visitBlock(VtParser::BlockContext* context) {
    std::vector<std::shared_ptr<ASTNode>> statements;
    for (auto* statement_context : context->statement()) {
        statements.push_back(
            std::any_cast<std::shared_ptr<ASTNode>>(visit(statement_context)));
    }
    return MakeNode<BlockNode>(std::move(statements));
}

std::any ASTBuilder::visitAndExpr(VtParser::AndExprContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>("and", left, right);
}

std::any ASTBuilder::visitStringLiteral(
    VtParser::StringLiteralContext* context) {
    return MakeNode<StringLiteralNode>(context->getText());
}

std::any ASTBuilder::visitIdExpr(VtParser::IdExprContext* context) {
    return MakeNode<VarRefNode>(context->ID()->getText());
}

std::any ASTBuilder::visitMulDiv(VtParser::MulDivContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    std::string op = (context->STAR() != nullptr) ? "*" : "/";
    return MakeNode<BinaryOpNode>(op, left, right);
}

std::any ASTBuilder::visitAddSub(VtParser::AddSubContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    std::string op = (context->PLUS() != nullptr) ? "+" : "-";
    return MakeNode<BinaryOpNode>(op, left, right);
}

std::any ASTBuilder::visitComparison(VtParser::ComparisonContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    std::string op;
    if (context->LT() != nullptr) {
        op = "<";
    } else if (context->GT() != nullptr) {
        op = ">";
    } else if (context->LE() != nullptr) {
        op = "<=";
    } else if (context->GE() != nullptr) {
        op = ">=";
    } else if (context->EQEQ() != nullptr) {
        op = "==";
    } else if (context->NEQ() != nullptr) {
        op = "!=";
    }
    return MakeNode<BinaryOpNode>(op, left, right);
}

std::any ASTBuilder::visitNegExpr(VtParser::NegExprContext* context) {
    auto operand =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<UnaryOpNode>("-", operand);
}

std::any ASTBuilder::visitParensExpr(VtParser::ParensExprContext* context) {
    return visit(context->expr());
}

std::any ASTBuilder::visitIntLiteral(VtParser::IntLiteralContext* context) {
    return MakeNode<IntLiteralNode>(std::stoi(context->getText()));
}

std::any ASTBuilder::visitNotExpr(VtParser::NotExprContext* context) {
    auto operand =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr()));
    return MakeNode<UnaryOpNode>("!", operand);
}

std::any ASTBuilder::visitOrExpr(VtParser::OrExprContext* context) {
    auto left =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(0)));
    auto right =
        std::any_cast<std::shared_ptr<ASTNode>>(visit(context->expr(1)));
    return MakeNode<BinaryOpNode>("||", left, right);
}

}  // namespace vt::ast