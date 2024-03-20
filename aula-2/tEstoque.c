#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEstoque.h"

typedef struct tEstoque{
    float valor;
    tItem **item;
    int qtdItens;
} tEstoque;

tEstoque *criaEstoque(tProd **p, int qtdP){
    tEstoque *e = malloc(sizeof(tEstoque));
    e->item = lerItens(p, qtdP);
    e->qtdItens = qtdP;
    e->valor = calculaValor(e);
    return e;
}

float calculaValor(tEstoque *e){
    float valor = 0;
    for(int i = 0; i < e->qtdItens; i++){
        valor += obtemValorItem(e->item[i]);
    }
    return valor;
}

void desalocaEstoque(tEstoque * e){
    for(int i = 0; i < e->qtdItens; i++){
        desalocaItem(e->item[i]);
    }
    free(e->item);
    free(e);
}

void imprimeEstoque(tEstoque * e){
    printf("Estoque: %2.f\n", e->valor);
    for(int i = 0; i < e->qtdItens; i++){
        imprimeItem(e->item);
    }
}