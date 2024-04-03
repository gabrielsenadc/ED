#ifndef produto_h
#define produto_h

#include <stdio.h>

typedef struct produto Produto;

Produto* criaProduto(int codigo, char *nome, int preco);

int obtemCodigo(Produto *p);

void imprimeProduto(Produto *p);

void liberaProduto(Produto *p);

#endif