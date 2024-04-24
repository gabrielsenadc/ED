#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>

typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char *nome, int tipo);

int obtemComportamentoCachorro(Cachorro *dog);

void liberaCachorro(Cachorro *dog);

#endif 