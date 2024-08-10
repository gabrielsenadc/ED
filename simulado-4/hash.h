#ifndef hash_h
#define hash_h

#include <stdio.h>

typedef struct hash Hash;

Hash * criaHash(int size, int (*compare) (const void *, const void *), void (*imprime) (void *, FILE *), int (*function) (void *, int), void (*libera) (void *), void (*set) (void *, char c));

void insereHash(Hash * hash, void * dado);

void liberaHash(Hash * hash);

void imprimeHash(Hash * hash);

void setFrequencia(Hash * hash, void * dado, char p);


#endif