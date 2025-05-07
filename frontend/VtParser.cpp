
// Generated from Vt.g4 by ANTLR 4.10.1


#include "VtListener.h"
#include "VtVisitor.h"

#include "VtParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct VtParserStaticData final {
  VtParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VtParserStaticData(const VtParserStaticData&) = delete;
  VtParserStaticData(VtParserStaticData&&) = delete;
  VtParserStaticData& operator=(const VtParserStaticData&) = delete;
  VtParserStaticData& operator=(VtParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag vtParserOnceFlag;
VtParserStaticData *vtParserStaticData = nullptr;

void vtParserInitialize() {
  assert(vtParserStaticData == nullptr);
  auto staticData = std::make_unique<VtParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "varDecl", "type", "assignment", "printStmt", 
      "ifStmt", "whileStmt", "block", "expr"
    },
    std::vector<std::string>{
      "", "", "", "", "'if'", "'else'", "'while'", "'int'", "'string'", 
      "'print'", "'and'", "'or'", "'not'", "'='", "';'", "'('", "')'", "'{'", 
      "'}'", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'<='", "'>='", "'=='", 
      "'!='"
    },
    std::vector<std::string>{
      "", "INT_LITERAL", "STRING_LITERAL", "ID", "IF", "ELSE", "WHILE", 
      "INT", "STRING", "PRINT", "AND", "OR", "NOT", "EQ", "SEMI", "LPAREN", 
      "RPAREN", "LBRACE", "RBRACE", "PLUS", "MINUS", "STAR", "DIV", "LT", 
      "GT", "LE", "GE", "EQEQ", "NEQ", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,31,116,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,0,1,0,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,41,8,1,1,2,1,2,1,2,1,2,3,
  	2,47,8,2,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,3,6,67,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,5,8,77,8,8,10,
  	8,12,8,80,9,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,94,
  	8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,111,
  	8,9,10,9,12,9,114,9,9,1,9,0,1,18,10,0,2,4,6,8,10,12,14,16,18,0,4,1,0,
  	7,8,1,0,21,22,1,0,19,20,1,0,23,28,123,0,23,1,0,0,0,2,40,1,0,0,0,4,42,
  	1,0,0,0,6,48,1,0,0,0,8,50,1,0,0,0,10,54,1,0,0,0,12,59,1,0,0,0,14,68,1,
  	0,0,0,16,74,1,0,0,0,18,93,1,0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,25,1,
  	0,0,0,23,21,1,0,0,0,23,24,1,0,0,0,24,26,1,0,0,0,25,23,1,0,0,0,26,27,5,
  	0,0,1,27,1,1,0,0,0,28,29,3,4,2,0,29,30,5,14,0,0,30,41,1,0,0,0,31,32,3,
  	8,4,0,32,33,5,14,0,0,33,41,1,0,0,0,34,35,3,10,5,0,35,36,5,14,0,0,36,41,
  	1,0,0,0,37,41,3,12,6,0,38,41,3,14,7,0,39,41,3,16,8,0,40,28,1,0,0,0,40,
  	31,1,0,0,0,40,34,1,0,0,0,40,37,1,0,0,0,40,38,1,0,0,0,40,39,1,0,0,0,41,
  	3,1,0,0,0,42,43,3,6,3,0,43,46,5,3,0,0,44,45,5,13,0,0,45,47,3,18,9,0,46,
  	44,1,0,0,0,46,47,1,0,0,0,47,5,1,0,0,0,48,49,7,0,0,0,49,7,1,0,0,0,50,51,
  	5,3,0,0,51,52,5,13,0,0,52,53,3,18,9,0,53,9,1,0,0,0,54,55,5,9,0,0,55,56,
  	5,15,0,0,56,57,3,18,9,0,57,58,5,16,0,0,58,11,1,0,0,0,59,60,5,4,0,0,60,
  	61,5,15,0,0,61,62,3,18,9,0,62,63,5,16,0,0,63,66,3,2,1,0,64,65,5,5,0,0,
  	65,67,3,2,1,0,66,64,1,0,0,0,66,67,1,0,0,0,67,13,1,0,0,0,68,69,5,6,0,0,
  	69,70,5,15,0,0,70,71,3,18,9,0,71,72,5,16,0,0,72,73,3,2,1,0,73,15,1,0,
  	0,0,74,78,5,17,0,0,75,77,3,2,1,0,76,75,1,0,0,0,77,80,1,0,0,0,78,76,1,
  	0,0,0,78,79,1,0,0,0,79,81,1,0,0,0,80,78,1,0,0,0,81,82,5,18,0,0,82,17,
  	1,0,0,0,83,84,6,9,-1,0,84,85,5,12,0,0,85,94,3,18,9,5,86,87,5,15,0,0,87,
  	88,3,18,9,0,88,89,5,16,0,0,89,94,1,0,0,0,90,94,5,1,0,0,91,94,5,2,0,0,
  	92,94,5,3,0,0,93,83,1,0,0,0,93,86,1,0,0,0,93,90,1,0,0,0,93,91,1,0,0,0,
  	93,92,1,0,0,0,94,112,1,0,0,0,95,96,10,10,0,0,96,97,7,1,0,0,97,111,3,18,
  	9,11,98,99,10,9,0,0,99,100,7,2,0,0,100,111,3,18,9,10,101,102,10,8,0,0,
  	102,103,7,3,0,0,103,111,3,18,9,9,104,105,10,7,0,0,105,106,5,10,0,0,106,
  	111,3,18,9,8,107,108,10,6,0,0,108,109,5,11,0,0,109,111,3,18,9,7,110,95,
  	1,0,0,0,110,98,1,0,0,0,110,101,1,0,0,0,110,104,1,0,0,0,110,107,1,0,0,
  	0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,19,1,0,0,0,114,
  	112,1,0,0,0,8,23,40,46,66,78,93,110,112
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vtParserStaticData = staticData.release();
}

}

