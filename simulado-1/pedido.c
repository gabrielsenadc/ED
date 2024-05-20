#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

typedef struct cellType cellType;

struct pedido {
    char *dono;
    cellType *first;
    cellType *last;
};

struct cellType{
    cellType *next;
    cellType *ant;
    TProduto *produto;
};

TPedido* InicPedido (char* dono){
    TPedido *pedido = malloc(sizeof(TPedido));

    pedido->dono = strdup(dono);
    pedido->first = NULL;
    pedido->last = NULL;

    return pedido;
}

void IncluiProdutoPedido (TPedido* pedido, TProduto* prod){
    for(cellType *aux = pedido->first; aux; aux = aux->next){
        if(!strcmp(RetornaNome(prod), RetornaNome(aux->produto))){
            printf("Produto já existe no pedido\n");
            return;
        }
    }

    cellType *cell = malloc(sizeof(cellType));

    cell->produto = prod;
    cell->next = NULL;
    cell->ant = pedido->last;

    if(pedido->last) pedido->last->next = cell;
    if(!pedido->first) pedido->first = cell;

    pedido->last = cell;
}

void ImprimePedido (TPedido* pedido){
    printf("Dono do Pedido: %s\n", pedido->dono);

    if(pedido->first == NULL){
        printf("Nao ha produtos neste pedido!\n");
        return;
    }

    for(cellType *cell = pedido->first; cell; cell = cell->next){
        ImprimeIngredientes(cell->produto);
    }
}

void RetiraProdutoPedido (TPedido* pedido, char* prod){
    cellType *aux = NULL;
    for(aux = pedido->first; aux; aux = aux->next){
        if(!strcmp(prod, RetornaNome(aux->produto))){
            break;
        }
    }

    if(aux == NULL){
        printf("Esse produto não existe no pedido");
        return;
    }

    if(aux->next) aux->next->ant = aux->ant;
    if(aux->ant) aux->ant->next = aux->next;

    if(aux->next == NULL) pedido->last = aux->ant;
    if(aux->ant == NULL) pedido->first = aux->next;

    free(aux);
}

void LiberaPedido(TPedido *pedido){
    free(pedido->dono);
    cellType *aux = NULL, *cell = pedido->first;

    while(cell){
        aux = cell;
        cell = cell->next;
        free(aux);
    }

    free(pedido);
}

int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    int calorias = 0;
    for(cellType *aux = pedido->first; aux; aux = aux->next){
        calorias += Calorias(aux->produto);
    }

    if(calorias > restricao_calorica){
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    for(cellType *aux = pedido->first; aux; aux = aux->next){
        if(VerificaIngrediente(aux->produto, restricao_alimentar)){
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(aux->produto));
            return 0;
        }
    }

    LiberaPedido(pedido);

    return 1;
}
