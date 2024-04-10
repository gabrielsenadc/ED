#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct celula{
    Produto* p;
    Celula* prox;
    Celula* ant;
};

Lista* criaLista(){
    return NULL;
}

Lista* insereProduto(Lista *l, Produto *p){
    Celula *c = malloc(sizeof(Celula));

    c->p = p;
    c->ant = NULL;
    if(l != NULL) {
        c->prox = l;
        l->ant = c;
    }
    if(l == NULL) c->prox = NULL;

    return c;
}

Lista* retiraProduto(Lista *l, int codigo){
    Celula* c;
    for(c = l; c; c = c->prox){
        if(obtemCodigo(c->p) == codigo) break;
    }

    if(c == NULL) return l;

    
    if(c->prox != NULL) c->prox->ant = c->ant;
    if(c->ant != NULL) c->ant->prox = c->prox;
    if(c == l) l = c->prox;
    
    free(c);
    
    return l;
}

void imprimeLista(Lista *l){
    printf("Lista:\n");
    for(Celula *c = l; c; c = c->prox){
        imprimeProduto(c->p);
    }
}

Lista* liberaLista(Lista *l){
    Celula *cel = l;
    Celula *aux = l;
    while(aux){
        cel = aux;
        aux = cel->prox;
        free(cel);
    }
}
