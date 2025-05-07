grammar Vt;

options { language = Cpp; }

// Parser rules
program
    : statement* EOF
    ;

statement
    : varDecl ';'
    | assignment ';'
    | printStmt ';'
    | ifStmt
    | whileStmt
    | block
    ;

varDecl
    : type ID ('=' expr)?
    ;

type
    : 'int'
    | 'string'
    ;

assignment
    : ID '=' expr
    ;

printStmt
    : 'print' '(' expr ')'
    ;

ifStmt
    : 'if' '(' expr ')' statement ('else' statement)?
    ;

whileStmt
    : 'while' '(' expr ')' statement
    ;

block
    : '{' statement* '}'
    ;

expr
    : expr op=('*'|'/') expr        # MulDiv
    | expr op=('+'|'-') expr        # AddSub
    | expr op=('==' | '!=' | '<' | '>' | '<=' | '>=') expr  # Comparison
    | expr 'and' expr                # AndExpr
    | expr 'or' expr                 # OrExpr
    | 'not' expr                     # NotExpr
    | '(' expr ')'                   # ParensExpr
    | INT_LITERAL                    # IntLiteral
    | STRING_LITERAL                 # StringLiteral
    | ID                             # IdExpr
    ;

// Lexer rules
INT_LITERAL
    : [0-9]+
    ;

STRING_LITERAL
    : '"' (~["\\\r\n] | '\\' .)* '"'
    ;

ID
    : [a-zA-Z_] [a-zA-Z_0-9]*
    ;

// Keywords
IF      : 'if';
ELSE    : 'else';
WHILE   : 'while';
INT     : 'int';
STRING  : 'string';
PRINT   : 'print';
AND     : 'and';
OR      : 'or';
NOT     : 'not';

// Operators and punctuation
EQ      : '=';
SEMI    : ';';
LPAREN  : '(';
RPAREN  : ')';
LBRACE  : '{';
RBRACE  : '}';
PLUS    : '+';
MINUS   : '-';
STAR    : '*';
DIV     : '/';
LT      : '<';
GT      : '>';
LE      : '<=';
GE      : '>=';
EQEQ    : '==';
NEQ     : '!=';

// Whitespace and comments
WS
    : [ \t\r\n]+ -> skip
    ;

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
    ;

BLOCK_COMMENT
    : '/*' .*? '*/' -> skip
    ;
