#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "pessoa.h"

typedef struct tree Tree;

Tree * criaTree(char * nome);

Tree * insereTree(Tree * tree, char * nome);

void printSortedTree(Tree * tree);

void freeTree(Tree * tree);

void readFrequencyFile(Tree * tree, FILE * file);


#endif