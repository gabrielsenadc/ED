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

void imprimeAluno(void *info){
    Aluno *aluno = (Aluno*) info;
    printf("%s: %d; ", aluno->nome, aluno->mat);
}

void liberaAluno(Aluno *aluno){
    free(aluno->nome);
    free(aluno);
}

int comparaAluno(void *info1, void *info2){
    Aluno *aluno1 = (Aluno*) info1, *aluno2 = (Aluno*) info2;

    if(aluno1->mat == aluno2->mat) return 0;

    if(aluno1->mat > aluno2->mat) return 1;
    else return -1;
    
}