#ifndef _TESTOQUE_H_
#define _TESTOQUE_H_

#include "tItem.h"

typedef struct tEstoque tEstoque;

tEstoque *criaEstoque(tProd **p, int qtdP);

float calculaValor(tEstoque *e);

void desalocaEstoque(tEstoque *e);

void imprimeEstoque(tEstoque *e);

#endif