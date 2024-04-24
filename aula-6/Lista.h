#ifndef Lista_h
#define Lista_h

#define CAT 0
#define DOG 1

#include <stdio.h>

typedef struct lista Lista;

Lista* criaLista();

void insereAnimal(Lista *lista, void *animal, int tipo);

void removeAnimal(Lista *lista, void *p);

void liberaLista(Lista *lista);

int existeNaLista(Lista *lista, void *p);

void imprimeLista(Lista *lista);

float calculaReceitaLista(Lista *lista);

#endif 