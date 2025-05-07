
// Generated from Vt.g4 by ANTLR 4.10.1

#pragma once

#include "VtParser.h"
#include "antlr4-runtime.h"

/**
 * This class defines an abstract visitor for a parse tree
 * produced by VtParser.
 */
class VtVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:
    /**
     * Visit parse trees produced by VtParser.
     */
    virtual std::any visitProgram(VtParser::ProgramContext* context) = 0;

    virtual std::any visitStatement(VtParser::StatementContext* context) = 0;

    virtual std::any visitVarDecl(VtParser::VarDeclContext* context) = 0;

    virtual std::any visitType(VtParser::TypeContext* context) = 0;

    virtual std::any visitAssignment(VtParser::AssignmentContext* context) = 0;

    virtual std::any visitPrintStmt(VtParser::PrintStmtContext* context) = 0;

    virtual std::any visitIfStmt(VtParser::IfStmtContext* context) = 0;

    virtual std::any visitWhileStmt(VtParser::WhileStmtContext* context) = 0;

    virtual std::any visitBlock(VtParser::BlockContext* context) = 0;

    virtual std::any visitAndExpr(VtParser::AndExprContext* context) = 0;

    virtual std::any visitStringLiteral(
        VtParser::StringLiteralContext* context) = 0;

    virtual std::any visitIdExpr(VtParser::IdExprContext* context) = 0;

    virtual std::any visitMulDiv(VtParser::MulDivContext* context) = 0;

    virtual std::any visitAddSub(VtParser::AddSubContext* context) = 0;

    virtual std::any visitComparison(VtParser::ComparisonContext* context) = 0;

    virtual std::any visitNegExpr(VtParser::NegExprContext* context) = 0;

    virtual std::any visitParensExpr(VtParser::ParensExprContext* context) = 0;

    virtual std::any visitIntLiteral(VtParser::IntLiteralContext* context) = 0;

    virtual std::any visitNotExpr(VtParser::NotExprContext* context) = 0;

    virtual std::any visitOrExpr(VtParser::OrExprContext* context) = 0;
};
