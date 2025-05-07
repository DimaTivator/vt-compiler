grammar Vt;

options { language = Cpp; }

// ---------------Parser rules---------------

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
    : type ID '=' expr
    ;

type
    : 'int'
    | 'string'
    ;

assignment
    : ID '=' expr
    ;

printStmt
    : 'print' expr
    ;

ifStmt
    : 'if' '(' expr ')' block ('else' block)?
    ;

whileStmt
    : 'while' '(' expr ')' block
    ;

block
    : '{' statement* '}'
    ;

expr
    : expr op=('*'|'/') expr              # MulDiv
    | expr op=('+'|'-') expr              # AddSub
    | expr op=('<=' | '>=' | '==' | '!=' | '<' | '>') expr  # Comparison
    | expr 'and' expr                     # AndExpr
    | expr 'or' expr                      # OrExpr
    | 'not' expr                          # NotExpr
    | '(' expr ')'                        # ParensExpr
    | INT_LITERAL                         # IntLiteral
    | STRING_LITERAL                      # StringLiteral
    | ID                                  # IdExpr
    ;

// ---------------Lexer rules---------------

// Keywords
INT_KW      : 'int';
STRING_KW   : 'string';
IF_KW       : 'if';
ELSE_KW     : 'else';
WHILE_KW    : 'while';
PRINT_KW    : 'print';
AND_KW      : 'and';
OR_KW       : 'or';
NOT_KW      : 'not';

INT_LITERAL
    : [0-9]+
    ;

STRING_LITERAL
    : '"' (~["\\\r\n] | '\\' .)* '"'
    ;

ID
    : [a-zA-Z_] [a-zA-Z_0-9]*
    ;

// Operators and delimiters
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

// Whitespaces and comments
WS
    : [ \t\r\n]+ -> skip
    ;

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
    ;

BLOCK_COMMENT
    : '/*' .*? '*/' -> skip
    ;
