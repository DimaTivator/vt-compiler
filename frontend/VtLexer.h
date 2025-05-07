
// Generated from Vt.g4 by ANTLR 4.10.1

#pragma once

#include "antlr4-runtime.h"

class VtLexer : public antlr4::Lexer {
public:
    enum {
        INT_KW = 1,
        STRING_KW = 2,
        IF_KW = 3,
        ELSE_KW = 4,
        WHILE_KW = 5,
        PRINT_KW = 6,
        AND_KW = 7,
        OR_KW = 8,
        NOT_KW = 9,
        INT_LITERAL = 10,
        STRING_LITERAL = 11,
        ID = 12,
        EQ = 13,
        SEMI = 14,
        LPAREN = 15,
        RPAREN = 16,
        LBRACE = 17,
        RBRACE = 18,
        PLUS = 19,
        MINUS = 20,
        STAR = 21,
        DIV = 22,
        LT = 23,
        GT = 24,
        LE = 25,
        GE = 26,
        EQEQ = 27,
        NEQ = 28,
        WS = 29,
        LINE_COMMENT = 30,
        BLOCK_COMMENT = 31
    };

    explicit VtLexer(antlr4::CharStream* input);

    ~VtLexer() override;

    std::string getGrammarFileName() const override;

    const std::vector<std::string>& getRuleNames() const override;

    const std::vector<std::string>& getChannelNames() const override;

    const std::vector<std::string>& getModeNames() const override;

    const antlr4::dfa::Vocabulary& getVocabulary() const override;

    antlr4::atn::SerializedATNView getSerializedATN() const override;

    const antlr4::atn::ATN& getATN() const override;

    // By default the static state used to implement the lexer is lazily
    // initialized during the first call to the constructor. You can call this
    // function if you wish to initialize the static state ahead of time.
    static void initialize();

private:
    // Individual action functions triggered by action() above.

    // Individual semantic predicate functions triggered by sempred() above.
};
