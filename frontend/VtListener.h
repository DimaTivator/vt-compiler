
// Generated from Vt.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "VtParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by VtParser.
 */
class  VtListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(VtParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(VtParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(VtParser::StatementContext *ctx) = 0;
  virtual void exitStatement(VtParser::StatementContext *ctx) = 0;

  virtual void enterVarDecl(VtParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(VtParser::VarDeclContext *ctx) = 0;

  virtual void enterType(VtParser::TypeContext *ctx) = 0;
  virtual void exitType(VtParser::TypeContext *ctx) = 0;

  virtual void enterAssignment(VtParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(VtParser::AssignmentContext *ctx) = 0;

  virtual void enterPrintStmt(VtParser::PrintStmtContext *ctx) = 0;
  virtual void exitPrintStmt(VtParser::PrintStmtContext *ctx) = 0;

  virtual void enterIfStmt(VtParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(VtParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(VtParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(VtParser::WhileStmtContext *ctx) = 0;

  virtual void enterBlock(VtParser::BlockContext *ctx) = 0;
  virtual void exitBlock(VtParser::BlockContext *ctx) = 0;

  virtual void enterAndExpr(VtParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(VtParser::AndExprContext *ctx) = 0;

  virtual void enterStringLiteral(VtParser::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(VtParser::StringLiteralContext *ctx) = 0;

  virtual void enterIdExpr(VtParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(VtParser::IdExprContext *ctx) = 0;

  virtual void enterMulDiv(VtParser::MulDivContext *ctx) = 0;
  virtual void exitMulDiv(VtParser::MulDivContext *ctx) = 0;

  virtual void enterAddSub(VtParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(VtParser::AddSubContext *ctx) = 0;

  virtual void enterComparison(VtParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(VtParser::ComparisonContext *ctx) = 0;

  virtual void enterParensExpr(VtParser::ParensExprContext *ctx) = 0;
  virtual void exitParensExpr(VtParser::ParensExprContext *ctx) = 0;

  virtual void enterIntLiteral(VtParser::IntLiteralContext *ctx) = 0;
  virtual void exitIntLiteral(VtParser::IntLiteralContext *ctx) = 0;

  virtual void enterNotExpr(VtParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(VtParser::NotExprContext *ctx) = 0;

  virtual void enterOrExpr(VtParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(VtParser::OrExprContext *ctx) = 0;


};

