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
    return prod;
}

void desalocaProd(tProd * p){
    free(p->nome);
    free(p);
}

void imprimeProd(tProd * p){
    pritnf("%s, valor unitario: %2.f", p->nome, p->valor);
}