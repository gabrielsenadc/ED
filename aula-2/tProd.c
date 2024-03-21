#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProd.h"

typedef struct tProd{
    char *nome;
    float valor;
} tProd;

char *obtemNome(tProd *p){
    return p->nome;
}

float obtemValor(tProd *p){
    return p->valor;
}

tProd *criaProd(char *nome, float valor){
    tProd *prod = malloc(sizeof(tProd));
    prod->nome = strdup(nome);
    prod->valor = valor;
    return prod;
}

tProd **cadastrarProdutos(int qtdP){
    tProd **p = malloc(qtdP * sizeof(tProd));
    char nome[100];
    float valor = 0;
    for(int i = 0; i < qtdP; i++){
        printf("Nome do produto %d: ", i + 1);
        scanf("%[^\n]%*c", nome);
        printf("Valor do produto %d: ", i + 1);
        scanf("%f%*c", &valor);
        p[i] = criaProd(nome, valor);
        if(i != qtdP - 1) printf("\n");
    }
    printf("##############################\n\n");

    return p;
}

void desalocaProd(tProd * p){
    free(p->nome);
    free(p);
}

void imprimeProd(tProd * p){
    printf("%s, valor unitario: %2.f", p->nome, p->valor);
}