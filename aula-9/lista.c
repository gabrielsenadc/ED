#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct celula{
    int n;
    Celula *next;
};

Lista* criaLista(){
    return NULL;
}

Lista* insereProduto(Lista *l, int n){
    if(l == NULL){
        Celula *cell = malloc(sizeof(Celula));
        cell->n = n;
        cell->next = NULL;

        return cell;
    }

    l->next = insereProduto(l->next, n);
    return l;
}

Lista* retiraProduto(Lista *l, int n){
    if(l != NULL){
        if(l->n == n){
            Celula *t = l;
            l = l->next;
            free(t);
        } else l->next = retiraProduto(l->next, n);
        
    }
    
    return l;
}

void imprimeLista(Lista *l){
    if(l != NULL){
        printf("%d\n", l->n);

        imprimeLista(l->next);
    }
}

Lista* liberaLista(Lista *l){
    if(l != NULL){
        Celula *t = l;
        l = l->next;
        free(t);

        return liberaLista(l);
    }

    return NULL;
}