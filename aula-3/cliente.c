#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main() {
    int l = 0, c = 0;

    printf("linhas matriz 1: ");
    scanf("%d", &l);
    printf("colunas matriz 1: ");
    scanf("%d", &c);
    Matriz* mat1 = inicializaMatriz(l, c);

    printf("linhas matriz 2: ");
    scanf("%d", &l);
    printf("colunas matriz 2: ");
    scanf("%d", &c);
    Matriz* mat2 = inicializaMatriz(l, c);

    int e = 0;
    printf("elementos da matriz 1: ");
    for(int i = 0; i < recuperaNLinhas(mat1); i++){
        for(int j = 0; j < recuperaNColunas(mat1); j++){
            scanf("%d", &e);
            modificaElemento(mat1, i, j, e);
        }
    }

    printf("elementos da matriz 2: ");
    for(int i = 0; i < recuperaNLinhas(mat2); i++){
        for(int j = 0; j < recuperaNColunas(mat2); j++){
            scanf("%d", &e);
            modificaElemento(mat2, i, j, e);
        }
    }

    printf("matriz 1:\n");
    imprimeMatriz(mat1);

    printf("matriz 2:\n");
    imprimeMatriz(mat2);

    Matriz* trans1 = transposta(mat1);
    printf("transposta da matriz 1:\n");
    imprimeMatriz(trans1);

    Matriz* trans2 = transposta(mat2);
    printf("transposta da matriz 2:\n");
    imprimeMatriz(trans2);

    Matriz *mult = multiplicacao(mat1, mat2);
    printf("matriz 1 * matriz 2:\n");
    imprimeMatriz(mult);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(trans1);
    destroiMatriz(trans2);
    destroiMatriz(mult);

    return 0;
}