VtParser::VtParser(TokenStream *input) : VtParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

VtParser::VtParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  VtParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *vtParserStaticData->atn, vtParserStaticData->decisionToDFA, vtParserStaticData->sharedContextCache, options);
}

VtParser::~VtParser() {
  delete _interpreter;
}

const atn::ATN& VtParser::getATN() const {
  return *vtParserStaticData->atn;
}

std::string VtParser::getGrammarFileName() const {
  return "Vt.g4";
}

const std::vector<std::string>& VtParser::getRuleNames() const {
  return vtParserStaticData->ruleNames;
}

const dfa::Vocabulary& VtParser::getVocabulary() const {
  return vtParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VtParser::getSerializedATN() const {
  return vtParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

VtParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::ProgramContext::EOF() {
  return getToken(VtParser::EOF, 0);
}

std::vector<VtParser::StatementContext *> VtParser::ProgramContext::statement() {
  return getRuleContexts<VtParser::StatementContext>();
}

VtParser::StatementContext* VtParser::ProgramContext::statement(size_t i) {
  return getRuleContext<VtParser::StatementContext>(i);
}


size_t VtParser::ProgramContext::getRuleIndex() const {
  return VtParser::RuleProgram;
}

void VtParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void VtParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any VtParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

VtParser::ProgramContext* VtParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, VtParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << VtParser::ID)
      | (1ULL << VtParser::IF)
      | (1ULL << VtParser::WHILE)
      | (1ULL << VtParser::INT)
      | (1ULL << VtParser::STRING)
      | (1ULL << VtParser::PRINT)
      | (1ULL << VtParser::LBRACE))) != 0)) {
      setState(20);
      statement();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
    match(VtParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

VtParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VtParser::VarDeclContext* VtParser::StatementContext::varDecl() {
  return getRuleContext<VtParser::VarDeclContext>(0);
}

tree::TerminalNode* VtParser::StatementContext::SEMI() {
  return getToken(VtParser::SEMI, 0);
}

VtParser::AssignmentContext* VtParser::StatementContext::assignment() {
  return getRuleContext<VtParser::AssignmentContext>(0);
}

VtParser::PrintStmtContext* VtParser::StatementContext::printStmt() {
  return getRuleContext<VtParser::PrintStmtContext>(0);
}

VtParser::IfStmtContext* VtParser::StatementContext::ifStmt() {
  return getRuleContext<VtParser::IfStmtContext>(0);
}

VtParser::WhileStmtContext* VtParser::StatementContext::whileStmt() {
  return getRuleContext<VtParser::WhileStmtContext>(0);
}

VtParser::BlockContext* VtParser::StatementContext::block() {
  return getRuleContext<VtParser::BlockContext>(0);
}


size_t VtParser::StatementContext::getRuleIndex() const {
  return VtParser::RuleStatement;
}

void VtParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void VtParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any VtParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

VtParser::StatementContext* VtParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, VtParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VtParser::INT:
      case VtParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(28);
        varDecl();
        setState(29);
        match(VtParser::SEMI);
        break;
      }

      case VtParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        assignment();
        setState(32);
        match(VtParser::SEMI);
        break;
      }

      case VtParser::PRINT: {
        enterOuterAlt(_localctx, 3);
        setState(34);
        printStmt();
        setState(35);
        match(VtParser::SEMI);
        break;
      }

      case VtParser::IF: {
        enterOuterAlt(_localctx, 4);
        setState(37);
        ifStmt();
        break;
      }

      case VtParser::WHILE: {
        enterOuterAlt(_localctx, 5);
        setState(38);
        whileStmt();
        break;
      }

      case VtParser::LBRACE: {
        enterOuterAlt(_localctx, 6);
        setState(39);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

VtParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

VtParser::TypeContext* VtParser::VarDeclContext::type() {
  return getRuleContext<VtParser::TypeContext>(0);
}

tree::TerminalNode* VtParser::VarDeclContext::ID() {
  return getToken(VtParser::ID, 0);
}

tree::TerminalNode* VtParser::VarDeclContext::EQ() {
  return getToken(VtParser::EQ, 0);
}

VtParser::ExprContext* VtParser::VarDeclContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}


