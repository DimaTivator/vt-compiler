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
    explicit ASTNode(antlr4::Token* token) : token_(token) {}
    virtual ~ASTNode() = default;

    [[nodiscard]] antlr4::Token* GetToken() const { return token_; }

private:
    antlr4::Token* token_;
};

template <typename Derived, typename... Args>
std::any MakeNode(Args&&... args) {
    auto derived = std::make_shared<Derived>(std::forward<Args>(args)...);
    std::shared_ptr<ASTNode> base = derived;
    return base;
}

class VarDeclNode : public ASTNode {
public:
    VarDeclNode(antlr4::Token* token, std::string type_name,
                std::string var_name, std::shared_ptr<ASTNode> init_expr)
        : ASTNode(token),
          type_name(std::move(type_name)),
          var_name(std::move(var_name)),
          init_expr(std::move(init_expr)) {}

    std::string type_name;
    std::string var_name;
    std::shared_ptr<ASTNode> init_expr;
};

class VarRefNode : public ASTNode {
public:
    VarRefNode(antlr4::Token* token, std::string var_name)
        : ASTNode(token), var_name(std::move(var_name)) {}

    std::string var_name;
};

class AssignmentNode : public ASTNode {
public:
    AssignmentNode(antlr4::Token* token, std::string var_name,
                   std::shared_ptr<ASTNode> expr)
        : ASTNode(token),
          var_name(std::move(var_name)),
          expr(std::move(expr)) {}

    std::string var_name;
    std::shared_ptr<ASTNode> expr;
};

class PrintNode : public ASTNode {
public:
    PrintNode(antlr4::Token* token, std::shared_ptr<ASTNode> expr)
        : ASTNode(token), expr(std::move(expr)) {}

    std::shared_ptr<ASTNode> expr;
};

class IfNode : public ASTNode {
public:
    IfNode(antlr4::Token* token, std::shared_ptr<ASTNode> condition,
           std::shared_ptr<ASTNode> then_block,
           std::shared_ptr<ASTNode> else_block)
        : ASTNode(token),
          condition(std::move(condition)),
          then_block(std::move(then_block)),
          else_block(std::move(else_block)) {}

    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> then_block;
    std::shared_ptr<ASTNode> else_block;
};

class WhileNode : public ASTNode {
public:
    WhileNode(antlr4::Token* token, std::shared_ptr<ASTNode> condition,
              std::shared_ptr<ASTNode> body)
        : ASTNode(token),
          condition(std::move(condition)),
          body(std::move(body)) {}

    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> body;
};

class BlockNode : public ASTNode {
public:
    BlockNode(antlr4::Token* token,
              std::vector<std::shared_ptr<ASTNode>> statements)
        : ASTNode(token), statements(std::move(statements)) {}

    std::vector<std::shared_ptr<ASTNode>> statements;
};

class BinaryOpNode : public ASTNode {
public:
    BinaryOpNode(antlr4::Token* token, std::string op,
                 std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right)
        : ASTNode(token),
          op(std::move(op)),
          left(std::move(left)),
          right(std::move(right)) {}

    std::string op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
};

class UnaryOpNode : public ASTNode {
public:
    UnaryOpNode(antlr4::Token* token, std::string op,
                std::shared_ptr<ASTNode> operand)
        : ASTNode(token), op(std::move(op)), operand(std::move(operand)) {}

    std::string op;
    std::shared_ptr<ASTNode> operand;
};

class IntLiteralNode : public ASTNode {
public:
    IntLiteralNode(antlr4::Token* token, int value)
        : ASTNode(token), value(value) {}

    int value;
};

class StringLiteralNode : public ASTNode {
public:
    StringLiteralNode(antlr4::Token* token, std::string value)
        : ASTNode(token), value(std::move(value)) {}

    std::string value;
};

}  // namespace vt::ast