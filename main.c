#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


#include "decl.h"
#include "data.h"
#include "defs.h"

char *tokstr[] = { "+", "-", "*", "/", "intlit" };

int Line = 1;
int Putback = '\n';
FILE *Infile;
FILE *Outfile;
struct token Token;
char Text[TEXTLEN + 1];

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

    if ((Outfile = fopen("out.s", "w")) == NULL) {
        fprintf(stderr, "Unable to create out.s: %s\n", strerror(errno));
        exit(1);
    }

    scan(&Token);
    genpreamble();
    statements();
    genpostamble();
    fclose(Outfile);   
    exit(0);
}