size_t VtParser::VarDeclContext::getRuleIndex() const {
  return VtParser::RuleVarDecl;
}

void VtParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void VtParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any VtParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

VtParser::VarDeclContext* VtParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, VtParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    type();
    setState(43);
    match(VtParser::ID);
    setState(46);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == VtParser::EQ) {
      setState(44);
      match(VtParser::EQ);
      setState(45);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

VtParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::TypeContext::INT() {
  return getToken(VtParser::INT, 0);
}

tree::TerminalNode* VtParser::TypeContext::STRING() {
  return getToken(VtParser::STRING, 0);
}


size_t VtParser::TypeContext::getRuleIndex() const {
  return VtParser::RuleType;
}

void VtParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void VtParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any VtParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

VtParser::TypeContext* VtParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 6, VtParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    _la = _input->LA(1);
    if (!(_la == VtParser::INT

    || _la == VtParser::STRING)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

VtParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::AssignmentContext::ID() {
  return getToken(VtParser::ID, 0);
}

tree::TerminalNode* VtParser::AssignmentContext::EQ() {
  return getToken(VtParser::EQ, 0);
}

VtParser::ExprContext* VtParser::AssignmentContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}


size_t VtParser::AssignmentContext::getRuleIndex() const {
  return VtParser::RuleAssignment;
}

void VtParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void VtParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any VtParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

VtParser::AssignmentContext* VtParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 8, VtParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(VtParser::ID);
    setState(51);
    match(VtParser::EQ);
    setState(52);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStmtContext ------------------------------------------------------------------

VtParser::PrintStmtContext::PrintStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::PrintStmtContext::PRINT() {
  return getToken(VtParser::PRINT, 0);
}

tree::TerminalNode* VtParser::PrintStmtContext::LPAREN() {
  return getToken(VtParser::LPAREN, 0);
}

VtParser::ExprContext* VtParser::PrintStmtContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}

