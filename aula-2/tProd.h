#ifndef _TPROD_H_
#define _TPROD_H_

typedef struct tProd tProd;

char *obtemNome(tProd *p);

float obtemValor(tProd *p);

tProd *criaProd(char *nome, float valor);

void desalocaProd(tProd * p);

void imprimeProd(tProd * p);

#endif