#include <stdlib.h>

#include "decl.h"
#include "data.h"
#include "defs.h"

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

struct ASTnode* multiplicative_expression(void) {
    struct ASTnode* left, *right;
    int tokenType;

    left = primary();
    tokenType = Token.token;

    if (tokenType == T_EOF) {
        return left;
    }

    while (tokenType == T_STAR || tokenType == T_SLASH) {
        scan(&Token);

        right = multiplicative_expression();

        left = make_ast_node(arithop(tokenType), left, right, 0);

        tokenType = Token.token;

        if (tokenType == T_EOF) {
            return left;
        }
    }

    return left;
}

struct ASTnode* additive_expression(void) {
    struct ASTnode* left, *right;
    int tokenType;

    left = multiplicative_expression();
    tokenType = Token.token;

    if (tokenType == T_EOF) {
        return left;
    }

    
    while (tokenType == T_PLUS || tokenType == T_MINUS  ) {
        scan(&Token);

        right = multiplicative_expression();

        left = make_ast_node(arithop(tokenType), left, right, 0);

        tokenType = Token.token;

        if (tokenType == T_EOF) {
            return left;
        }
    }

    return left;
}

struct ASTnode* binexpr(int inp) {
    return additive_expression();
}
