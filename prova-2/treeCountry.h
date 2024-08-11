#ifndef treecountry_h
#define treecountry_h

#include <stdio.h>
#include "country.h"

typedef struct tree Tree;

Tree *criaTree(char *nome, int ouro, int prata, int bronze);

Tree *insereTree(Tree *tree, char *nome, int ouro, int prata, int bronze);

Tree * removeTree(Tree * tree, char * nome);

void criaRankTree(Tree * tree);

void freeTree(Tree *tree);

#endif