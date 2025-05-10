#include "semantic.h"

#include <iostream>

namespace vt::sem {

void ReportError(antlr4::Token* token, const std::string& msg) {
    size_t line = token->getLine();
    size_t column = token->getCharPositionInLine();
    std::cerr << "Semantic error at " << line << ":" << column << " — " << msg
              << "\n";
}

SemanticAnalyzer::SemanticAnalyzer()
    : current_scope_(std::make_shared<Scope>(nullptr)) {}

void SemanticAnalyzer::Analyze(const std::shared_ptr<ast::ASTNode>& root) {
    auto block = std::dynamic_pointer_cast<ast::BlockNode>(root);
    if (block) {
        AnalyzeBlock(block);
    }
}

void SemanticAnalyzer::AnalyzeBlock(
    const std::shared_ptr<ast::BlockNode>& block) {
    EnterScope();
    for (auto& statement : block->statements) {
        AnalyzeStatement(statement);
    }
    ExitScope();
}

void SemanticAnalyzer::AnalyzeVarDecl(
    const std::shared_ptr<ast::VarDeclNode>& node) {
    //
    Type decl_type = ParseType(node->type_name);
    if (!current_scope_->Declare(node->var_name, Symbol{decl_type})) {
        ReportError(node->GetToken(), "Variable '" + node->var_name +
                                          "' already declared in this scope.");
    }
    Type init_t = AnalyzeExpression(node->init_expr);
    if (init_t != decl_type) {
        ReportError(node->GetToken(), "Cannot initialize variable '" +
                                          node->var_name + "' of type " +
                                          node->type_name +
                                          " with expression of type " +
                                          TypeToString(init_t) + ".");
    }
}

void SemanticAnalyzer::AnalyzeAssignment(
    const std::shared_ptr<ast::AssignmentNode>& node) {
    //
    auto* symbol = current_scope_->Lookup(node->var_name);
    if (symbol == nullptr) {
        ReportError(node->GetToken(),
                    "Undeclared variable '" + node->var_name + "'.");
        symbol = new Symbol{Type::UNKNOWN};
    }
    Type rhs_t = AnalyzeExpression(node->expr);
    if (rhs_t != symbol->type) {
        ReportError(node->GetToken(), "Type mismatch in assignment to '" +
                                          node->var_name + "': expected " +
                                          TypeToString(symbol->type) +
                                          ", got " + TypeToString(rhs_t) + ".");
    }
}

void SemanticAnalyzer::AnalyzeIf(const std::shared_ptr<ast::IfNode>& node) {
    Type cond = AnalyzeExpression(node->condition);
    if (cond != Type::INT) {
        ReportError(node->GetToken(), "If condition must be of type int.");
    }
    AnalyzeBlock(std::dynamic_pointer_cast<ast::BlockNode>(node->then_block));
    if (node->else_block) {
        AnalyzeBlock(
            std::dynamic_pointer_cast<ast::BlockNode>(node->else_block));
    }
}

void SemanticAnalyzer::AnalyzeWhile(
    const std::shared_ptr<ast::WhileNode>& node) {
    //
    Type cond = AnalyzeExpression(node->condition);
    if (cond != Type::INT) {
        ReportError(node->GetToken(), "While condition must be of type int.");
    }
    AnalyzeBlock(std::dynamic_pointer_cast<ast::BlockNode>(node->body));
}

void SemanticAnalyzer::AnalyzeStatement(
    const std::shared_ptr<ast::ASTNode>& statement) {
    //
    if (auto decl_n = std::dynamic_pointer_cast<ast::VarDeclNode>(statement)) {
        AnalyzeVarDecl(decl_n);

    } else if (auto assign_n =
                   std::dynamic_pointer_cast<ast::AssignmentNode>(statement)) {
        AnalyzeAssignment(assign_n);

    } else if (auto prints_n =
                   std::dynamic_pointer_cast<ast::PrintsNode>(statement)) {
        Type type = AnalyzeExpression(prints_n->expr);
        if (type != Type::STRING) {
            ReportError(prints_n->GetToken(),
                        "Prints statement requires a string expression.");
        }

    } else if (auto printi_n =
                   std::dynamic_pointer_cast<ast::PrintiNode>(statement)) {
        Type type = AnalyzeExpression(printi_n->expr);
        if (type != Type::INT) {
            ReportError(printi_n->GetToken(),
                        "Printi statement requires integer expression.");
        }

    } else if (auto if_n = std::dynamic_pointer_cast<ast::IfNode>(statement)) {
        AnalyzeIf(if_n);

    } else if (auto while_n =
                   std::dynamic_pointer_cast<ast::WhileNode>(statement)) {
        AnalyzeWhile(while_n);

    } else if (auto blk =
                   std::dynamic_pointer_cast<ast::BlockNode>(statement)) {
        AnalyzeBlock(blk);
    }
}

Type SemanticAnalyzer::AnalyzeBinOp(
    const std::shared_ptr<ast::BinaryOpNode>& node) {
    //
    Type left_t = AnalyzeExpression(node->left);
    Type right_t = AnalyzeExpression(node->right);
    const std::string& op = node->op;
    if (op == "+" || op == "-") {
        if (left_t == Type::INT && right_t == Type::INT) {
            return Type::INT;
        }
        if (op == "+" && left_t == Type::STRING && right_t == Type::STRING) {
            return Type::STRING;
        }
        ReportError(node->GetToken(), "Operator '" + op +
                                          "' not defined for operand types '" +
                                          TypeToString(left_t) + "' and '" +
                                          TypeToString(right_t) + "'.");
        return Type::UNKNOWN;
    }
    if (op == "*" || op == "/") {
        if (left_t == Type::INT && right_t == Type::INT) {
            return Type::INT;
        }
        ReportError(node->GetToken(),
                    "Operator '" + op + "' requires integer operands.");
        return Type::UNKNOWN;
    }
    if (op == "and" || op == "or") {
        if (left_t == Type::INT && right_t == Type::INT) {
            return Type::INT;
        }
        ReportError(node->GetToken(),
                    "Logical '" + op + "' requires integer operands.");
        return Type::UNKNOWN;
    }
    // comparison
    if (left_t != right_t) {
        ReportError(node->GetToken(), "Operator '" + op +
                                          "' not valid for types '" +
                                          TypeToString(left_t) + "' and '" +
                                          TypeToString(right_t) + "'.");
    }
    return Type::INT;
}

Type SemanticAnalyzer::AnalyzeUnaryOp(
    const std::shared_ptr<ast::UnaryOpNode>& node) {
    //
    Type operand_t = AnalyzeExpression(node->operand);
    const std::string& op = node->op;
    if (op == "-" && operand_t != Type::INT) {
        ReportError(node->GetToken(), "Unary '-' requires an integer operand.");
        return Type::UNKNOWN;
    }
    if (op == "not" && operand_t != Type::INT) {
        ReportError(node->GetToken(),
                    "Logical 'not' requires an integer operand.");
        return Type::UNKNOWN;
    }
    return Type::INT;
}

Type SemanticAnalyzer::AnalyzeValRefOp(
    const std::shared_ptr<ast::VarRefNode>& node) {
    //
    auto* sym = current_scope_->Lookup(node->var_name);
    if (sym == nullptr) {
        ReportError(node->GetToken(),
                    "Use of undeclared variable '" + node->var_name + "'.");
        return Type::UNKNOWN;
    }
    return sym->type;
}

Type SemanticAnalyzer::AnalyzeExpression(
    const std::shared_ptr<ast::ASTNode>& expr) {
    //
    if (auto bin_n = std::dynamic_pointer_cast<ast::BinaryOpNode>(expr)) {
        return AnalyzeBinOp(bin_n);
    }

    if (auto un_n = std::dynamic_pointer_cast<ast::UnaryOpNode>(expr)) {
        return AnalyzeUnaryOp(un_n);
    }
    if (auto int_l_n = std::dynamic_pointer_cast<ast::IntLiteralNode>(expr)) {
        return Type::INT;
    }
    if (auto string_l_n =
            std::dynamic_pointer_cast<ast::StringLiteralNode>(expr)) {
        return Type::STRING;
    }
    if (auto val_ref_n = std::dynamic_pointer_cast<ast::VarRefNode>(expr)) {
        return AnalyzeValRefOp(val_ref_n);
    }
    return Type::UNKNOWN;
}

void SemanticAnalyzer::EnterScope() {
    current_scope_ = std::make_shared<Scope>(current_scope_);
}

void SemanticAnalyzer::ExitScope() {
    current_scope_ = current_scope_->Parent();
}

}  // namespace vt::sem
