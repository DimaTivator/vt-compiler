#include <gtest/gtest.h>

#include "../../frontend/ast_builder.h"
#include "../ir_generator.h"

using namespace vt::ir;
using namespace vt::ast;

std::shared_ptr<BlockNode> MakeBlock(
    std::initializer_list<std::shared_ptr<ASTNode>> statements) {
    return std::make_shared<BlockNode>(
        std::vector<std::shared_ptr<ASTNode>>(statements));
}

TEST(IRGenerator, SimpleAssignment) {
    // int x = 1 + 2;
    auto expr =
        std::make_shared<BinaryOpNode>("+", std::make_shared<IntLiteralNode>(1),
                                       std::make_shared<IntLiteralNode>(2));
    auto decl = std::make_shared<VarDeclNode>("int", "x", expr);
    auto block = MakeBlock({decl});

    IRGenerator gen;
    IR ir = gen.Generate(block);
    // Expected sequence:
    // t0 = 1
    // t1 = 2
    // t2 = t0 + t1
    // x = t2
    ASSERT_EQ(ir.size(), 4);
    EXPECT_EQ(ir[0].op, IRInstruction::Op::LOAD_CONST);
    EXPECT_EQ(ir[0].result, "v0");
    EXPECT_EQ(std::get<int>(ir[0].arg1), 1);

    EXPECT_EQ(ir[1].op, IRInstruction::Op::LOAD_CONST);
    EXPECT_EQ(ir[1].result, "v1");
    EXPECT_EQ(std::get<int>(ir[1].arg1), 2);

    EXPECT_EQ(ir[2].op, IRInstruction::Op::ADD);
    EXPECT_EQ(ir[2].result, "v2");
    EXPECT_EQ(std::get<std::string>(ir[2].arg1), "v0");
    EXPECT_EQ(std::get<std::string>(ir[2].arg2), "v1");

    EXPECT_EQ(ir[3].op, IRInstruction::Op::ASSIGN);
    EXPECT_EQ(ir[3].result, "x");
    EXPECT_EQ(std::get<std::string>(ir[3].arg1), "v2");
}

TEST(IRGenerator, PrintStatement) {
    // print 42;
    auto lit = std::make_shared<IntLiteralNode>(42);
    auto print = std::make_shared<PrintNode>(lit);
    auto block = MakeBlock({print});

    IRGenerator gen;
    IR ir = gen.Generate(block);
    // Expected: t0=42, print t0
    ASSERT_EQ(ir.size(), 2);
    EXPECT_EQ(ir[0].op, IRInstruction::Op::LOAD_CONST);
    EXPECT_EQ(ir[0].result, "v0");
    EXPECT_EQ(std::get<int>(ir[0].arg1), 42);

    EXPECT_EQ(ir[1].op, IRInstruction::Op::PRINT);
    EXPECT_EQ(std::get<std::string>(ir[1].arg1), "v0");
}

TEST(IRGenerator, IfWithoutElse) {
    // if (x) { print x; }
    auto cond = std::make_shared<VarRefNode>("x");
    auto then_print = std::make_shared<PrintNode>(cond);
    auto then_block = std::make_shared<BlockNode>(
        std::vector<std::shared_ptr<ASTNode>>{then_print});
    auto ifnode = std::make_shared<IfNode>(cond, then_block, nullptr);
    auto block = MakeBlock({ifnode});

    IRGenerator gen;
    IR ir = gen.Generate(block);
    // Sequence:
    // if x == 0 goto L0
    // print x
    // goto L1
    // L0:
    // L1:
    ASSERT_GE(ir.size(), 5);
    EXPECT_EQ(ir[0].op, IRInstruction::Op::BRANCH_IF_ZERO);
    EXPECT_EQ(std::get<std::string>(ir[0].arg1), "x");
    // label names L0, L1 in positions 3 and 4
    EXPECT_EQ(ir[3].op, IRInstruction::Op::LABEL);
    EXPECT_EQ(ir[3].result, "L0");
    EXPECT_EQ(ir[4].op, IRInstruction::Op::LABEL);
    EXPECT_EQ(ir[4].result, "L1");
}

TEST(IRGenerator, WhileLoop) {
    // while (x) { x = x - 1; }
    auto cond = std::make_shared<VarRefNode>("x");
    auto dec = std::make_shared<BinaryOpNode>(
        "-", cond, std::make_shared<IntLiteralNode>(1));
    auto assign = std::make_shared<AssignmentNode>("x", dec);
    auto body = std::make_shared<BlockNode>(
        std::vector<std::shared_ptr<ASTNode>>{assign});
    auto while_node = std::make_shared<WhileNode>(cond, body);
    auto block = MakeBlock({while_node});

    IRGenerator gen;
    IR ir = gen.Generate(block);

    EXPECT_EQ(ir.front().op, IRInstruction::Op::LABEL);
    EXPECT_EQ(ir.back().op, IRInstruction::Op::LABEL);
    EXPECT_EQ(ir.back().result, "L1");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
