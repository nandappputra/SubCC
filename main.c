#include "scan.c"

char *tokstr[] = { "+", "-", "*", "/", "intlit" };

int Line;
int Putback;
FILE *Infile;

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
    Infile = fopen(argv[1], "r");

    scan_file();

    exit(0);
}
