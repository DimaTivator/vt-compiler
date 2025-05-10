#include "ast_utils.h"

namespace vt::ast {

namespace {

void PrintIndent(int indent) {
    for (int i = 0; i < indent; ++i) {
        std::cout << "  ";
    }
}

void PrintAST(const std::shared_ptr<ASTNode>& node, int indent) {
    if (node == nullptr) {
        return;
    }

    PrintIndent(indent);

    if (auto var_decl = std::dynamic_pointer_cast<VarDeclNode>(node)) {
        std::cout << "VarDecl: " << var_decl->type_name << " "
                  << var_decl->var_name << "\n";
        PrintAST(var_decl->init_expr, indent + 1);

    } else if (auto var_ref = std::dynamic_pointer_cast<VarRefNode>(node)) {
        std::cout << "VarRef: " << var_ref->var_name << "\n";

    } else if (auto assign = std::dynamic_pointer_cast<AssignmentNode>(node)) {
        std::cout << "Assignment: " << assign->var_name << "\n";
        PrintAST(assign->expr, indent + 1);

    } else if (auto prints_stmt = std::dynamic_pointer_cast<PrintsNode>(node)) {
        std::cout << "Prints:\n";
        PrintAST(prints_stmt->expr, indent + 1);

    } else if (auto printi_stmt = std::dynamic_pointer_cast<PrintiNode>(node)) {
        std::cout << "Printi:\n";
        PrintAST(printi_stmt->expr, indent + 1);

    } else if (auto if_node = std::dynamic_pointer_cast<IfNode>(node)) {
        std::cout << "If:\n";
        PrintIndent(indent + 1);
        std::cout << "Condition:\n";
        PrintAST(if_node->condition, indent + 2);
        PrintIndent(indent + 1);
        std::cout << "Then:\n";
        PrintAST(if_node->then_block, indent + 2);
        if (if_node->else_block) {
            PrintIndent(indent + 1);
            std::cout << "Else:\n";
            PrintAST(if_node->else_block, indent + 2);
        }

    } else if (auto while_node = std::dynamic_pointer_cast<WhileNode>(node)) {
        std::cout << "While:\n";
        PrintIndent(indent + 1);
        std::cout << "Condition:\n";
        PrintAST(while_node->condition, indent + 2);
        PrintIndent(indent + 1);
        std::cout << "Body:\n";
        PrintAST(while_node->body, indent + 2);

    } else if (auto block = std::dynamic_pointer_cast<BlockNode>(node)) {
        std::cout << "Block:\n";
        for (const auto& stmt : block->statements) {
            PrintAST(stmt, indent + 1);
        }

    } else if (auto bin_op = std::dynamic_pointer_cast<BinaryOpNode>(node)) {
        std::cout << "BinaryOp: " << bin_op->op << "\n";
        PrintAST(bin_op->left, indent + 1);
        PrintAST(bin_op->right, indent + 1);

    } else if (auto un_op = std::dynamic_pointer_cast<UnaryOpNode>(node)) {
        std::cout << "UnaryOp: " << un_op->op << "\n";
        PrintAST(un_op->operand, indent + 1);

    } else if (auto int_lit = std::dynamic_pointer_cast<IntLiteralNode>(node)) {
        std::cout << "IntLiteral: " << int_lit->value << "\n";

    } else if (auto str_lit =
                   std::dynamic_pointer_cast<StringLiteralNode>(node)) {
        std::cout << "StringLiteral: " << str_lit->value << "\n";

    } else {
        std::cout << "Unknown AST node\n";
    }
}

}  // namespace

void PrintAST(const std::shared_ptr<ASTNode>& node) { PrintAST(node, 0); }

}  // namespace vt::ast
