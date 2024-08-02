#ifndef hash_h
#define hash_h

#include <stdio.h>

typedef struct hash Hash;
typedef struct country Country;

Hash* criaHash(int size);

void insereHash(Hash *hash, char *nome, int ouro, int prata, int bronze);

void criaRank(Hash *hash);

void freeHash(Hash *hash);



#endif