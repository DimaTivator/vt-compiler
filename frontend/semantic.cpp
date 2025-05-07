#include "semantic.h"

namespace vt::sem {

namespace {
void ReportError(antlr4::Token* token, const std::string& msg) {
    size_t line = token->getLine();
    size_t column = token->getCharPositionInLine();
    std::cerr << "Semantic error at " << line << ":" << column << " — " << msg
              << "\n";
}
}  // namespace

std::any SemanticAnalyzer::visitProgram(VtParser::ProgramContext* context) {
    std::vector<std::shared_ptr<ast::ASTNode>> statements;
    for (auto* statement_context : context->statement()) {
        statements.push_back(std::any_cast<std::shared_ptr<ast::ASTNode>>(
            visit(statement_context)));
    }
    return ast::MakeNode<ast::BlockNode>(std::move(statements));
}

std::any SemanticAnalyzer::visitStatement(VtParser::StatementContext* context) {
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
    return std::shared_ptr<ast::ASTNode>(nullptr);
}

std::any SemanticAnalyzer::visitVarDecl(VtParser::VarDeclContext* context) {
    std::string type_name = context->type()->getText();
    std::string var_name = context->ID()->getText();

    Type decl_type = ParseType(type_name);

    if (!current_scope_->Declare(var_name, Symbol{decl_type})) {
        ReportError(context->start, "Variable '" + var_name +
                                        "' already declared in this scope.");
    }

    auto init_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));

    Type init_type = node_type_map_[init_node.get()];
    if (init_type != decl_type) {
        ReportError(context->expr()->start,
                    "Cannot initialize variable '" + var_name + "' of type " +
                        type_name + " with expression of type " +
                        TypeToString(init_type) + ".");
    }

    return ast::MakeNode<ast::VarDeclNode>(type_name, var_name, init_node);
}

std::any SemanticAnalyzer::visitType(VtParser::TypeContext* context) {
    return std::shared_ptr<ast::ASTNode>(nullptr);
}

std::any SemanticAnalyzer::visitAssignment(
    VtParser::AssignmentContext* context) {
    std::string var_name = context->ID()->getText();
    auto* symbol = current_scope_->Lookup(var_name);
    if (symbol == nullptr) {
        ReportError(context->start, "Undeclared variable '" + var_name + "'.");
        symbol = new Symbol{Type::UNKNOWN};
    }

    auto expr_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));

    Type expr_type = node_type_map_[expr_node.get()];
    if (expr_type != symbol->type) {
        ReportError(context->expr()->start,
                    "Type mismatch in assignment to '" + var_name +
                        "': expected " + TypeToString(symbol->type) + ", got " +
                        TypeToString(expr_type) + ".");
    }

    return ast::MakeNode<ast::AssignmentNode>(var_name, expr_node);
}

std::any SemanticAnalyzer::visitPrintStmt(VtParser::PrintStmtContext* context) {
    auto this_expr =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));

    auto node = ast::MakeNode<ast::PrintNode>(this_expr);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::UNKNOWN;

    return node;
}

std::any SemanticAnalyzer::visitIfStmt(VtParser::IfStmtContext* context) {
    auto cond =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));

    if (node_type_map_[cond.get()] != Type::INT) {
        ReportError(
            context->expr()->start,
            "If condition must be of type int (0 - false, !=0 - true).");
    }

    EnterScope();
    auto cond_then =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->block(0)));
    ExitScope();

    std::shared_ptr<ast::ASTNode> cond_else = nullptr;
    if (context->block().size() > 1) {
        EnterScope();
        cond_else = std::any_cast<std::shared_ptr<ast::ASTNode>>(
            visit(context->block(1)));
        ExitScope();
    }

    return ast::MakeNode<ast::IfNode>(cond, cond_then, cond_else);
}

std::any SemanticAnalyzer::visitWhileStmt(VtParser::WhileStmtContext* context) {
    auto cond =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));
    if (node_type_map_[cond.get()] != Type::INT) {
        ReportError(context->expr()->start,
                    "While condition must be of type int.");
    }

    EnterScope();
    auto body =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->block()));
    ExitScope();

    return ast::MakeNode<ast::WhileNode>(cond, body);
}

std::any SemanticAnalyzer::visitBlock(VtParser::BlockContext* context) {
    EnterScope();
    std::vector<std::shared_ptr<ast::ASTNode>> statements;
    for (auto* statement_context : context->statement()) {
        statements.push_back(std::any_cast<std::shared_ptr<ast::ASTNode>>(
            visit(statement_context)));
    }
    ExitScope();
    return ast::MakeNode<ast::BlockNode>(statements);
}

