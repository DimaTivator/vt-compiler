
// Generated from Vt.g4 by ANTLR 4.10.1


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
      "T__0", "T__1", "INT_KW", "STRING_KW", "IF_KW", "ELSE_KW", "WHILE_KW", 
      "PRINT_KW", "AND_KW", "OR_KW", "NOT_KW", "INT_LITERAL", "STRING_LITERAL", 
      "ID", "EQ", "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "PLUS", 
      "MINUS", "STAR", "DIV", "LT", "GT", "LE", "GE", "EQEQ", "NEQ", "WS", 
      "LINE_COMMENT", "BLOCK_COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'prints'", "'printi'", "'int'", "'string'", "'if'", "'else'", 
      "'while'", "'print'", "'and'", "'or'", "'not'", "", "", "", "'='", 
      "';'", "'('", "')'", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'", "'<'", 
      "'>'", "'<='", "'>='", "'=='", "'!='"
    },
    std::vector<std::string>{
      "", "", "", "INT_KW", "STRING_KW", "IF_KW", "ELSE_KW", "WHILE_KW", 
      "PRINT_KW", "AND_KW", "OR_KW", "NOT_KW", "INT_LITERAL", "STRING_LITERAL", 
      "ID", "EQ", "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "PLUS", 
      "MINUS", "STAR", "DIV", "LT", "GT", "LE", "GE", "EQEQ", "NEQ", "WS", 
      "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,33,214,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,11,
  	4,11,125,8,11,11,11,12,11,126,1,12,1,12,1,12,1,12,5,12,133,8,12,10,12,
  	12,12,136,9,12,1,12,1,12,1,13,1,13,5,13,142,8,13,10,13,12,13,145,9,13,
  	1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,
  	1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,27,
  	1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,4,30,184,8,30,11,30,12,30,
  	185,1,30,1,30,1,31,1,31,1,31,1,31,5,31,194,8,31,10,31,12,31,197,9,31,
  	1,31,1,31,1,32,1,32,1,32,1,32,5,32,205,8,32,10,32,12,32,208,9,32,1,32,
  	1,32,1,32,1,32,1,32,1,206,0,33,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,
  	65,33,1,0,6,1,0,48,57,4,0,10,10,13,13,34,34,92,92,3,0,65,90,95,95,97,
  	122,4,0,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,2,0,10,10,13,13,
  	220,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,
  	1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,
  	0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,
  	0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,
  	1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,
  	0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,
  	0,65,1,0,0,0,1,67,1,0,0,0,3,74,1,0,0,0,5,81,1,0,0,0,7,85,1,0,0,0,9,92,
  	1,0,0,0,11,95,1,0,0,0,13,100,1,0,0,0,15,106,1,0,0,0,17,112,1,0,0,0,19,
  	116,1,0,0,0,21,119,1,0,0,0,23,124,1,0,0,0,25,128,1,0,0,0,27,139,1,0,0,
  	0,29,146,1,0,0,0,31,148,1,0,0,0,33,150,1,0,0,0,35,152,1,0,0,0,37,154,
  	1,0,0,0,39,156,1,0,0,0,41,158,1,0,0,0,43,160,1,0,0,0,45,162,1,0,0,0,47,
  	164,1,0,0,0,49,166,1,0,0,0,51,168,1,0,0,0,53,170,1,0,0,0,55,173,1,0,0,
  	0,57,176,1,0,0,0,59,179,1,0,0,0,61,183,1,0,0,0,63,189,1,0,0,0,65,200,
  	1,0,0,0,67,68,5,112,0,0,68,69,5,114,0,0,69,70,5,105,0,0,70,71,5,110,0,
  	0,71,72,5,116,0,0,72,73,5,115,0,0,73,2,1,0,0,0,74,75,5,112,0,0,75,76,
  	5,114,0,0,76,77,5,105,0,0,77,78,5,110,0,0,78,79,5,116,0,0,79,80,5,105,
  	0,0,80,4,1,0,0,0,81,82,5,105,0,0,82,83,5,110,0,0,83,84,5,116,0,0,84,6,
  	1,0,0,0,85,86,5,115,0,0,86,87,5,116,0,0,87,88,5,114,0,0,88,89,5,105,0,
  	0,89,90,5,110,0,0,90,91,5,103,0,0,91,8,1,0,0,0,92,93,5,105,0,0,93,94,
  	5,102,0,0,94,10,1,0,0,0,95,96,5,101,0,0,96,97,5,108,0,0,97,98,5,115,0,
  	0,98,99,5,101,0,0,99,12,1,0,0,0,100,101,5,119,0,0,101,102,5,104,0,0,102,
  	103,5,105,0,0,103,104,5,108,0,0,104,105,5,101,0,0,105,14,1,0,0,0,106,
  	107,5,112,0,0,107,108,5,114,0,0,108,109,5,105,0,0,109,110,5,110,0,0,110,
  	111,5,116,0,0,111,16,1,0,0,0,112,113,5,97,0,0,113,114,5,110,0,0,114,115,
  	5,100,0,0,115,18,1,0,0,0,116,117,5,111,0,0,117,118,5,114,0,0,118,20,1,
  	0,0,0,119,120,5,110,0,0,120,121,5,111,0,0,121,122,5,116,0,0,122,22,1,
  	0,0,0,123,125,7,0,0,0,124,123,1,0,0,0,125,126,1,0,0,0,126,124,1,0,0,0,
  	126,127,1,0,0,0,127,24,1,0,0,0,128,134,5,34,0,0,129,133,8,1,0,0,130,131,
  	5,92,0,0,131,133,9,0,0,0,132,129,1,0,0,0,132,130,1,0,0,0,133,136,1,0,
  	0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,137,1,0,0,0,136,134,1,0,0,0,137,
  	138,5,34,0,0,138,26,1,0,0,0,139,143,7,2,0,0,140,142,7,3,0,0,141,140,1,
  	0,0,0,142,145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,28,1,0,0,0,
  	145,143,1,0,0,0,146,147,5,61,0,0,147,30,1,0,0,0,148,149,5,59,0,0,149,
  	32,1,0,0,0,150,151,5,40,0,0,151,34,1,0,0,0,152,153,5,41,0,0,153,36,1,
  	0,0,0,154,155,5,123,0,0,155,38,1,0,0,0,156,157,5,125,0,0,157,40,1,0,0,
  	0,158,159,5,43,0,0,159,42,1,0,0,0,160,161,5,45,0,0,161,44,1,0,0,0,162,
  	163,5,42,0,0,163,46,1,0,0,0,164,165,5,47,0,0,165,48,1,0,0,0,166,167,5,
  	60,0,0,167,50,1,0,0,0,168,169,5,62,0,0,169,52,1,0,0,0,170,171,5,60,0,
  	0,171,172,5,61,0,0,172,54,1,0,0,0,173,174,5,62,0,0,174,175,5,61,0,0,175,
  	56,1,0,0,0,176,177,5,61,0,0,177,178,5,61,0,0,178,58,1,0,0,0,179,180,5,
  	33,0,0,180,181,5,61,0,0,181,60,1,0,0,0,182,184,7,4,0,0,183,182,1,0,0,
  	0,184,185,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,187,1,0,0,0,187,
  	188,6,30,0,0,188,62,1,0,0,0,189,190,5,47,0,0,190,191,5,47,0,0,191,195,
  	1,0,0,0,192,194,8,5,0,0,193,192,1,0,0,0,194,197,1,0,0,0,195,193,1,0,0,
  	0,195,196,1,0,0,0,196,198,1,0,0,0,197,195,1,0,0,0,198,199,6,31,0,0,199,
  	64,1,0,0,0,200,201,5,47,0,0,201,202,5,42,0,0,202,206,1,0,0,0,203,205,
  	9,0,0,0,204,203,1,0,0,0,205,208,1,0,0,0,206,207,1,0,0,0,206,204,1,0,0,
  	0,207,209,1,0,0,0,208,206,1,0,0,0,209,210,5,42,0,0,210,211,5,47,0,0,211,
  	212,1,0,0,0,212,213,6,32,0,0,213,66,1,0,0,0,8,0,126,132,134,143,185,195,
  	206,1,6,0,0
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
