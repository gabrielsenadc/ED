#ifndef Gato_h
#define Gato_h

#include <stdio.h>

typedef struct gato Gato;

Gato* inicGato(char *nome, int tipo);

int obtemComportamentoGato(Gato *dog);

void liberaGato(Gato *dog);

#endif 