std::any SemanticAnalyzer::visitAndExpr(VtParser::AndExprContext* context) {
    auto left_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(0)));
    auto right_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(1)));

    if (node_type_map_[left_node.get()] != Type::INT ||
        node_type_map_[right_node.get()] != Type::INT) {
        ReportError(context->start, "Logical 'and' requires integer operands.");
    }

    auto node = ast::MakeNode<ast::BinaryOpNode>("and", left_node, right_node);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitOrExpr(VtParser::OrExprContext* context) {
    auto left_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(0)));
    auto right_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(1)));

    if (node_type_map_[left_node.get()] != Type::INT ||
        node_type_map_[right_node.get()] != Type::INT) {
        ReportError(context->start, "Logical 'or' requires integer operands.");
    }

    auto node = ast::MakeNode<ast::BinaryOpNode>("or", left_node, right_node);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitIntLiteral(
    VtParser::IntLiteralContext* context) {
    int value = std::stoi(context->getText());
    auto node = ast::MakeNode<ast::IntLiteralNode>(value);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitStringLiteral(
    VtParser::StringLiteralContext* context) {
    std::string text = context->getText();
    text = text.substr(1, text.size() - 2);  // strip the quotes
    auto node = ast::MakeNode<ast::StringLiteralNode>(text);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::STRING;

    return node;
}

std::any SemanticAnalyzer::visitIdExpr(VtParser::IdExprContext* context) {
    std::string name = context->ID()->getText();
    auto* symbol = current_scope_->Lookup(name);
    if (symbol == nullptr) {
        ReportError(context->start,
                    "Use of undeclared variable '" + name + "'.");
        symbol = new Symbol{Type::UNKNOWN};
    }
    auto node = ast::MakeNode<ast::VarRefNode>(name);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        symbol->type;

    return node;
}

std::any SemanticAnalyzer::visitMulDiv(VtParser::MulDivContext* context) {
    auto left_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(0)));
    auto right_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(1)));

    if (node_type_map_[left_node.get()] != Type::INT ||
        node_type_map_[right_node.get()] != Type::INT) {
        ReportError(context->start,
                    "Operator '*' and '/' require integer operands.");
    }
    std::string op = (context->STAR() != nullptr) ? "*" : "/";
    auto node = ast::MakeNode<ast::BinaryOpNode>(op, left_node, right_node);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitAddSub(VtParser::AddSubContext* context) {
    auto left_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(0)));
    auto right_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(1)));

    Type left_type = node_type_map_[left_node.get()];
    Type right_type = node_type_map_[right_node.get()];

    bool is_plus = (context->PLUS() != nullptr);
    Type result_type;
    if (left_type == Type::INT && right_type == Type::INT) {
        result_type = Type::INT;
    } else if (left_type == Type::STRING && right_type == Type::STRING &&
               is_plus) {
        result_type = Type::STRING;
    } else {
        std::string op_text = is_plus ? "+" : "-";
        ReportError(context->start, "Operator '" + op_text +
                                        "' not defined for operand types '" +
                                        TypeToString(left_type) + "' and '" +
                                        TypeToString(right_type) + "'.");
        result_type = Type::UNKNOWN;
    }

    auto node = ast::MakeNode<ast::BinaryOpNode>((is_plus ? "+" : "-"),
                                                 left_node, right_node);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        result_type;

    return node;
}

std::any SemanticAnalyzer::visitComparison(
    VtParser::ComparisonContext* context) {
    auto left_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(0)));
    auto right_node =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr(1)));

    Type left_type = node_type_map_[left_node.get()];
    Type right_type = node_type_map_[right_node.get()];
    std::string op;

    if (context->LT() != nullptr) {
        op = "<";
    }
    if (context->GT() != nullptr) {
        op = ">";
    }
    if (context->LE() != nullptr) {
        op = "<=";
    }
    if (context->GE() != nullptr) {
        op = ">=";
    }
    if (context->EQEQ() != nullptr) {
        op = "==";
    }
    if (context->NEQ() != nullptr) {
        op = "!=";
    }

    if (left_type != right_type) {
        ReportError(context->start, "Operator '" + op +
                                        "' not valid for types '" +
                                        TypeToString(left_type) + "' and '" +
                                        TypeToString(right_type) + "'.");
    }
    auto node = ast::MakeNode<ast::BinaryOpNode>(op, left_node, right_node);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitNegExpr(VtParser::NegExprContext* context) {
    auto operand =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));
    if (node_type_map_[operand.get()] != Type::INT) {
        ReportError(context->start, "Unary '-' requires an integer operand.");
    }
    auto node = ast::MakeNode<ast::UnaryOpNode>("-", operand);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitNotExpr(VtParser::NotExprContext* context) {
    auto operand =
        std::any_cast<std::shared_ptr<ast::ASTNode>>(visit(context->expr()));
    if (node_type_map_[operand.get()] != Type::INT) {
        ReportError(context->start,
                    "Logical 'not' requires an integer operand.");
    }
    auto node = ast::MakeNode<ast::UnaryOpNode>("not", operand);
    node_type_map_[std::any_cast<std::shared_ptr<ast::ASTNode>>(node).get()] =
        Type::INT;

    return node;
}

std::any SemanticAnalyzer::visitParensExpr(
    VtParser::ParensExprContext* context) {
    return visit(context->expr());
}

}  // namespace vt::sem
