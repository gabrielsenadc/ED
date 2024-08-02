#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashCountry.h"

struct hash{
    Country **tab;
    int size;
    int qtd;
};

struct country{
    char *nome;
    int ouro;
    int prata;
    int bronze;
    Country * next;
};

//Country functions

Country * criaCountry(char *nome, int ouro, int prata, int bronze){
    Country * country = malloc(sizeof(Country));

    country->nome = strdup(nome);
    country->ouro = ouro;
    country->prata = prata;
    country->bronze = bronze;
    country->next = NULL;

    return country;
}

void printCountry(Country * country, FILE * file){
    fprintf(file, "%s: %d ouro - %d prata - %d bronze\n", country->nome, country->ouro, country->prata, country->bronze);
}

void freeCountry(Country *country){
    if(country == NULL) return;

    freeCountry(country->next);
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

//Hash functions

int hashFunction(int size, char * nome){
    int total = 0;
    for(int i = 0; i < strlen(nome); i++) total += nome[i];

    return total % size;
}

Hash* criaHash(int size){
    Hash *hash = malloc(sizeof(Hash));

    hash->tab = calloc(size, sizeof(Country*)); 
    hash->size = size;
    hash->qtd = 0;

    return hash;
}

void insereHash(Hash *hash, char *nome, int ouro, int prata, int bronze){
    int index = hashFunction(hash->size, nome);

    Country * aux = hash->tab[index];

    while(aux){
        if(!strcmp(nome, aux->nome)) break;
    }

    if(aux == NULL){
        Country * country = criaCountry(nome, ouro, prata, bronze);

        country->next = hash->tab[index];
        hash->tab[index] = country;

        hash->qtd++;
    } else{
        aux->bronze = bronze;
        aux->ouro = ouro;
        aux->prata = prata;
    }

}

void freeHash(Hash *hash){
    for(int i = 0; i < hash->size; i++){
        freeCountry(hash->tab[i]);
    }

    free(hash->tab);
    free(hash);
}

void criaRank(Hash *hash){
    FILE * file = fopen("rank.txt", "w");

    Country *vet[hash->qtd];

    int index = 0;
    for(int i = 0; i < hash->size; i++){
        Country * aux = hash->tab[i];
        while(aux){
            vet[index] = aux;
            index++;
            aux = aux->next;
        }
    }

    qsort(vet, hash->qtd, sizeof(Country*), comparaCountry);

    for(int i = 0; i < hash->qtd; i++){
        printCountry(vet[i], file);
    }

    fclose(file);
}



