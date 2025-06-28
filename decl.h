#ifndef DECL_H
#define DECL_H

#include "defs.h"

int scan(struct token *t);

struct ASTnode* make_ast_node(int op, struct ASTnode* left, struct ASTnode* right, int intValue);
struct ASTnode* make_ast_leaf(int op, int intValue);
struct ASTnode* make_ast_unary(int op, struct ASTnode* left, int intValue);
struct ASTnode* binexpr(int inp);

int interpretAST(struct ASTnode *n);
void generatecode(struct ASTnode *n);

void freeall_registers(void);
void cgpreamble();
void cgpostamble();
int cgload(int value);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);

void match(int t, char *what);
void semi(void);

void genpreamble(void);
void genpostamble(void);
void genfreeregs(void);
void genprintint(int reg);

int genAST(struct ASTnode *n);

void statements();

#endif
