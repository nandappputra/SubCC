#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include "defs.h"

#define TEXTLEN 512

extern int Line;
extern int Putback;
extern FILE *Infile;
extern FILE *Outfile;
extern struct token Token;
extern char Text[TEXTLEN + 1];

#endif
