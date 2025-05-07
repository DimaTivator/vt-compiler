
// Generated from Vt.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "VtListener.h"


/**
 * This class provides an empty implementation of VtListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  VtBaseListener : public VtListener {
public:

  virtual void enterProgram(VtParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(VtParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(VtParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(VtParser::StatementContext * /*ctx*/) override { }

  virtual void enterVarDecl(VtParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(VtParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterType(VtParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(VtParser::TypeContext * /*ctx*/) override { }

  virtual void enterAssignment(VtParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(VtParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterPrintStmt(VtParser::PrintStmtContext * /*ctx*/) override { }
  virtual void exitPrintStmt(VtParser::PrintStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(VtParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(VtParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(VtParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(VtParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterBlock(VtParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(VtParser::BlockContext * /*ctx*/) override { }

  virtual void enterAndExpr(VtParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(VtParser::AndExprContext * /*ctx*/) override { }

  virtual void enterStringLiteral(VtParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(VtParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterIdExpr(VtParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(VtParser::IdExprContext * /*ctx*/) override { }

  virtual void enterMulDiv(VtParser::MulDivContext * /*ctx*/) override { }
  virtual void exitMulDiv(VtParser::MulDivContext * /*ctx*/) override { }

  virtual void enterAddSub(VtParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(VtParser::AddSubContext * /*ctx*/) override { }

  virtual void enterComparison(VtParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(VtParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterNegExpr(VtParser::NegExprContext * /*ctx*/) override { }
  virtual void exitNegExpr(VtParser::NegExprContext * /*ctx*/) override { }

  virtual void enterParensExpr(VtParser::ParensExprContext * /*ctx*/) override { }
  virtual void exitParensExpr(VtParser::ParensExprContext * /*ctx*/) override { }

  virtual void enterIntLiteral(VtParser::IntLiteralContext * /*ctx*/) override { }
  virtual void exitIntLiteral(VtParser::IntLiteralContext * /*ctx*/) override { }

  virtual void enterNotExpr(VtParser::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(VtParser::NotExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(VtParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(VtParser::OrExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

