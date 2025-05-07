
// Generated from Vt.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "VtVisitor.h"


/**
 * This class provides an empty implementation of VtVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  VtBaseVisitor : public VtVisitor {
public:

  virtual std::any visitProgram(VtParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(VtParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(VtParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(VtParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(VtParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStmt(VtParser::PrintStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(VtParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(VtParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(VtParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(VtParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(VtParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdExpr(VtParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDiv(VtParser::MulDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSub(VtParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(VtParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParensExpr(VtParser::ParensExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntLiteral(VtParser::IntLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(VtParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(VtParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

