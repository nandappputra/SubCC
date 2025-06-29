#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "defs.h"
#include "decl.h"

int genAST(struct ASTnode *n) {
    int leftreg, rightreg;

    if (n->left) leftreg = genAST(n->left);
    if (n->right) rightreg = genAST(n->right);

    switch (n->op) {
        case A_ADD:      return (cgadd(leftreg,rightreg));
        case A_SUBTRACT: return (cgsub(leftreg,rightreg));
        case A_MULTIPLY: return (cgmul(leftreg,rightreg));
        case A_DIVIDE:   return (cgdiv(leftreg,rightreg));
        case A_INTLIT:   return (cgload(n->intValue));

        default:
        fprintf(stderr, "Unknown AST operator %d\n", n->op);
        exit(1);
    }
}

void generatecode(struct ASTnode *n) {
    int reg;

    cgpreamble();
    reg= genAST(n);
    cgprintint(reg);
    cgpostamble();
}

void genpreamble()        { cgpreamble(); }
void genpostamble()       { cgpostamble(); }
void genfreeregs()        { freeall_registers(); }
void genprintint(int reg) { cgprintint(reg); }
