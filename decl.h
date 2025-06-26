#ifndef DECL_H
#define DECL_H

#include "defs.h"

int scan(struct token *t);
struct ASTnode* make_ast_node(int op, struct ASTnode* left, struct ASTnode* right, int intValue);
struct ASTnode* make_ast_leaf(int op, int intValue);
struct ASTnode* make_ast_unary(int op, struct ASTnode* left, int intValue);
int interpretAST(struct ASTnode *n);
struct ASTnode* binexpr(void);

#endif
