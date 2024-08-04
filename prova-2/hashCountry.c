#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashCountry.h"

typedef struct cell Cell;

struct hash{
    Cell **tab;
    int size;
    int qtd;
};

struct cell{
    Country *country;
    Cell *next;
};

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

    Cell * aux = hash->tab[index];

    while(aux){
        if(!strcmp(nome, getNome(aux->country))) break;
    }

    if(aux == NULL){
        Country * country = criaCountry(nome, ouro, prata, bronze);
        Cell * cell = malloc(sizeof(Cell));
        cell->country = country;

        cell->next = hash->tab[index];
        hash->tab[index] = cell;

        hash->qtd++;
    } else{
        setBronze(aux->country, bronze);
        setOuro(aux->country, ouro);
        setPrata(aux->country, prata);
    }

}

void freeHash(Hash *hash){
    for(int i = 0; i < hash->size; i++){
        Cell *cell = hash->tab[i], *aux = NULL;
        while(cell){
            aux = cell;
            cell = cell->next;
            freeCountry(aux->country);
            free(aux);
        }
    }

    free(hash->tab);
    free(hash);
}

void criaRankHash(Hash *hash){
    FILE * file = fopen("rankHash.txt", "w");

    Country *vet[hash->qtd];

    int index = 0;
    for(int i = 0; i < hash->size; i++){
        Cell * aux = hash->tab[i];
        while(aux){
            vet[index] = aux->country;
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



