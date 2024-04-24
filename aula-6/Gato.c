#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Gato.h"

struct gato {
    char *nome;
    int comportamento;
};

Gato* inicGato(char *nome, int comportamento){
    Gato *cat = malloc(sizeof(Gato));

    cat->nome = strdup(nome);
    cat->comportamento = comportamento;

    return cat;
}

int obtemComportamentoGato(Gato *cat){
    return cat->comportamento;
}

void liberaGato(Gato *cat){
    free(cat->nome);
    free(cat);
}

void imprimeGato(Gato *cat){
    printf("gato %s\n", cat->nome);
}

void atribuiNivelAgressividadeGato(Gato *cat, int tipo){
    cat->comportamento = tipo;
}