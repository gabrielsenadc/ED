#ifndef _TITEM_H_
#define _TITEM_H_

#include "tProd.h"

typedef struct tItem tItem;

tItem **lerItens(tProd **p, int qtdP);

tItem *criaItem(tProd *p, int qtd);

float obtemValorItem(tItem *item);

void desalocaItem(tItem * p);

void imprimeItem(tItem * p);

#endif