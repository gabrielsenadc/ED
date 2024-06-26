#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSuper.h"

int main(){
    int qtdP;
    printf("#### Cadastro de Produtos ####\n");
    printf("Quantos produtos? ");
    scanf("%d%*c", &qtdP);
    tProd **p = cadastrarProdutos(qtdP);

    char nome[100];
    printf("### Cadastro do Supermercado ###\n");
    printf("Nome do supermercado: ");
    scanf("%[^\n]%*c", nome);
    tSuper *s = criaSuper(nome, p, qtdP);

    imprimeSuper(s);

    for(int i = 0; i < qtdP; i++){
        desalocaProd(p[i]);
    }
    free(p);
    desalocaSuper(s);
}