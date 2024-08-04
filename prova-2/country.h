#ifndef country_h
#define country_h

#include <stdio.h>

typedef struct country Country;

Country * criaCountry(char *nome, int ouro, int prata, int bronze);

void printCountry(Country * country, FILE * file);

void freeCountry(Country *country);

int comparaCountry(const void *c1, const void *c2);

char * getNome(Country *country);

int getOuro(Country *country);

int getPrata(Country *country);

int getBronze(Country *country);

void setOuro(Country *country, int ouro);

void setPrata(Country *country, int prata);

void setBronze(Country *country, int bronze);

#endif