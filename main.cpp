#include <antlr4-runtime.h>

#include <fstream>
#include <iostream>

#include "frontend/VtLexer.h"
#include "frontend/semantic.h"
#include "frontend/utils/ast_utils.h"
#include "middle/ir_generator.h"
#include "middle/utils/ir_utils.h"

int main(int argc, const char* argv[]) {
    std::ifstream stream("../example.vt");
    if (!stream) {
        std::cerr << "Cannot open input file.\n";
        return 1;
    }

    antlr4::ANTLRInputStream input(stream);
    VtLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    VtParser parser(&tokens);

    antlr4::tree::ParseTree* tree = parser.program();

    vt::sem::SemanticAnalyzer sem_analyzer;
    std::any sem_result = sem_analyzer.visit(tree);

    auto ast_root =
        std::any_cast<std::shared_ptr<vt::ast::ASTNode>>(sem_result);
    vt::ast::PrintAST(ast_root);

    vt::ir::IRGenerator gen;
    auto ir =
        gen.Generate(std::dynamic_pointer_cast<vt::ast::BlockNode>(ast_root));

    vt::ir::PrintIR(ir);

    return 0;
}
