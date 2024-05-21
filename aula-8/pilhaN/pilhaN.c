#include <stdio.h>
#include <stdlib.h>
#include "pilhaN.h"

struct indice{
    int Topo, Base;
};

struct pilha{
    TipoItem* Item[MAXTAM];
    IndicePilha * Pilha;
    int qtd;
};

TipoPilhaN* criaPilha(int i){
    TipoPilhaN* pilha = malloc(sizeof(TipoPilhaN));

    pilha->Pilha = malloc(sizeof(IndicePilha) *  i);
    pilha->qtd = i;

    for(int j = 0; j < i; j++){
        int base = (MAXTAM / i) * j;
        pilha->Pilha[j].Base = 0 + base;
        pilha->Pilha[j].Topo =  pilha->Pilha[j].Base - 1;
    }

    return pilha;
}

void push(TipoPilhaN *pilha, TipoItem *item, int i){
    if(item == NULL) return;

    i--;
    if(i >= pilha->qtd){
        printf("indice invalido\n");
        free(item);
        return;
    }

    int max = MAXTAM;
    if(i != 9) max = pilha->Pilha[i + 1].Base;
    if(pilha->Pilha[i].Topo + 1 == max){
        printf("Overflow\n");
        free(item);
        return;
    }

    pilha->Pilha[i].Topo++;
    pilha->Item[pilha->Pilha[i].Topo] = item;
}

void imprimePilhas(TipoPilhaN *p){
    for(int i = 0; i < p->qtd; i++){
        printf("Pilha%02d: ", i + 1);
        for(int j = p->Pilha[i].Base; j <= p->Pilha[i].Topo; j++){
            printf("%d ", *p->Item[j]);
        }
        printf("\n");
    }
    printf("\n");
}

TipoItem* pop(TipoPilhaN *pilha, int i){
    i--;
    if(pilha->Pilha[i].Topo == pilha->Pilha[i].Base - 1){
        printf("Pilha vazia\n");
        return NULL;
    }

    pilha->Pilha[i].Topo--;
    return pilha->Item[pilha->Pilha[i].Topo + 1];
}

void liberaPilhas(TipoPilhaN *p){
    for(int i = 0; i < p->qtd; i++){
        for(int j = p->Pilha[i].Base; j <= p->Pilha[i].Topo; j++){
            free(p->Item[j]);
        }
    }
    free(p->Pilha);
    free(p);
}