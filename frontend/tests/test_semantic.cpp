#include <gtest/gtest.h>

#include "../VtLexer.h"
#include "../VtParser.h"
#include "../ast_builder.h"
#include "../semantic.h"

using namespace vt::sem;
using namespace vt::ast;
using namespace antlr4;

static std::string RunSemantic(const std::string& src) {
    testing::internal::CaptureStderr();

    ANTLRInputStream input(src);
    VtLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    VtParser parser(&tokens);

    vt::ast::ASTBuilder builder;
    auto ast = std::any_cast<std::shared_ptr<vt::ast::ASTNode>>(
        builder.visit(parser.program()));

    SemanticAnalyzer sem;
    sem.Analyze(ast);

    return testing::internal::GetCapturedStderr();
}

TEST(SemanticAnalyzer, NoErrors) {
    std::string src = "int x = 1; x = x + 2; print x;";
    EXPECT_TRUE(RunSemantic(src).empty());
}

TEST(SemanticAnalyzer, RedeclarationError) {
    EXPECT_NE(RunSemantic("int x = 0; int x = 1;"), "");
}

TEST(SemanticAnalyzer, InitializationTypeMismatch) {
    auto err = RunSemantic("string s = 42;");
    EXPECT_NE(err.find("Cannot initialize variable 's' of type string"),
              std::string::npos);
}

TEST(SemanticAnalyzer, UndeclaredVariableError) {
    EXPECT_NE(RunSemantic("x = 5;"), "");
}

TEST(SemanticAnalyzer, AssignmentTypeMismatch) {
    EXPECT_NE(RunSemantic("int x = 1; x = \"hello\";"), "");
}

TEST(SemanticAnalyzer, IfConditionTypeError) {
    EXPECT_NE(RunSemantic("string s = \"hi\"; if (s) { }"), "");
}

TEST(SemanticAnalyzer, WhileConditionTypeError) {
    EXPECT_NE(RunSemantic("string s = \"loop\"; while (s) { }"), "");
}

TEST(SemanticAnalyzer, AndExprTypeError) {
    EXPECT_NE(RunSemantic("int a = 1 and \"bad\";"), "");
}

TEST(SemanticAnalyzer, OrExprTypeError) {
    EXPECT_NE(RunSemantic("trueVal = 0 or \"hi\";"), "");
}

TEST(SemanticAnalyzer, ComparisonTypeError) {
    EXPECT_NE(RunSemantic("int a = 1; string b = \"b\"; if (a == b) { }"), "");
}

TEST(SemanticAnalyzer, InnerScopeShadowing) {
    EXPECT_TRUE(RunSemantic("int x = 0; { string x = \"ok\"; }").empty());
}

TEST(SemanticAnalyzer, InnerRedeclarationError) {
    EXPECT_NE(RunSemantic("{ int y = 1; int y = 2; }"), "");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
