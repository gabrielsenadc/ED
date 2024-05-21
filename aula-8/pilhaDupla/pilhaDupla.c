#include <stdio.h>
#include <stdlib.h>
#include "pilhaDupla.h"

struct indice{
    int Topo, Base;
};

struct pilha{
    TipoItem* Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
};

TipoPilhaDupla* criaPilha(){
    TipoPilhaDupla* p = (TipoPilhaDupla*) malloc (sizeof (TipoPilhaDupla));

    p->Pilha1.Base = 0;
    p->Pilha1.Topo = -1; 
    p->Pilha2.Base = MaxTam -1;
    p->Pilha2.Topo = MaxTam;

    return p;
}

void push(TipoPilhaDupla *p, TipoItem *item, int i){
    if(i == 1){
        if(p->Pilha1.Topo + 1 == p->Pilha2.Topo) {
            printf("Overflow\n");
            free(item);
            return;
        }

        p->Pilha1.Topo++;

        p->Item[p->Pilha1.Topo] = item;
    }

    if(i == 2){

        if(p->Pilha1.Topo  == p->Pilha2.Topo - 1) {
            printf("Overflow\n");
            free(item);
            return;
        }

        p->Pilha2.Topo--;

        p->Item[p->Pilha2.Topo] = item;
    }
}

void imprimePilhas(TipoPilhaDupla *p){
    printf("%d %d\n", p->Pilha1.Topo, p->Pilha2.Topo);
    printf("Pilha1: ");
    for(int i = p->Pilha1.Base; i <= p->Pilha1.Topo; i++){
        printf("%d ", *(p->Item[i]));
    }
    printf("\n");

    printf("Pilha2: ");
    for(int i = p->Pilha2.Base; i >= p->Pilha2.Topo; i--){
        printf("%d ", *(p->Item[i]));
    }
    printf("\n");
}

void liberaPilhas(TipoPilhaDupla *p){
    for(int i = MaxTam - 1; i >= p->Pilha2.Topo; i--){
        free(p->Item[i]);
    }
    for(int i = 0; i <= p->Pilha1.Topo; i++){
        free(p->Item[i]);
    }

    free(p);
}

TipoItem* pop(TipoPilhaDupla *pilha, int i){
    if(i == 1){
        if(pilha->Pilha1.Topo == -1){
            printf("Pilha vazia\n");
            return NULL;
        }
        pilha->Pilha1.Topo--;

        return pilha->Item[pilha->Pilha1.Topo + 1];
    }

    if(i == 2){
        if(pilha->Pilha2.Topo == MaxTam - 1){
            printf("Pilha vazia\n");
            return NULL;
        }
        pilha->Pilha2.Topo++;

        return pilha->Item[pilha->Pilha2.Topo - 1];
    }
}