#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashCountry.h"

struct country{
    char *nome;
    int ouro;
    int prata;
    int bronze;
};

Country * criaCountry(char *nome, int ouro, int prata, int bronze){
    Country * country = malloc(sizeof(Country));

    country->nome = strdup(nome);
    country->ouro = ouro;
    country->prata = prata;
    country->bronze = bronze;

    return country;
}

void printCountry(Country * country, FILE * file){
    fprintf(file, "%s: %d ouro - %d prata - %d bronze\n", country->nome, country->ouro, country->prata, country->bronze);
}

void freeCountry(Country *country){
    free(country->nome);
    free(country);
}

int comparaCountry(const void *c1, const void *c2){
    Country * country1 = *(Country**)c1;
    Country * country2 = *(Country**)c2;

    if(country2->ouro - country1->ouro != 0) return country2->ouro - country1->ouro;
    if(country2->prata - country1->prata != 0) return country2->prata - country1->prata;
    return country2->bronze - country1->bronze;
}

char * getNome(Country *country){
    return country->nome;
}

int getOuro(Country *country){
    return country->ouro;
}

int getPrata(Country *country){
    return country->prata;
}

int getBronze(Country *country){
    return country->bronze;
}

void setOuro(Country *country, int ouro){
    country->ouro = ouro;
}

void setPrata(Country *country, int prata){
    country->prata = prata;
}

void setBronze(Country *country, int bronze){
    country->bronze = bronze;
}