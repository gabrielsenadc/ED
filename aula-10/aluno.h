#ifndef aluno_h
#define aluno_h

#include <stdio.h>

typedef struct aluno Aluno;

Aluno *criaAluno(char *nome, int mat);

void imprimeAluno(Aluno *aluno);

void liberaAluno(Aluno *aluno);

int verificaNome(Aluno *aluno, char *nome);


#endif