#ifndef _TFILIAL_H_
#define _TFILIAL_H_

#include "tEstoque.h"

typedef struct tFilial tFilial;

tFilial *criaFilial(char *nome, tProd **p, int qtdP);

tFilial **lerFiliais(tProd **p, int qtdP, int qtdF);

void desalocaFilial(tFilial *f);

void imprimeFilial(tFilial *f);

float obtemValorFilial(tFilial *f);

#endif