#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "aluno.h"

typedef struct tree Tree;

Tree *createTree(Aluno *aluno);

Tree *insertTree(Tree *tree, Aluno *aluno);

Tree *removeTree(Tree *tree, int mat);

void printTree(Tree *tree);

Tree* freeTree(Tree *tree);

int search(Tree *tree, Aluno *aluno);



#endif