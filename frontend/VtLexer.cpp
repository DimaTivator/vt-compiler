
// Generated from ../Vt.g4 by ANTLR 4.10.1


#include "VtLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct VtLexerStaticData final {
  VtLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VtLexerStaticData(const VtLexerStaticData&) = delete;
  VtLexerStaticData(VtLexerStaticData&&) = delete;
  VtLexerStaticData& operator=(const VtLexerStaticData&) = delete;
  VtLexerStaticData& operator=(VtLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag vtlexerLexerOnceFlag;
VtLexerStaticData *vtlexerLexerStaticData = nullptr;

void vtlexerLexerInitialize() {
  assert(vtlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<VtLexerStaticData>(
    std::vector<std::string>{
      "INT_KW", "STRING_KW", "IF_KW", "ELSE_KW", "WHILE_KW", "PRINT_KW", 
      "AND_KW", "OR_KW", "NOT_KW", "INT_LITERAL", "STRING_LITERAL", "ID", 
      "EQ", "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "PLUS", "MINUS", 
      "STAR", "DIV", "LT", "GT", "LE", "GE", "EQEQ", "NEQ", "WS", "LINE_COMMENT", 
      "BLOCK_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'string'", "'if'", "'else'", "'while'", "'print'", "'and'", 
      "'or'", "'not'", "", "", "", "'='", "';'", "'('", "')'", "'{'", "'}'", 
      "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'<='", "'>='", "'=='", 
      "'!='"
    },
    std::vector<std::string>{
      "", "INT_KW", "STRING_KW", "IF_KW", "ELSE_KW", "WHILE_KW", "PRINT_KW", 
      "AND_KW", "OR_KW", "NOT_KW", "INT_LITERAL", "STRING_LITERAL", "ID", 
      "EQ", "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "PLUS", "MINUS", 
      "STAR", "DIV", "LT", "GT", "LE", "GE", "EQEQ", "NEQ", "WS", "LINE_COMMENT", 
      "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,31,196,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,4,9,107,8,9,
  	11,9,12,9,108,1,10,1,10,1,10,1,10,5,10,115,8,10,10,10,12,10,118,9,10,
  	1,10,1,10,1,11,1,11,5,11,124,8,11,10,11,12,11,127,9,11,1,12,1,12,1,13,
  	1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,26,
  	1,26,1,26,1,27,1,27,1,27,1,28,4,28,166,8,28,11,28,12,28,167,1,28,1,28,
  	1,29,1,29,1,29,1,29,5,29,176,8,29,10,29,12,29,179,9,29,1,29,1,29,1,30,
  	1,30,1,30,1,30,5,30,187,8,30,10,30,12,30,190,9,30,1,30,1,30,1,30,1,30,
  	1,30,1,188,0,31,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,
  	12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,
  	47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,1,0,6,1,0,48,57,4,0,10,
  	10,13,13,34,34,92,92,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,
  	122,3,0,9,10,13,13,32,32,2,0,10,10,13,13,202,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,
  	0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,
  	0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,
  	37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,
  	0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,
  	0,0,59,1,0,0,0,0,61,1,0,0,0,1,63,1,0,0,0,3,67,1,0,0,0,5,74,1,0,0,0,7,
  	77,1,0,0,0,9,82,1,0,0,0,11,88,1,0,0,0,13,94,1,0,0,0,15,98,1,0,0,0,17,
  	101,1,0,0,0,19,106,1,0,0,0,21,110,1,0,0,0,23,121,1,0,0,0,25,128,1,0,0,
  	0,27,130,1,0,0,0,29,132,1,0,0,0,31,134,1,0,0,0,33,136,1,0,0,0,35,138,
  	1,0,0,0,37,140,1,0,0,0,39,142,1,0,0,0,41,144,1,0,0,0,43,146,1,0,0,0,45,
  	148,1,0,0,0,47,150,1,0,0,0,49,152,1,0,0,0,51,155,1,0,0,0,53,158,1,0,0,
  	0,55,161,1,0,0,0,57,165,1,0,0,0,59,171,1,0,0,0,61,182,1,0,0,0,63,64,5,
  	105,0,0,64,65,5,110,0,0,65,66,5,116,0,0,66,2,1,0,0,0,67,68,5,115,0,0,
  	68,69,5,116,0,0,69,70,5,114,0,0,70,71,5,105,0,0,71,72,5,110,0,0,72,73,
  	5,103,0,0,73,4,1,0,0,0,74,75,5,105,0,0,75,76,5,102,0,0,76,6,1,0,0,0,77,
  	78,5,101,0,0,78,79,5,108,0,0,79,80,5,115,0,0,80,81,5,101,0,0,81,8,1,0,
  	0,0,82,83,5,119,0,0,83,84,5,104,0,0,84,85,5,105,0,0,85,86,5,108,0,0,86,
  	87,5,101,0,0,87,10,1,0,0,0,88,89,5,112,0,0,89,90,5,114,0,0,90,91,5,105,
  	0,0,91,92,5,110,0,0,92,93,5,116,0,0,93,12,1,0,0,0,94,95,5,97,0,0,95,96,
  	5,110,0,0,96,97,5,100,0,0,97,14,1,0,0,0,98,99,5,111,0,0,99,100,5,114,
  	0,0,100,16,1,0,0,0,101,102,5,110,0,0,102,103,5,111,0,0,103,104,5,116,
  	0,0,104,18,1,0,0,0,105,107,7,0,0,0,106,105,1,0,0,0,107,108,1,0,0,0,108,
  	106,1,0,0,0,108,109,1,0,0,0,109,20,1,0,0,0,110,116,5,34,0,0,111,115,8,
  	1,0,0,112,113,5,92,0,0,113,115,9,0,0,0,114,111,1,0,0,0,114,112,1,0,0,
  	0,115,118,1,0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,119,1,0,0,0,118,
  	116,1,0,0,0,119,120,5,34,0,0,120,22,1,0,0,0,121,125,7,2,0,0,122,124,7,
  	3,0,0,123,122,1,0,0,0,124,127,1,0,0,0,125,123,1,0,0,0,125,126,1,0,0,0,
  	126,24,1,0,0,0,127,125,1,0,0,0,128,129,5,61,0,0,129,26,1,0,0,0,130,131,
  	5,59,0,0,131,28,1,0,0,0,132,133,5,40,0,0,133,30,1,0,0,0,134,135,5,41,
  	0,0,135,32,1,0,0,0,136,137,5,123,0,0,137,34,1,0,0,0,138,139,5,125,0,0,
  	139,36,1,0,0,0,140,141,5,43,0,0,141,38,1,0,0,0,142,143,5,45,0,0,143,40,
  	1,0,0,0,144,145,5,42,0,0,145,42,1,0,0,0,146,147,5,47,0,0,147,44,1,0,0,
  	0,148,149,5,60,0,0,149,46,1,0,0,0,150,151,5,62,0,0,151,48,1,0,0,0,152,
  	153,5,60,0,0,153,154,5,61,0,0,154,50,1,0,0,0,155,156,5,62,0,0,156,157,
  	5,61,0,0,157,52,1,0,0,0,158,159,5,61,0,0,159,160,5,61,0,0,160,54,1,0,
  	0,0,161,162,5,33,0,0,162,163,5,61,0,0,163,56,1,0,0,0,164,166,7,4,0,0,
  	165,164,1,0,0,0,166,167,1,0,0,0,167,165,1,0,0,0,167,168,1,0,0,0,168,169,
  	1,0,0,0,169,170,6,28,0,0,170,58,1,0,0,0,171,172,5,47,0,0,172,173,5,47,
  	0,0,173,177,1,0,0,0,174,176,8,5,0,0,175,174,1,0,0,0,176,179,1,0,0,0,177,
  	175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,0,180,181,6,
  	29,0,0,181,60,1,0,0,0,182,183,5,47,0,0,183,184,5,42,0,0,184,188,1,0,0,
  	0,185,187,9,0,0,0,186,185,1,0,0,0,187,190,1,0,0,0,188,189,1,0,0,0,188,
  	186,1,0,0,0,189,191,1,0,0,0,190,188,1,0,0,0,191,192,5,42,0,0,192,193,
  	5,47,0,0,193,194,1,0,0,0,194,195,6,30,0,0,195,62,1,0,0,0,8,0,108,114,
  	116,125,167,177,188,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  vtlexerLexerStaticData = staticData.release();
}

}

VtLexer::VtLexer(CharStream *input) : Lexer(input) {
  VtLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *vtlexerLexerStaticData->atn, vtlexerLexerStaticData->decisionToDFA, vtlexerLexerStaticData->sharedContextCache);
}

VtLexer::~VtLexer() {
  delete _interpreter;
}

std::string VtLexer::getGrammarFileName() const {
  return "Vt.g4";
}

const std::vector<std::string>& VtLexer::getRuleNames() const {
  return vtlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& VtLexer::getChannelNames() const {
  return vtlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& VtLexer::getModeNames() const {
  return vtlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& VtLexer::getVocabulary() const {
  return vtlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView VtLexer::getSerializedATN() const {
  return vtlexerLexerStaticData->serializedATN;
}

const atn::ATN& VtLexer::getATN() const {
  return *vtlexerLexerStaticData->atn;
}




void VtLexer::initialize() {
  std::call_once(vtlexerLexerOnceFlag, vtlexerLexerInitialize);
}
