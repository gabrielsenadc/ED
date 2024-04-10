#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto {
    int codigo;
    char* nome;
    int preco;
};

Produto* criaProduto(int codigo, char *nome, int preco){
    Produto *p = malloc(sizeof(Produto));

    p->codigo = codigo;
    p->nome = strdup(nome);
    p->preco = preco;

    return p;
}

int obtemCodigo(Produto *p){
    return p->codigo;
}

void imprimeProduto(Produto *p){
    printf("Produto %s (%d): R$%d\n", p->nome, p->codigo, p->preco);
}

void liberaProduto(Produto *p){
    free(p->nome);
    free(p);
}