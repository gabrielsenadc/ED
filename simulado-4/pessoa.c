#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

struct pessoa{
    char *nome;
    int f;
    int p;
};

Pessoa * criaPessoa(char *nome){
    Pessoa * pessoa = malloc(sizeof(Pessoa));

    pessoa->nome = strdup(nome);
    pessoa->f = pessoa->p = 0;

    return pessoa;
}

void incFalta(Pessoa *pessoa){
    pessoa->f++;
}

void incPresenca(Pessoa *pessoa){
    pessoa->p++;
}

char * getNome(Pessoa *pessoa){
    return pessoa->nome;
}

void liberaPessoa(Pessoa * pessoa){
    free(pessoa->nome);
    free(pessoa);
}

void imprimePessoa(Pessoa * pessoa, FILE * file){
    fprintf(file, "%s %dP %dF\n", pessoa->nome, pessoa->p, pessoa->f);
}

int comparaPessoa(const void * pessoa1, const void * pessoa2){
    Pessoa * p1 = *(Pessoa**) pessoa1;
    Pessoa * p2 = *(Pessoa**) pessoa2;

    return strcmp(p1->nome, p2->nome);
}