
// Generated from Vt.g4 by ANTLR 4.10.1

#pragma once

#include "antlr4-runtime.h"

class VtParser : public antlr4::Parser {
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

    enum {
        RuleProgram = 0,
        RuleStatement = 1,
        RuleVarDecl = 2,
        RuleType = 3,
        RuleAssignment = 4,
        RulePrintStmt = 5,
        RuleIfStmt = 6,
        RuleWhileStmt = 7,
        RuleBlock = 8,
        RuleExpr = 9
    };

    explicit VtParser(antlr4::TokenStream* input);

    VtParser(antlr4::TokenStream* input,
             const antlr4::atn::ParserATNSimulatorOptions& options);

    ~VtParser() override;

    std::string getGrammarFileName() const override;

    const antlr4::atn::ATN& getATN() const override;

    const std::vector<std::string>& getRuleNames() const override;

    const antlr4::dfa::Vocabulary& getVocabulary() const override;

    antlr4::atn::SerializedATNView getSerializedATN() const override;

    class ProgramContext;
    class StatementContext;
    class VarDeclContext;
    class TypeContext;
    class AssignmentContext;
    class PrintStmtContext;
    class IfStmtContext;
    class WhileStmtContext;
    class BlockContext;
    class ExprContext;

    class ProgramContext : public antlr4::ParserRuleContext {
    public:
        ProgramContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EOF();
        std::vector<StatementContext*> statement();
        StatementContext* statement(size_t i);

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ProgramContext* program();

    class StatementContext : public antlr4::ParserRuleContext {
    public:
        StatementContext(antlr4::ParserRuleContext* parent,
                         size_t invokingState);
        virtual size_t getRuleIndex() const override;
        VarDeclContext* varDecl();
        antlr4::tree::TerminalNode* SEMI();
        AssignmentContext* assignment();
        PrintStmtContext* printStmt();
        IfStmtContext* ifStmt();
        WhileStmtContext* whileStmt();
        BlockContext* block();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StatementContext* statement();

    class VarDeclContext : public antlr4::ParserRuleContext {
    public:
        VarDeclContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        TypeContext* type();
        antlr4::tree::TerminalNode* ID();
        antlr4::tree::TerminalNode* EQ();
        ExprContext* expr();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    VarDeclContext* varDecl();

    class TypeContext : public antlr4::ParserRuleContext {
    public:
        TypeContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* INT_KW();
        antlr4::tree::TerminalNode* STRING_KW();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TypeContext* type();

    class AssignmentContext : public antlr4::ParserRuleContext {
    public:
        AssignmentContext(antlr4::ParserRuleContext* parent,
                          size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ID();
        antlr4::tree::TerminalNode* EQ();
        ExprContext* expr();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AssignmentContext* assignment();

    class PrintStmtContext : public antlr4::ParserRuleContext {
    public:
        PrintStmtContext(antlr4::ParserRuleContext* parent,
                         size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PRINT_KW();
        ExprContext* expr();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PrintStmtContext* printStmt();

    class IfStmtContext : public antlr4::ParserRuleContext {
    public:
        IfStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IF_KW();
        antlr4::tree::TerminalNode* LPAREN();
        ExprContext* expr();
        antlr4::tree::TerminalNode* RPAREN();
        std::vector<BlockContext*> block();
        BlockContext* block(size_t i);
        antlr4::tree::TerminalNode* ELSE_KW();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IfStmtContext* ifStmt();

    class WhileStmtContext : public antlr4::ParserRuleContext {
    public:
        WhileStmtContext(antlr4::ParserRuleContext* parent,
                         size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* WHILE_KW();
        antlr4::tree::TerminalNode* LPAREN();
        ExprContext* expr();
        antlr4::tree::TerminalNode* RPAREN();
        BlockContext* block();

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WhileStmtContext* whileStmt();

    class BlockContext : public antlr4::ParserRuleContext {
    public:
        BlockContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LBRACE();
        antlr4::tree::TerminalNode* RBRACE();
        std::vector<StatementContext*> statement();
        StatementContext* statement(size_t i);

        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BlockContext* block();

    class ExprContext : public antlr4::ParserRuleContext {
    public:
        ExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        ExprContext() = default;
        void copyFrom(ExprContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class AndExprContext : public ExprContext {
    public:
        AndExprContext(ExprContext* ctx);

        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        antlr4::tree::TerminalNode* AND_KW();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class StringLiteralContext : public ExprContext {
    public:
        StringLiteralContext(ExprContext* ctx);

        antlr4::tree::TerminalNode* STRING_LITERAL();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IdExprContext : public ExprContext {
    public:
        IdExprContext(ExprContext* ctx);

        antlr4::tree::TerminalNode* ID();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MulDivContext : public ExprContext {
    public:
        MulDivContext(ExprContext* ctx);

        antlr4::Token* op = nullptr;
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        antlr4::tree::TerminalNode* STAR();
        antlr4::tree::TerminalNode* DIV();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AddSubContext : public ExprContext {
    public:
        AddSubContext(ExprContext* ctx);

        antlr4::Token* op = nullptr;
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        antlr4::tree::TerminalNode* PLUS();
        antlr4::tree::TerminalNode* MINUS();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ComparisonContext : public ExprContext {
    public:
        ComparisonContext(ExprContext* ctx);

        antlr4::Token* op = nullptr;
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        antlr4::tree::TerminalNode* LE();
        antlr4::tree::TerminalNode* GE();
        antlr4::tree::TerminalNode* EQEQ();
        antlr4::tree::TerminalNode* NEQ();
        antlr4::tree::TerminalNode* LT();
        antlr4::tree::TerminalNode* GT();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class NegExprContext : public ExprContext {
    public:
        NegExprContext(ExprContext* ctx);

        antlr4::tree::TerminalNode* MINUS();
        ExprContext* expr();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ParensExprContext : public ExprContext {
    public:
        ParensExprContext(ExprContext* ctx);

        antlr4::tree::TerminalNode* LPAREN();
        ExprContext* expr();
        antlr4::tree::TerminalNode* RPAREN();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IntLiteralContext : public ExprContext {
    public:
        IntLiteralContext(ExprContext* ctx);

        antlr4::tree::TerminalNode* INT_LITERAL();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class NotExprContext : public ExprContext {
    public:
        NotExprContext(ExprContext* ctx);

        antlr4::tree::TerminalNode* NOT_KW();
        ExprContext* expr();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class OrExprContext : public ExprContext {
    public:
        OrExprContext(ExprContext* ctx);

        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        antlr4::tree::TerminalNode* OR_KW();
        virtual void enterRule(
            antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(
            antlr4::tree::ParseTreeListener* listener) override;

        virtual std::any accept(
            antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprContext* expr();
    ExprContext* expr(int precedence);

    bool sempred(antlr4::RuleContext* _localctx, size_t ruleIndex,
                 size_t predicateIndex) override;

    bool exprSempred(ExprContext* _localctx, size_t predicateIndex);

    // By default the static state used to implement the parser is lazily
    // initialized during the first call to the constructor. You can call this
    // function if you wish to initialize the static state ahead of time.
    static void initialize();

private:
};
