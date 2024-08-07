#ifndef pessoa_h
#define pessoa_h

#include <stdio.h>

typedef struct pessoa Pessoa;

Pessoa * criaPessoa(char *nome);

void incFalta(Pessoa *pessoa);

void incPresenca(Pessoa *pessoa);

char * getNome(Pessoa *pessoa);

void liberaPessoa(Pessoa * pessoa);

void imprimePessoa(Pessoa * pessoa, FILE * file);

int comparaPessoa(const void * pessoa1, const void * pessoa2);

#endif