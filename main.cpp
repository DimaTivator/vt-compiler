#include <antlr4-runtime.h>

#include <fstream>
#include <iostream>

#include "backend/address_alloc.h"
#include "backend/asm_generation.h"
#include "backend/register_allocator.h"
#include "backend/utils/backend_utils.h"
#include "frontend/VtLexer.h"
#include "frontend/ast_builder.h"
#include "frontend/semantic.h"
#include "frontend/utils/ast_utils.h"
#include "middle/ir_generator.h"
#include "middle/utils/ir_utils.h"

void Compile(std::string program_file, std::string output_file) {
    std::ifstream stream(program_file);
    if (!stream) {
        std::cerr << "Cannot open input file.\n";
        return;
    }

    antlr4::ANTLRInputStream input(stream);
    VtLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    VtParser parser(&tokens);

    antlr4::tree::ParseTree* tree = parser.program();

    vt::ast::ASTBuilder builder;
    auto ast =
        std::any_cast<std::shared_ptr<vt::ast::ASTNode>>(builder.visit(tree));

    std::ofstream ast_out(output_file + "_ast");
    vt::ast::PrintAST(ast, ast_out);

    vt::sem::SemanticAnalyzer sem;
    sem.Analyze(ast);

    vt::ir::IRGenerator gen;
    auto ir = gen.Generate(ast);

    std::ofstream ir1_out(output_file + "_ir1");
    vt::ir::PrintIR(ir, ir1_out);

    ir = vt::back::AllocateRegistersLinearScan(ir);
    vt::back::AllocateStrings(ir);
    ir = vt::back::AllocateSpillSlots(ir);

    std::ofstream ir2_out(output_file + "_ir2");
    vt::ir::PrintIR(ir, ir2_out);

    vt::back::Asm asm_code = vt::back::GenerateASM(ir);
    std::ofstream asm_out(output_file + ".asm");
    vt::back::PrintASM(asm_code, asm_out);
}

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];
    Compile(input_file, output_file);

    return 0;
}
