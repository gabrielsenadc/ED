#ifndef _TSUPER_H_
#define _TSUPER_H_

#include "tFilial.h"

typedef struct tSuper tSuper;

tSuper *criaSuper(char *nome, tProd **p, int qtdP);

void desalocaSuper(tSuper *s);

void imprimeSuper(tSuper *s);

float estoqueTotal(tSuper *s);

#endif