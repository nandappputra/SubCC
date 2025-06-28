#ifndef DEFS_H
#define DEFS_H

struct token {
    int token;
    int intValue;
};

enum {
    T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_SEMI, T_PRINT
};

struct ASTnode {
    int op;
    struct ASTnode* left;
    struct ASTnode* right;
    int intValue;
};

enum {
    A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT
};

#endif
