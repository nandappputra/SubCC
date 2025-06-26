#include <stdlib.h>
#include <stdio.h>

#include "decl.h"
#include "defs.h"
#include "data.h"

struct ASTnode* make_ast_node(int op, struct ASTnode* left, struct ASTnode* right, int intValue)
{
    struct ASTnode *n;

    n = (struct ASTnode*) malloc(sizeof(struct ASTnode));
    if (n == NULL) {
        fprintf(stderr, "Unable to malloc in make_ast_node");
        exit(1);
    }

    n->op = op;
    n->left = left;
    n->right = right;
    n->intValue = intValue;

    return (n);
};

struct ASTnode* make_ast_leaf(int op, int intValue) 
{
    return (make_ast_node(op, NULL, NULL, intValue));
}

struct ASTnode* make_ast_unary(int op, struct ASTnode* left, int intValue) 
{
    return (make_ast_node(op, left, NULL, intValue));
}
