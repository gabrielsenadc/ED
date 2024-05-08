#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct Cell Cell;

struct fila{
    Cell *in;
    Cell *out;
};

struct Cell{
    Cell *next;
    Amostra *amostra;
};

Fila* criaFila(){
    Fila *fila = malloc(sizeof(Fila));

    fila->in = fila->out = NULL;

    return fila;
}

void insereAmostra(Fila *fila, Amostra *amostra){
    Cell *cell = malloc(sizeof(Cell));

    cell->amostra = amostra;
    cell->next = NULL;

    if(fila->out == NULL) fila->out = cell;
   
    if(fila->in) fila->in->next = cell;
    fila->in = cell;
}

void inserePrerencial(Fila *fila, Amostra *amostra){
    Cell *cell = malloc(sizeof(Cell));

    cell->amostra = amostra;
    cell->next = fila->out;

    fila->out = cell;

    if(fila->in == NULL) fila->in = cell;
   
}

Amostra* retiraAmostra(Fila *fila){
    if(fila->out == NULL) return NULL;

    Cell *cell = fila->out;
    Amostra *amostra = cell->amostra;
    fila->out = cell->next;
    
    free(cell);
    return amostra;
}   

void imprimeFila(Fila *fila){
    for(Cell *cell = fila->out; cell; cell = cell->next){
        imprimeAmostra(cell->amostra);
    }
}

int temAmostraFila(Fila *fila){
    if(fila->out) return 1;
    return 0;
}

void liberaFila(Fila *fila){
    Cell *aux = NULL, *cell = fila->out;

    while(cell){
        aux = cell;
        cell = cell->next;
        liberaAmostra(aux->amostra);
        free(aux);
    }

    free(fila);
}

