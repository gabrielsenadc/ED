#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash.h"

struct Cell{
    Word *word;
    Cell *next;
};

struct Hash{
    Cell **tab;
    int tam;
    int qtd;
};

int hashFunction(char *palavra, int tam){
    int total = 0;
    for(int i = 0; i < strlen(palavra); i++){
        total += palavra[i];
    }

    return total % tam;
}

Hash * criaHash(int tam){
    Hash * hash = malloc(sizeof(Hash));
    hash->tab = calloc(tam, sizeof(Cell*));
    hash->tam = tam;
    hash->qtd = 0;
    return hash;
}

void insereHash(Hash *hash, char *string){
    int index = hashFunction(string, hash->tam);

    Cell *aux = hash->tab[index];

    while(aux){
        if(!strcmp(string, getString(aux->word))) break;
        aux = aux->next;
    }

    if(aux == NULL){
        Cell *cell = malloc(sizeof(Cell));

        cell->word = criaWord(string);

        cell->next = hash->tab[index];
        hash->tab[index] = cell;

        hash->qtd++;
    } else incrementaWord(aux->word);

}

void liberaHash(Hash *hash){
    for(int i = 0; i < hash->tam; i++){
        Cell *cell = hash->tab[i], *aux = NULL;
        while(cell){
            aux = cell;
            cell = cell->next;
            freeWord(aux->word);
            free(aux);
        }
    }

    free(hash->tab);
    free(hash);
}

void printHash(Hash *hash){
    for(int i = 0; i < hash->tam; i++){
        for(Cell *cell = hash->tab[i]; cell; cell = cell->next){
            printWord(cell->word);
        }
    }
}

void printSortedHash(Hash *hash){
    Word *vet[hash->qtd];

    int j = 0;
    for(int i = 0; i < hash->tam; i++){
        for(Cell *cell = hash->tab[i]; cell; cell = cell->next){
            vet[j] = cell->word;
            j++;
        }
    } 

    qsort(vet, hash->qtd, sizeof(Word*), compareWords);

    for(int i = 0; i < hash->qtd; i++){
        printWord(vet[i]);
    }
}



