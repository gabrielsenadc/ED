#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lista.h"
#include "Gato.h"
#include "Cachorro.h"

typedef struct cel Cel;

struct lista {
    Cel *first;
    Cel *last;
};

struct cel{
    void *animal;
    int tipo;
    Cel *prox;
    Cel *ant;
};

Lista* criaLista(){
    Lista *lista = malloc(sizeof(Lista));
    
    lista->first = lista->last = NULL;

    return lista;
}

void insereAnimal(Lista *lista, void *animal, int tipo){
    Cel *cel = malloc(sizeof(Cel));

    cel->tipo = tipo;
    cel->animal = animal;

    cel->ant = lista->last;
    cel->prox = NULL;
    if(lista->last) lista->last->prox = cel;

    if(lista->first == NULL) lista->first = cel;

    lista->last = cel;
}

void removeAnimal(Lista *lista, void *p){
    Cel *cel = NULL;
    for(cel = lista->first; cel; cel = cel->prox){
        if(cel->animal == p) break;
    }

    if(cel == NULL) return;

    if(cel->prox == NULL) lista->last = cel->ant;
    if(cel->ant == NULL) lista->first = cel->prox;

    if(cel->prox) cel->prox->ant = cel->ant;
    if(cel->ant) cel->ant->prox = cel->prox;

    free(cel);
}

void liberaLista(Lista *lista){
    Cel *cel = NULL;
    Cel *aux = lista->first;
    while(aux){
        cel = aux;
        aux = aux->prox;
        free(cel);
    }

    free(lista);
}

int existeNaLista(Lista *lista, void *p){
    for(Cel *cel = lista->first; cel; cel = cel->prox){
        if(cel->animal == p) return 1;
    }
    return 0;
}

void imprimeLista(Lista *lista){
    for(Cel *cel = lista->first; cel; cel = cel->prox){
        if(cel->tipo == DOG) imprimeCachorro((Cachorro*) cel->animal);
        if(cel->tipo == CAT) imprimeGato((Gato*) cel->animal);
    }
    printf("\n");
}

float calculaReceitaLista(Lista *lista){
    float valor = 0;
    for(Cel *cel = lista->first; cel; cel = cel->prox){
        if(cel->tipo == DOG) {
            valor += 40;
            if(obtemComportamentoCachorro((Cachorro*) cel->animal)) valor += 5;
        }
        if(cel->tipo == CAT) {
            valor += 30;
            if(obtemComportamentoGato((Gato*) cel->animal)) valor += 5;
        }
    }
    return valor;
}

