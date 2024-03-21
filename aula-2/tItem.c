#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tItem.h"

typedef struct tItem{
    tProd *prod;
    int qtd;
} tItem;

tItem **lerItens(tProd **p, int qtdP){
    int num;
    tItem **item = malloc(qtdP * sizeof(tItem*));
    for(int i = 0; i < qtdP; i++){
        printf("Quantidade de %s: ", obtemNome(p[i]));
        scanf("%d%*c", &num);
        item[i] = criaItem(p[i], num);
    }
    return item;
}

float obtemValorItem(tItem *item){
    return item->qtd * obtemValor(item->prod);
}

tItem *criaItem(tProd *p, int qtd){
    tItem *item = malloc(sizeof(tItem));
    item->prod = p;
    item->qtd = qtd;
}

void desalocaItem(tItem * item){
    free(item);
}

void imprimeItem(tItem * item){
    if(item->qtd == 0) return;
    printf("     Item: ");
    imprimeProd(item->prod);
    printf(", quantidade: %d\n", item->qtd);
}