#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct celula Celula;

typedef Celula Lista;

Lista* criaLista();

Lista* insereProduto(Lista *l, int n);

Lista* retiraProduto(Lista *l, int n);

void imprimeLista(Lista *l);

Lista* liberaLista(Lista *l);


#endif