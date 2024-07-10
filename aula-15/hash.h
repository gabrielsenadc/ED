#ifndef hash_h
#define hash_h

#include <stdio.h>
#include "word.h"

typedef struct Cell Cell;

typedef struct Hash Hash;

int hashFunction(char *palavra, int tam);

Hash * criaHash(int tam);

void insereHash(Hash *hash, char *string);

void liberaHash(Hash *hash);

void printHash(Hash *hash);

void printSortedHash(Hash *hash);


#endif 