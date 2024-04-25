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
    Celula *next;
};

Lista* criaLista(){
    Lista *l = malloc(sizeof(Lista));
    l->first = l->last = NULL;
    return l;
}

void insereInicioProduto(Lista *l, Produto *p){
    Celula *cel = malloc(sizeof(Celula));
    cel->p = p;
    cel->next = l->first;

    if(!l->last) l->last = cel;
    l->first = cel;

}

void insereFimProduto(Lista *l, Produto *p){
    Celula *cel = malloc(sizeof(Celula));
    cel->p = p;
    cel->next = NULL;

    if(!l->last) l->first = cel;
    if(l->last) l->last->next = cel;
    l->last = cel;
}

void retiraProduto(Lista *l, int codigo){
    Celula *ant = NULL, *cel = l->first;
    while(cel){
        if(obtemCodigo(cel->p) == codigo) break;
        ant = cel;
        cel = cel->next;
    }

    if(!cel){
        printf("Nao achou o produto");
        return;
    }
    
    if(!ant) l->first = cel->next;
    if(!cel->next) {
        l->last = ant;
        if(ant) ant->next = NULL;
    }
    if(ant && cel->next) ant->next = cel->next;
    free(cel);
}

void imprimeLista(Lista *l){
    printf("Lista:\n");
    for(Celula *cel = l->first; cel; cel = cel->next){
        imprimeProduto(cel->p);
    }
}

void liberaLista(Lista *l){
    Celula *cel = l->first;
    Celula *aux = l->first;
    while(aux){
        cel = aux;
        aux = cel->next;
        free(cel);
    }
    free(l);
}