tree::TerminalNode* VtParser::PrintStmtContext::RPAREN() {
  return getToken(VtParser::RPAREN, 0);
}


size_t VtParser::PrintStmtContext::getRuleIndex() const {
  return VtParser::RulePrintStmt;
}

void VtParser::PrintStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStmt(this);
}

void VtParser::PrintStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStmt(this);
}


std::any VtParser::PrintStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitPrintStmt(this);
  else
    return visitor->visitChildren(this);
}

VtParser::PrintStmtContext* VtParser::printStmt() {
  PrintStmtContext *_localctx = _tracker.createInstance<PrintStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, VtParser::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(VtParser::PRINT);
    setState(55);
    match(VtParser::LPAREN);
    setState(56);
    expr(0);
    setState(57);
    match(VtParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

VtParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::IfStmtContext::IF() {
  return getToken(VtParser::IF, 0);
}

tree::TerminalNode* VtParser::IfStmtContext::LPAREN() {
  return getToken(VtParser::LPAREN, 0);
}

VtParser::ExprContext* VtParser::IfStmtContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}

tree::TerminalNode* VtParser::IfStmtContext::RPAREN() {
  return getToken(VtParser::RPAREN, 0);
}

std::vector<VtParser::StatementContext *> VtParser::IfStmtContext::statement() {
  return getRuleContexts<VtParser::StatementContext>();
}

VtParser::StatementContext* VtParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<VtParser::StatementContext>(i);
}

tree::TerminalNode* VtParser::IfStmtContext::ELSE() {
  return getToken(VtParser::ELSE, 0);
}


size_t VtParser::IfStmtContext::getRuleIndex() const {
  return VtParser::RuleIfStmt;
}

void VtParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void VtParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


std::any VtParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

VtParser::IfStmtContext* VtParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, VtParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(VtParser::IF);
    setState(60);
    match(VtParser::LPAREN);
    setState(61);
    expr(0);
    setState(62);
    match(VtParser::RPAREN);
    setState(63);
    statement();
    setState(66);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(64);
      match(VtParser::ELSE);
      setState(65);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

VtParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::WhileStmtContext::WHILE() {
  return getToken(VtParser::WHILE, 0);
}

tree::TerminalNode* VtParser::WhileStmtContext::LPAREN() {
  return getToken(VtParser::LPAREN, 0);
}

VtParser::ExprContext* VtParser::WhileStmtContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}

tree::TerminalNode* VtParser::WhileStmtContext::RPAREN() {
  return getToken(VtParser::RPAREN, 0);
}

VtParser::StatementContext* VtParser::WhileStmtContext::statement() {
  return getRuleContext<VtParser::StatementContext>(0);
}


size_t VtParser::WhileStmtContext::getRuleIndex() const {
  return VtParser::RuleWhileStmt;
}

void VtParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void VtParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}


std::any VtParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

VtParser::WhileStmtContext* VtParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 14, VtParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(VtParser::WHILE);
    setState(69);
    match(VtParser::LPAREN);
    setState(70);
    expr(0);
    setState(71);
    match(VtParser::RPAREN);
    setState(72);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

VtParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* VtParser::BlockContext::LBRACE() {
  return getToken(VtParser::LBRACE, 0);
}

tree::TerminalNode* VtParser::BlockContext::RBRACE() {
  return getToken(VtParser::RBRACE, 0);
}

std::vector<VtParser::StatementContext *> VtParser::BlockContext::statement() {
  return getRuleContexts<VtParser::StatementContext>();
}

VtParser::StatementContext* VtParser::BlockContext::statement(size_t i) {
  return getRuleContext<VtParser::StatementContext>(i);
}


