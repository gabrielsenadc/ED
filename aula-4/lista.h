#ifndef lista_h
#define lista_h

#include <stdio.h>
#include "produto.h"

typedef struct lista Lista;

Lista* criaLista();

void insereProduto(Lista *l, Produto *p);

void retiraProduto(Lista *l, int codigo);

void imprimeLista(Lista *l);

void liberaLista(Lista *l);


#endif