#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct celula Celula;

struct lista{
    Celula *first;
    Celula *last;
};

struct celula{
    Produto *p;
    Celula *prox;
    Celula *ant;
};

Lista* criaLista(){
    Lista *l = malloc(sizeof(Lista));
    l->first = l->last = NULL;
    return l;
}

void insereProduto(Lista *l, Produto *p){
    Celula *cel = malloc(sizeof(Celula));
    cel->p = p;
    if(l->first != NULL) l->first->ant = cel;
    cel->prox = l->first;
    cel->ant = NULL;

    if(l->last == NULL) l->last = cel;
    l->first = cel;

}

void retiraProduto(Lista *l, int codigo){
    Celula *cel;
    for(cel = l->first; cel!= NULL; cel = cel->prox){
        if(obtemCodigo(cel->p) == codigo) break;
    }

    if(!cel){
        printf("Nao achou o produto");
        return;
    }
    

    if(cel->prox != NULL) cel->prox->ant = cel->ant;
    if(cel->ant != NULL) cel->ant->prox = cel->prox;

    if(cel->ant == NULL) l->first = cel->prox;
    if(cel->prox != NULL)  l->last = cel->ant;
        
    free(cel);
}

void imprimeLista(Lista *l){
    printf("Lista:\n");
    for(Celula *cel = l->first; cel; cel = cel->prox){
        imprimeProduto(cel->p);
    }
}

void liberaLista(Lista *l){
    Celula *cel = l->first;
    Celula *aux = l->first;
    while(aux){
        cel = aux;
        aux = cel->prox;
        free(cel);
    }
    free(l);
}

