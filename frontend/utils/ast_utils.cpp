#include "ast_utils.h"

namespace vt::ast {

namespace {

void PrintIndent(int indent, std::ostream& out) {
    for (int i = 0; i < indent; ++i) {
        out << "  ";
    }
}

void PrintAST(const std::shared_ptr<ASTNode>& node, int indent,
              std::ostream& out) {
    if (node == nullptr) {
        return;
    }

    PrintIndent(indent, out);

    if (auto var_decl = std::dynamic_pointer_cast<VarDeclNode>(node)) {
        out << "VarDecl: " << var_decl->type_name << " " << var_decl->var_name
            << "\n";
        PrintAST(var_decl->init_expr, indent + 1, out);

    } else if (auto var_ref = std::dynamic_pointer_cast<VarRefNode>(node)) {
        out << "VarRef: " << var_ref->var_name << "\n";

    } else if (auto assign = std::dynamic_pointer_cast<AssignmentNode>(node)) {
        out << "Assignment: " << assign->var_name << "\n";
        PrintAST(assign->expr, indent + 1, out);

    } else if (auto prints_stmt = std::dynamic_pointer_cast<PrintsNode>(node)) {
        out << "Prints:\n";
        PrintAST(prints_stmt->expr, indent + 1, out);

    } else if (auto printi_stmt = std::dynamic_pointer_cast<PrintiNode>(node)) {
        out << "Printi:\n";
        PrintAST(printi_stmt->expr, indent + 1, out);

    } else if (auto if_node = std::dynamic_pointer_cast<IfNode>(node)) {
        out << "If:\n";
        PrintIndent(indent + 1, out);
        out << "Condition:\n";
        PrintAST(if_node->condition, indent + 2, out);
        PrintIndent(indent + 1, out);
        out << "Then:\n";
        PrintAST(if_node->then_block, indent + 2, out);
        if (if_node->else_block) {
            PrintIndent(indent + 1, out);
            out << "Else:\n";
            PrintAST(if_node->else_block, indent + 2, out);
        }

    } else if (auto while_node = std::dynamic_pointer_cast<WhileNode>(node)) {
        out << "While:\n";
        PrintIndent(indent + 1, out);
        out << "Condition:\n";
        PrintAST(while_node->condition, indent + 2, out);
        PrintIndent(indent + 1, out);
        out << "Body:\n";
        PrintAST(while_node->body, indent + 2, out);

    } else if (auto block = std::dynamic_pointer_cast<BlockNode>(node)) {
        out << "Block:\n";
        for (const auto& stmt : block->statements) {
            PrintAST(stmt, indent + 1, out);
        }

    } else if (auto bin_op = std::dynamic_pointer_cast<BinaryOpNode>(node)) {
        out << "BinaryOp: " << bin_op->op << "\n";
        PrintAST(bin_op->left, indent + 1, out);
        PrintAST(bin_op->right, indent + 1, out);

    } else if (auto un_op = std::dynamic_pointer_cast<UnaryOpNode>(node)) {
        out << "UnaryOp: " << un_op->op << "\n";
        PrintAST(un_op->operand, indent + 1, out);

    } else if (auto int_lit = std::dynamic_pointer_cast<IntLiteralNode>(node)) {
        out << "IntLiteral: " << int_lit->value << "\n";

    } else if (auto str_lit =
                   std::dynamic_pointer_cast<StringLiteralNode>(node)) {
        out << "StringLiteral: " << str_lit->value << "\n";

    } else {
        out << "Unknown AST node\n";
    }
}

}  // namespace

void PrintAST(const std::shared_ptr<ASTNode>& node) {
    PrintAST(node, 0, std::cout);
}

void PrintAST(const std::shared_ptr<ASTNode>& node, std::ostream& out) {
    PrintAST(node, 0, out);
}

}  // namespace vt::ast
