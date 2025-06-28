#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "defs.h"
#include "decl.h"

static struct ASTnode *primary(void) {
    struct ASTnode *n;

    switch (Token.token) {
        case T_INTLIT:
            n = make_ast_leaf(A_INTLIT, Token.intValue);
            scan(&Token);
            return (n);
        default:
            fprintf(stderr, "syntax error on line %d\n", Line);
            exit(1);
    }
}

int arithop(int tok) {
    switch (tok)
    {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            fprintf(stderr, "unknown token in arithop() on line %d\n", Line);
            exit(1);
    }
}

//                      EOF +   -   *   /  I
static int OpPrec[] = { 0, 10, 10, 20, 20, 0 };

static int operator_precedence(int tokenType) {
    int prec = OpPrec[tokenType];

    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokenType);
        exit(1);
    }

    return prec;
}


struct ASTnode* binexpr(int inp) {
    struct ASTnode *left, *right;
    int tokenType;

    left = primary();
    tokenType = Token.token;

    if (tokenType == T_SEMI) {
        return (left);
    }

    while (operator_precedence(tokenType) > inp)
    {
        scan(&Token);
        
        right = binexpr(OpPrec[tokenType]);

        left = make_ast_node(arithop(tokenType), left, right, 0);

        tokenType = Token.token;
        if (tokenType == T_SEMI) {
            return (left);
        }
    }

    return left;
}
