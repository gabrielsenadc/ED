#ifndef lista_h
#define lista_h

#include <stdio.h>
#include "produto.h"

typedef struct celula Celula;

typedef Celula Lista;

Lista* criaLista();

Lista* insereProduto(Lista *l, Produto *p);

Lista* retiraProduto(Lista *l, int codigo);

void imprimeLista(Lista *l);

Lista* liberaLista(Lista *l);


#endif