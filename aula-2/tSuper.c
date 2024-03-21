#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSuper.h"

typedef struct tSuper{
    char *nome;
    tFilial **filial;
    int qtdFilial;
    float valor;
} tSuper;

tSuper *criaSuper(char *nome, tProd **p, int qtdP){
    tSuper *s = malloc(sizeof(tSuper));
    s->nome = strdup(nome);
    printf("Quantas filiais? ");
    scanf("%d%*c", &s->qtdFilial);
    s->filial = lerFiliais(p, qtdP, s->qtdFilial);
    s->valor = estoqueTotal(s);
    return s;
}

float estoqueTotal(tSuper *s){
    float valor = 0;
    for(int i = 0; i < s->qtdFilial; i++){
        valor += obtemValorFilial(s->filial[i]);
    }
    return valor;
}

void desalocaSuper(tSuper *s){
    free(s->nome);
    for(int i = 0; i < s->qtdFilial; i++){
        desalocaFilial(s->filial[i]);
    }
    free(s->filial);
    free(s);
}

void imprimeSuper(tSuper *s){
    printf("\nSupermercado: %s, Estoque Total: %2.f\n", s->nome, s->valor);
    for(int i = 0; i < s->qtdFilial; i++){
        imprimeFilial(s->filial[i]);
    }
}