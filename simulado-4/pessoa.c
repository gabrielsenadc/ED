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

void liberaPessoa(void * p){
    Pessoa * pessoa = (Pessoa *) p;
    free(pessoa->nome);
    free(pessoa);
}

void imprimePessoa(void * p, FILE * file){
    Pessoa * pessoa = (Pessoa *) p;
    fprintf(file, "%s %dP %dF\n", pessoa->nome, pessoa->p, pessoa->f);
}

int comparaPessoa(const void * pessoa1, const void * pessoa2){
    Pessoa * p1 = *(Pessoa**) pessoa1;
    Pessoa * p2 = *(Pessoa**) pessoa2;

    return strcmp(p1->nome, p2->nome);
}

int hashFunction(void * p, int size){
    Pessoa * pessoa = (Pessoa *) p;

    int total = 0;
    for(int i = 0; i < strlen(pessoa->nome); i++) total += pessoa->nome[i];

    return total % size;
}

void setPresenca(void * pes1, char p){
    Pessoa * pessoa = (Pessoa*) pes1;

    if(p == 'P') incPresenca(pessoa);
    if(p == 'F') incFalta(pessoa);
}