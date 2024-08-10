#ifndef pessoa_h
#define pessoa_h

#include <stdio.h>

typedef struct pessoa Pessoa;

Pessoa * criaPessoa(char *nome);

void incFalta(Pessoa *pessoa);

void incPresenca(Pessoa *pessoa);

char * getNome(Pessoa *pessoa);

void liberaPessoa(void * p);

void imprimePessoa(void * p, FILE * file);

int comparaPessoa(const void * pessoa1, const void * pessoa2);

int hashFunction(void * p, int size);

void imprimePessoaTerminal(void * p);

void setPresenca(void * pes1, char p);

#endif