#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFilial.h"

typedef struct tFilial{
    char *nome;
    tEstoque *estoque;
} tFilial;

tFilial *criaFilial(char *nome, tProd **p, int qtdP){
    tFilial *filial = malloc(sizeof(tFilial));
    filial->nome = strdup(nome);
    filial->estoque = criaEstoque(p, qtdP);
    return filial;
}

tFilial **lerFiliais(tProd **p, int qtdP, int qtdF){
    char nome[100];
    tFilial **filial = malloc(qtdF * sizeof(tFilial*));
    printf("### Cadastro de Filiais ###\n");
    for(int i = 0; i < qtdF; i++){
        printf("Nome da filial %d: ", i + 1);
        scanf("%[^\n]%*c", nome);
        filial[i] = criaFilial(nome, p, qtdP);
        if(i != qtdF - 1) printf("\n");
    }
    return filial;
}

void desalocaFilial(tFilial *f){
    free(f->nome);
    desalocaEstoque(f->estoque);
    free(f);
}

void imprimeFilial(tFilial *f){
    printf("   Filial: %s\n", f->nome);
    imprimeEstoque(f->estoque);
}

float obtemValorFilial(tFilial *f){
    return obtemValorEstoque(f->estoque);
}