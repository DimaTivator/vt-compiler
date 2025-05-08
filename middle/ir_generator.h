#pragma once

#include <utility>

#include "../frontend/ast.h"
#include "ir.h"

namespace vt::ir {

class IRGenerator {
public:
    IRGenerator();

    IR Generate(const std::shared_ptr<ast::BlockNode>& root);

    IR Generate(const std::shared_ptr<ast::ASTNode>& root);

private:
    IR ir_;
    int temp_count_;
    int label_count_;

    std::string NewRegister();
    std::string NewLabel();

    void Emit(const IRInstruction& instr);

    std::string ProcessUnaryOpNode(
        const std::shared_ptr<ast::UnaryOpNode>& node);
    std::string ProcessBinaryOpNode(
        const std::shared_ptr<ast::BinaryOpNode>& node);

    std::string EmitExpr(const std::shared_ptr<ast::ASTNode>& node);

    void ProcessIfNode(const std::shared_ptr<ast::IfNode>& node);
    void ProcessWhileNode(const std::shared_ptr<ast::WhileNode>& node);

    void EmitStatement(const std::shared_ptr<ast::ASTNode>& node);

    void EmitBlock(const std::shared_ptr<ast::BlockNode>& block);

    void EmitBlockNode(const std::shared_ptr<ast::ASTNode>& node);
};

IR RemoveVariableNames(const IR& ir);

}  // namespace vt::ir