size_t VtParser::BlockContext::getRuleIndex() const {
  return VtParser::RuleBlock;
}

void VtParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void VtParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any VtParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

VtParser::BlockContext* VtParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, VtParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(VtParser::LBRACE);
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << VtParser::ID)
      | (1ULL << VtParser::IF)
      | (1ULL << VtParser::WHILE)
      | (1ULL << VtParser::INT)
      | (1ULL << VtParser::STRING)
      | (1ULL << VtParser::PRINT)
      | (1ULL << VtParser::LBRACE))) != 0)) {
      setState(75);
      statement();
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(VtParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

VtParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t VtParser::ExprContext::getRuleIndex() const {
  return VtParser::RuleExpr;
}

void VtParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<VtParser::ExprContext *> VtParser::AndExprContext::expr() {
  return getRuleContexts<VtParser::ExprContext>();
}

VtParser::ExprContext* VtParser::AndExprContext::expr(size_t i) {
  return getRuleContext<VtParser::ExprContext>(i);
}

tree::TerminalNode* VtParser::AndExprContext::AND() {
  return getToken(VtParser::AND, 0);
}

VtParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void VtParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any VtParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* VtParser::StringLiteralContext::STRING_LITERAL() {
  return getToken(VtParser::STRING_LITERAL, 0);
}

VtParser::StringLiteralContext::StringLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}
void VtParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}

std::any VtParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* VtParser::IdExprContext::ID() {
  return getToken(VtParser::ID, 0);
}

VtParser::IdExprContext::IdExprContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::IdExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExpr(this);
}
void VtParser::IdExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExpr(this);
}

std::any VtParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

std::vector<VtParser::ExprContext *> VtParser::MulDivContext::expr() {
  return getRuleContexts<VtParser::ExprContext>();
}

VtParser::ExprContext* VtParser::MulDivContext::expr(size_t i) {
  return getRuleContext<VtParser::ExprContext>(i);
}

tree::TerminalNode* VtParser::MulDivContext::STAR() {
  return getToken(VtParser::STAR, 0);
}

tree::TerminalNode* VtParser::MulDivContext::DIV() {
  return getToken(VtParser::DIV, 0);
}

VtParser::MulDivContext::MulDivContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::MulDivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDiv(this);
}
void VtParser::MulDivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDiv(this);
}

std::any VtParser::MulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitMulDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<VtParser::ExprContext *> VtParser::AddSubContext::expr() {
  return getRuleContexts<VtParser::ExprContext>();
}

VtParser::ExprContext* VtParser::AddSubContext::expr(size_t i) {
  return getRuleContext<VtParser::ExprContext>(i);
}

tree::TerminalNode* VtParser::AddSubContext::PLUS() {
  return getToken(VtParser::PLUS, 0);
}

tree::TerminalNode* VtParser::AddSubContext::MINUS() {
  return getToken(VtParser::MINUS, 0);
}

VtParser::AddSubContext::AddSubContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void VtParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}

std::any VtParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonContext ------------------------------------------------------------------

std::vector<VtParser::ExprContext *> VtParser::ComparisonContext::expr() {
  return getRuleContexts<VtParser::ExprContext>();
}

VtParser::ExprContext* VtParser::ComparisonContext::expr(size_t i) {
  return getRuleContext<VtParser::ExprContext>(i);
}

tree::TerminalNode* VtParser::ComparisonContext::EQEQ() {
  return getToken(VtParser::EQEQ, 0);
}

tree::TerminalNode* VtParser::ComparisonContext::NEQ() {
  return getToken(VtParser::NEQ, 0);
}

tree::TerminalNode* VtParser::ComparisonContext::LT() {
  return getToken(VtParser::LT, 0);
}

tree::TerminalNode* VtParser::ComparisonContext::GT() {
  return getToken(VtParser::GT, 0);
}

tree::TerminalNode* VtParser::ComparisonContext::LE() {
  return getToken(VtParser::LE, 0);
}

