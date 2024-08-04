#ifndef hash_h
#define hash_h

#include <stdio.h>
#include "country.h"

typedef struct hash Hash;

Hash* criaHash(int size);

void insereHash(Hash *hash, char *nome, int ouro, int prata, int bronze);

void criaRankHash(Hash *hash);

void freeHash(Hash *hash);



#endif