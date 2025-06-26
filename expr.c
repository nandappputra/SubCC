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

struct ASTnode* binexpr(void) {
    struct ASTnode* n, *left, *right;
    int nodetype;

    left = primary();
    if (Token.token == T_EOF) {
        return (left);
    }

    nodetype = arithop(Token.token);

    scan(&Token);

    right = binexpr();

    n = make_ast_node(nodetype, left, right, 0);

    return (n);
}