tree::TerminalNode* VtParser::ComparisonContext::GE() {
  return getToken(VtParser::GE, 0);
}

VtParser::ComparisonContext::ComparisonContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}
void VtParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

std::any VtParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParensExprContext ------------------------------------------------------------------

tree::TerminalNode* VtParser::ParensExprContext::LPAREN() {
  return getToken(VtParser::LPAREN, 0);
}

VtParser::ExprContext* VtParser::ParensExprContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}

tree::TerminalNode* VtParser::ParensExprContext::RPAREN() {
  return getToken(VtParser::RPAREN, 0);
}

VtParser::ParensExprContext::ParensExprContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::ParensExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParensExpr(this);
}
void VtParser::ParensExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParensExpr(this);
}

std::any VtParser::ParensExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitParensExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* VtParser::IntLiteralContext::INT_LITERAL() {
  return getToken(VtParser::INT_LITERAL, 0);
}

VtParser::IntLiteralContext::IntLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::IntLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntLiteral(this);
}
void VtParser::IntLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntLiteral(this);
}

std::any VtParser::IntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* VtParser::NotExprContext::NOT() {
  return getToken(VtParser::NOT, 0);
}

VtParser::ExprContext* VtParser::NotExprContext::expr() {
  return getRuleContext<VtParser::ExprContext>(0);
}

VtParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void VtParser::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

std::any VtParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<VtParser::ExprContext *> VtParser::OrExprContext::expr() {
  return getRuleContexts<VtParser::ExprContext>();
}

VtParser::ExprContext* VtParser::OrExprContext::expr(size_t i) {
  return getRuleContext<VtParser::ExprContext>(i);
}

tree::TerminalNode* VtParser::OrExprContext::OR() {
  return getToken(VtParser::OR, 0);
}

VtParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void VtParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void VtParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<VtListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any VtParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<VtVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

VtParser::ExprContext* VtParser::expr() {
   return expr(0);
}

VtParser::ExprContext* VtParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  VtParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  VtParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, VtParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case VtParser::NOT: {
        _localctx = _tracker.createInstance<NotExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(84);
        match(VtParser::NOT);
        setState(85);
        expr(5);
        break;
      }

      case VtParser::LPAREN: {
        _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(86);
        match(VtParser::LPAREN);
        setState(87);
        expr(0);
        setState(88);
        match(VtParser::RPAREN);
        break;
      }

      case VtParser::INT_LITERAL: {
        _localctx = _tracker.createInstance<IntLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(90);
        match(VtParser::INT_LITERAL);
        break;
      }

      case VtParser::STRING_LITERAL: {
        _localctx = _tracker.createInstance<StringLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(91);
        match(VtParser::STRING_LITERAL);
        break;
      }

      case VtParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(92);
        match(VtParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(110);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(95);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(96);
          antlrcpp::downCast<MulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == VtParser::STAR

          || _la == VtParser::DIV)) {
            antlrcpp::downCast<MulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(97);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(98);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(99);
          antlrcpp::downCast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == VtParser::PLUS

          || _la == VtParser::MINUS)) {
            antlrcpp::downCast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(100);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ComparisonContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(101);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(102);
          antlrcpp::downCast<ComparisonContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << VtParser::LT)
            | (1ULL << VtParser::GT)
            | (1ULL << VtParser::LE)
            | (1ULL << VtParser::GE)
            | (1ULL << VtParser::EQEQ)
            | (1ULL << VtParser::NEQ))) != 0))) {
            antlrcpp::downCast<ComparisonContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(103);
          expr(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(104);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(105);
          match(VtParser::AND);
          setState(106);
          expr(8);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(107);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(108);
          match(VtParser::OR);
          setState(109);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool VtParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool VtParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void VtParser::initialize() {
  std::call_once(vtParserOnceFlag, vtParserInitialize);
}
