#include <gtest/gtest.h>

#include "../VtLexer.h"
#include "../VtParser.h"
#include "../ast_builder.h"

using namespace vt::ast;
using namespace antlr4;

static std::shared_ptr<ASTNode> BuildAst(const std::string& source) {
    ANTLRInputStream input(source);
    VtLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    VtParser parser(&tokens);

    ASTBuilder builder;
    std::any any_root = builder.visit(parser.program());
    auto base_ptr = std::any_cast<std::shared_ptr<ASTNode>>(any_root);
    return base_ptr;
}

TEST(ASTBuilder, VarDeclAndLiteral) {
    auto root = std::dynamic_pointer_cast<BlockNode>(BuildAst("int x = 42;\n"));
    ASSERT_TRUE(root);
    ASSERT_EQ(root->statements.size(), 1);

    auto var_decl = std::dynamic_pointer_cast<VarDeclNode>(root->statements[0]);
    ASSERT_TRUE(var_decl);
    EXPECT_EQ(var_decl->type_name, "int");
    EXPECT_EQ(var_decl->var_name, "x");

    auto lit = std::dynamic_pointer_cast<IntLiteralNode>(var_decl->init_expr);
    ASSERT_TRUE(lit);
    EXPECT_EQ(lit->value, 42);
}

TEST(ASTBuilder, BinaryOp) {
    auto root =
        std::dynamic_pointer_cast<BlockNode>(BuildAst("print(1 + 2);\n"));
    ASSERT_TRUE(root);
    ASSERT_EQ(root->statements.size(), 1);

    auto print_node = std::dynamic_pointer_cast<PrintNode>(root->statements[0]);
    ASSERT_TRUE(print_node);

    auto binop = std::dynamic_pointer_cast<BinaryOpNode>(print_node->expr);
    ASSERT_TRUE(binop);
    EXPECT_EQ(binop->op, "+");

    auto left_lit = std::dynamic_pointer_cast<IntLiteralNode>(binop->left);
    auto right_lit = std::dynamic_pointer_cast<IntLiteralNode>(binop->right);
    ASSERT_TRUE(left_lit);
    ASSERT_TRUE(right_lit);
    EXPECT_EQ(left_lit->value, 1);
    EXPECT_EQ(right_lit->value, 2);
}

TEST(ASTBuilder, IfStmtElse) {
    std::string src = "if (x) { print(x); } else { x = 0; }\n";
    auto root = std::dynamic_pointer_cast<BlockNode>(BuildAst(src));
    ASSERT_TRUE(root);
    ASSERT_EQ(root->statements.size(), 1);

    auto if_node = std::dynamic_pointer_cast<IfNode>(root->statements[0]);
    ASSERT_TRUE(if_node);

    auto cond_ref = std::dynamic_pointer_cast<VarRefNode>(if_node->condition);
    ASSERT_TRUE(cond_ref);
    EXPECT_EQ(cond_ref->var_name, "x");

    auto then_block = std::dynamic_pointer_cast<BlockNode>(if_node->then_block);
    ASSERT_TRUE(then_block);
    ASSERT_EQ(then_block->statements.size(), 1);
    EXPECT_TRUE(
        std::dynamic_pointer_cast<PrintNode>(then_block->statements[0]));

    auto else_block = std::dynamic_pointer_cast<BlockNode>(if_node->else_block);
    ASSERT_TRUE(else_block);
    ASSERT_EQ(else_block->statements.size(), 1);
    EXPECT_TRUE(
        std::dynamic_pointer_cast<AssignmentNode>(else_block->statements[0]));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
