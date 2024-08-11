#ifndef hashWord_h
#define hashWord_h

#include <stdio.h>

typedef struct hash Hash;

Hash * criaHash(int size);

void insereHash(Hash *hash, char *word);

void liberaHash(Hash * hash);

void imprimeHash(Hash *hash);


#endif