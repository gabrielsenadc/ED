#ifndef _TFILIAL_H_
#define _TFILIAL_H_

#include "tEstoque.h"

typedef struct tFilial tFilial;

tFilial *criaFilial(char *nome, tEstoque *e, tProd **p, int qtdP);

void desalocaFilial(tFilial *e);

void imprimeFilial(tFilial *e);

#endif