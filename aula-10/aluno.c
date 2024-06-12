#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char *nome;
    int mat;
};

Aluno *criaAluno(char *nome, int mat){
    Aluno *aluno = malloc(sizeof(Aluno));

    aluno->nome = strdup(nome);
    aluno->mat = mat;

    return aluno;
}

void imprimeAluno(Aluno *aluno){
    printf("%s: %d; ", aluno->nome, aluno->mat);
}

void liberaAluno(Aluno *aluno){
    free(aluno->nome);
    free(aluno);
}

int verificaNome(Aluno *aluno, char *nome){
    return !strcmp(aluno->nome, nome);
}