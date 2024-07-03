#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "aluno.h"

typedef struct tree Tree;

Tree* createTree(void *info, void (*imprime)(void*), int (*compara)(void*, void*));

void printTree(Tree *tree);

Tree* freeTree(Tree *tree);

Tree *insertTree(Tree *tree, void *info, void (*imprime)(void*), int (*compara)(void*, void*));

int search(Tree *tree, void *info);

Tree *removeTree(Tree *tree, void *info);



#endif