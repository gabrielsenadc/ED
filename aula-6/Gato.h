#ifndef Gato_h
#define Gato_h

#include <stdio.h>

typedef struct gato Gato;

Gato* inicGato(char *nome, int tipo);

int obtemComportamentoGato(Gato *cat);

void liberaGato(Gato *cat);

void imprimeGato(Gato *cat);

void atribuiNivelAgressividadeGato(Gato *cat, int tipo);


#endif 