#include "ir_generator.h"

namespace vt::ir {

IRGenerator::IRGenerator() : temp_count_(0), label_count_(0) {}

IR IRGenerator::Generate(const std::shared_ptr<vt::ast::BlockNode>& root) {
    EmitBlock(root);
    return ir_;
}

IR IRGenerator::Generate(const std::shared_ptr<vt::ast::ASTNode>& root) {
    EmitBlockNode(root);
    return ir_;
}

std::string IRGenerator::NewRegister() {
    return "v" + std::to_string(temp_count_++);
}

std::string IRGenerator::NewLabel() {
    return "L" + std::to_string(label_count_++);
}

void IRGenerator::Emit(const IRInstruction& instr) { ir_.push_back(instr); }

std::string IRGenerator::ProcessUnaryOpNode(
    const std::shared_ptr<vt::ast::UnaryOpNode>& node) {
    auto operand_t = EmitExpr(node->operand);
    auto reg = NewRegister();
    if (node->op == "-") {
        Emit({IRInstruction::Op::LOAD_CONST, reg, 0, 0});
        Emit({IRInstruction::Op::SUB, reg, reg, operand_t});
        return reg;
    }
    if (node->op == "not") {
        Emit({IRInstruction::Op::LOAD_CONST, reg, 0, 0});
        Emit({IRInstruction::Op::NOT, reg, operand_t, 0});
        return reg;
    }
    throw std::runtime_error("Unsupported unary op: " + node->op);
}

std::string IRGenerator::ProcessBinaryOpNode(
    const std::shared_ptr<vt::ast::BinaryOpNode>& node) {
    auto lhs = EmitExpr(node->left);
    auto rhs = EmitExpr(node->right);
    auto reg = NewRegister();
    IRInstruction::Op op;

    if (node->op == "+") {
        op = IRInstruction::Op::ADD;
    } else if (node->op == "-") {
        op = IRInstruction::Op::SUB;
    } else if (node->op == "*") {
        op = IRInstruction::Op::MUL;
    } else if (node->op == "/") {
        op = IRInstruction::Op::DIV;
    }

    else if (node->op == "==" || node->op == "!=" || node->op == "<" ||
             node->op == ">" || node->op == "<=" || node->op == ">=") {
        op = IRInstruction::Op::SUB;
    }

    else if (node->op == "not") {
        op = IRInstruction::Op::NOT;
    } else if (node->op == "and") {
        op = IRInstruction::Op::AND;
    } else if (node->op == "or") {
        op = IRInstruction::Op::OR;
    }

    else {
        throw std::runtime_error("Unsupported binary op: " + node->op);
    }

    Emit({op, reg, lhs, rhs});
    return reg;
}

std::string IRGenerator::EmitExpr(const std::shared_ptr<ast::ASTNode>& node) {
    if (auto lit = std::dynamic_pointer_cast<ast::IntLiteralNode>(node)) {
        std::string reg = NewRegister();
        Emit({IRInstruction::Op::LOAD_CONST, reg, lit->value, 0});
        return reg;
    }

    if (auto lit = std::dynamic_pointer_cast<ast::StringLiteralNode>(node)) {
        std::string reg = NewRegister();
        Emit({IRInstruction::Op::LOAD_CONST, reg, lit->value, ""});
        return reg;
    }

    if (auto ref = std::dynamic_pointer_cast<ast::VarRefNode>(node)) {
        return ref->var_name;
    }

    if (auto un = std::dynamic_pointer_cast<ast::UnaryOpNode>(node)) {
        return ProcessUnaryOpNode(un);
    }

    if (auto bin = std::dynamic_pointer_cast<ast::BinaryOpNode>(node)) {
        return ProcessBinaryOpNode(bin);
    }

    throw std::runtime_error("Unsupported expr node");
}

void IRGenerator::ProcessIfNode(const std::shared_ptr<ast::IfNode>& node) {
    auto cond_t = EmitExpr(node->condition);
    auto else_l = NewLabel();
    auto end_l = NewLabel();

    Emit({IRInstruction::Op::BRANCH_IF_ZERO, else_l, cond_t, 0});
    EmitBlockNode(node->then_block);
    Emit({IRInstruction::Op::GOTO, end_l, 0, 0});
    Emit({IRInstruction::Op::LABEL, else_l, 0, 0});

    if (node->else_block) {
        EmitBlockNode(node->else_block);
    }

    Emit({IRInstruction::Op::LABEL, end_l, 0, 0});
}

void IRGenerator::ProcessWhileNode(const std::shared_ptr<ast::WhileNode>& node) {
    auto start_l = NewLabel();
    auto end_l = NewLabel();

    Emit({IRInstruction::Op::LABEL, start_l, 0, 0});

    auto cond_t = EmitExpr(node->condition);

    Emit({IRInstruction::Op::BRANCH_IF_ZERO, end_l, cond_t, 0});
    EmitBlockNode(node->body);
    Emit({IRInstruction::Op::GOTO, start_l, 0, 0});
    Emit({IRInstruction::Op::LABEL, end_l, 0, 0});
}

void IRGenerator::EmitStatement(const std::shared_ptr<vt::ast::ASTNode>& node) {
    if (auto decl = std::dynamic_pointer_cast<ast::VarDeclNode>(node)) {
        auto rhs = EmitExpr(decl->init_expr);
        Emit({IRInstruction::Op::ASSIGN, decl->var_name, rhs, 0});
        return;
    }

    if (auto assign = std::dynamic_pointer_cast<ast::AssignmentNode>(node)) {
        auto rhs = EmitExpr(assign->expr);
        Emit({IRInstruction::Op::ASSIGN, assign->var_name, rhs, 0});
        return;
    }

    if (auto print = std::dynamic_pointer_cast<ast::PrintNode>(node)) {
        auto arg = EmitExpr(print->expr);
        Emit({IRInstruction::Op::PRINT, "", arg, 0});
        return;
    }

    if (auto block = std::dynamic_pointer_cast<ast::BlockNode>(node)) {
        EmitBlock(block);
        return;
    }

    if (auto if_node = std::dynamic_pointer_cast<ast::IfNode>(node)) {
        ProcessIfNode(if_node);
        return;
    }

    if (auto while_node = std::dynamic_pointer_cast<ast::WhileNode>(node)) {
        ProcessWhileNode(while_node);
        return;
    }

    throw std::runtime_error("Unsupported statement node");
}

void IRGenerator::EmitBlock(const std::shared_ptr<vt::ast::BlockNode>& block) {
    for (auto& stmt : block->statements) {
        EmitStatement(stmt);
    }
}

void IRGenerator::EmitBlockNode(const std::shared_ptr<vt::ast::ASTNode>& node) {
    auto block = std::dynamic_pointer_cast<vt::ast::BlockNode>(node);
    EmitBlock(block);
}

}  // namespace vt::ir
