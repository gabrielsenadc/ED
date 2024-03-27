#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct matriz {
    int **matriz;
    int l, c;
} Matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* m = malloc(sizeof(Matriz));
    m->l = nlinhas;
    m->c = ncolunas;
    m->matriz = malloc(nlinhas * sizeof(int*));
    for(int i = 0; i < nlinhas; i++){
        m->matriz[i] = calloc(ncolunas, sizeof(int));  
    }
    return m;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->matriz[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->matriz[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->c;
}

int recuperaNLinhas (Matriz* mat){
    return mat->l;
}

Matriz* transposta (Matriz* mat){
    Matriz* mat2 = inicializaMatriz(mat->c, mat->l);
    
    for(int i = 0; i < mat2->l; i++){
        for(int j = 0; j < mat2->c; j++){
            modificaElemento(mat2, i, j, recuperaElemento(mat, j , i));
        }
    }

    return mat2;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1->c != mat2->l){
        printf("Erro");
        return NULL;
    }

    Matriz* mat = inicializaMatriz(mat1->l, mat2->c);
    int r = 0;

    for(int i = 0; i < mat->l; i++){
        for(int j = 0; j < mat->c; j++){
            r = 0;
            for(int k = 0; k < mat1->c; k++){
                r += (recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j));
            }
            modificaElemento(mat, i, j, r);
        }
    }

    return mat;
}

void imprimeMatriz(Matriz* mat){
    for(int i = 0; i < mat->l; i++){
       imprimeLinhas(mat, i); 
    }
}

void imprimeLinhas (Matriz* mat, int indice){
    for(int j = 0; j < mat->c; j++){
        printf("%d ", recuperaElemento(mat, indice, j));
    }
    printf("\n");
}

void destroiMatriz (Matriz* mat){
    for(int i = 0; i < mat->l; i++){
        free(mat->matriz[i]);    
    }
    free(mat->matriz);
    free(mat);
}