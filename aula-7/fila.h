#ifndef fila_h
#define fila_h

#include "amostra.h"

typedef struct fila Fila;

Fila* criaFila();

void insereAmostra(Fila *fila, Amostra *amostra);

void inserePrerencial(Fila *fila, Amostra *amostra);

Amostra* retiraAmostra(Fila *fila);

void imprimeFila(Fila *fila);

int temAmostraFila(Fila *fila);

void liberaFila(Fila *fila);

#endif 