#include <stdio.h>
#include <stdlib.h>

#include "decl.h"
#include "data.h"
#include "defs.h"

char *tokstr[] = { "+", "-", "*", "/", "intlit" };

int Line = 1;
int Putback = '\n';
FILE *Infile;
struct token Token;

static void scan_file(void) {
    struct token T;
    
    while (scan(&T))
    {
        printf("Token %s", tokstr[T.token]);

        if (T.token == T_INTLIT) {
            printf(", value %d", T.intValue);
        }

        printf("\n");
    }
} 

void main(int argc, char *argv[]) {
    struct ASTnode* n;
    Infile = fopen(argv[1], "r");

    // scan_file();

    scan(&Token);
    n = binexpr();
    printf("%d\n", interpretAST(n));

    exit(0);
}
