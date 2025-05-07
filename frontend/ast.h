#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "VtParser.h"
#include "VtVisitor.h"

namespace vt::ast {

class ASTNode {
public:
    virtual ~ASTNode() = default;
};

class VarDeclNode : public ASTNode {
public:
    std::string type_name;
    std::string var_name;
    std::shared_ptr<ASTNode> init_expr;

    VarDeclNode(std::string type_name, std::string var_name,
                std::shared_ptr<ASTNode> expr)
        : type_name(std::move(type_name)),
          var_name(std::move(var_name)),
          init_expr(std::move(expr)) {}
};

class VarRefNode : public ASTNode {
public:
    std::string var_name;

    explicit VarRefNode(std::string var_name) : var_name(std::move(var_name)) {}
};

class AssignmentNode : public ASTNode {
public:
    std::string var_name;
    std::shared_ptr<ASTNode> expr;

    AssignmentNode(std::string var_name, std::shared_ptr<ASTNode> expr)
        : var_name(std::move(var_name)), expr(std::move(expr)) {}
};

class PrintNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> expr;

    explicit PrintNode(std::shared_ptr<ASTNode> expr) : expr(std::move(expr)) {}
};

class IfNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> then_block;
    std::shared_ptr<ASTNode> else_block;

    IfNode(std::shared_ptr<ASTNode> condition,
           std::shared_ptr<ASTNode> then_block,
           std::shared_ptr<ASTNode> else_block)
        : condition(std::move(condition)),
          then_block(std::move(then_block)),
          else_block(std::move(else_block)) {}
};

class WhileNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> body;

    WhileNode(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> body)
        : condition(std::move(condition)), body(std::move(body)) {}
};

class BlockNode : public ASTNode {
public:
    std::vector<std::shared_ptr<ASTNode>> statements;

    explicit BlockNode(std::vector<std::shared_ptr<ASTNode>> statements)
        : statements(std::move(statements)) {}
};

class BinaryOpNode : public ASTNode {
public:
    std::string op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;

    BinaryOpNode(std::string op, std::shared_ptr<ASTNode> left,
                 std::shared_ptr<ASTNode> right)
        : op(std::move(op)), left(std::move(left)), right(std::move(right)) {}
};

class UnaryOpNode : public ASTNode {
public:
    std::string op;
    std::shared_ptr<ASTNode> operand;

    UnaryOpNode(std::string op, std::shared_ptr<ASTNode> operand)
        : op(std::move(op)), operand(std::move(operand)) {}
};

class IntLiteralNode : public ASTNode {
public:
    int value;

    explicit IntLiteralNode(int value) : value(value) {}
};

class StringLiteralNode : public ASTNode {
public:
    std::string value;

    explicit StringLiteralNode(std::string value) : value(std::move(value)) {}
};

class ASTBuilder : public VtVisitor {
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

    std::any visitStringLiteral(
        VtParser::StringLiteralContext* context) override;

    std::any visitIdExpr(VtParser::IdExprContext* context) override;

    std::any visitMulDiv(VtParser::MulDivContext* context) override;

    std::any visitAddSub(VtParser::AddSubContext* context) override;

    std::any visitComparison(VtParser::ComparisonContext* context) override;

    std::any visitNegExpr(VtParser::NegExprContext* context) override;

    std::any visitParensExpr(VtParser::ParensExprContext* context) override;

    std::any visitIntLiteral(VtParser::IntLiteralContext* context) override;

    std::any visitNotExpr(VtParser::NotExprContext* context) override;

    std::any visitOrExpr(VtParser::OrExprContext* context) override;
};

}  // namespace vt::ast
