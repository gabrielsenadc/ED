#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFilial.h"

typedef struct tFilial{
    char *nome;
    tEstoque *estoque;
} tFilial;

tFilial *criaFilial(char *nome, tEstoque *e, tProd **p, int qtdP){
    tFilial *filial = malloc(sizeof(tFilial));
    filial->nome = strdup(nome);
    filial->estoque = criaEstoque(p, qtdP);
    return filial;
}

void desalocaFilial(tFilial *f){
    free(f->nome);
    desalocaEstoque(f->estoque);
    free(f);
}

void imprimeFilial(tFilial *f){
    printf("Filial: %s\n", f->nome);
    imprimeEstoque(f->estoque);
}