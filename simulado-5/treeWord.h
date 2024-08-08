#ifndef treeword_h
#define treeword_h

#include <stdio.h>

typedef struct tree Tree;

Tree * criaTree(char * word);

Tree * insertTree(Tree * tree, char * word);

void freeTree(Tree * tree);

void printWords(Tree * tree, FILE * file);

int getQttTree(Tree * tree);

int getQttWords(Tree * tree);

Tree * getHigherFrequency(Tree * tree);

int getQtt(Tree * tree);

char * getWord(Tree * tree);


#endif