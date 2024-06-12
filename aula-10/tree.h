#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "aluno.h"

typedef struct tree Tree;

Tree *createTreeEmpty();

Tree *createTree(Aluno *aluno, Tree *right, Tree *left);

void printTree(Tree *tree);

Tree* freeTree(Tree *tree);

int thereIs(Tree *tree, Aluno *aluno);

int emptyTree(Tree *tree);

int leafs(Tree *tree);

int frequency(Tree *tree, char *nome);

int height(Tree *tree);


#endif