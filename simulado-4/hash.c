#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct cell Cell;

struct hash{
    Cell **tab;
    int size;
    int qtd;
    int (*compare) (const void *, const void *);
    void (*imprime) (void *, FILE *);
    int (*function) (void *, int);
    void (*libera) (void *);
    void (*set) (void *, char c);
};

struct cell{
    Cell * next;
    void * dado;
};

Hash * criaHash(int size, int (*compare) (const void *, const void *), void (*imprime) (void *, FILE *), int (*function) (void *, int), void (*libera) (void *), void (*set) (void *, char c)){
    Hash * hash = malloc(sizeof(Hash));

    hash->tab = calloc(size, sizeof(Cell*));
    hash->size = size;
    hash->compare = compare;
    hash->imprime = imprime;
    hash->function = function;
    hash->libera = libera;
    hash->set = set;
    hash->qtd = 0;

    return hash;
}

void insereHash(Hash * hash, void * dado){
    int index = hash->function(dado, hash->size);

    Cell * aux = hash->tab[index];

    while(aux){
        if(!hash->compare(&dado, &aux->dado)) break;
        aux = aux->next;
    }

    if(aux == NULL){
        Cell * cell = malloc(sizeof(Cell));

        cell->dado = dado;
        cell->next = hash->tab[index];
        hash->tab[index] = cell;

        hash->qtd++;
    }
}

void liberaCell(Cell * cell, void (*libera) (void *)){
    if(cell == NULL) return;

    libera(cell->dado);
    liberaCell(cell->next, libera);
    free(cell);
}

void liberaHash(Hash * hash){
    for(int i = 0; i < hash->size; i++){
        liberaCell(hash->tab[i], hash->libera);
    }

    free(hash->tab);
    free(hash);
}

void imprimeHash(Hash * hash){
    FILE * file = fopen("saidaHash.txt", "w");
    void *vet[hash->qtd];

    int index = 0;
    for(int i = 0; i < hash->size; i++){
        Cell * aux = hash->tab[i];

        while(aux){
            vet[index] = aux->dado;
            index++;
            aux = aux->next;
        }
    }

    qsort(vet, hash->qtd, sizeof(void*), hash->compare);

    for(int i = 0; i < hash->qtd; i++){
        hash->imprime(vet[i], file);
    }

    fclose(file);
}

void setFrequencia(Hash * hash, void * dado, char p){
    int index = hash->function(dado, hash->size);

    Cell * aux = hash->tab[index];

    while(aux){
        if(!hash->compare(&dado, &aux->dado)){
            hash->set(aux->dado, p);
            break;
        }
        aux = aux->next;
    }

    
}