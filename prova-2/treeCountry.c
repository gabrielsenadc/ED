#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeCountry.h"

struct tree{
    Country *country;
    Tree *left;
    Tree *right;
};

Tree *criaTree(char *nome, int ouro, int prata, int bronze){
    Country *country = criaCountry(nome, ouro, prata, bronze);
    Tree *tree = malloc(sizeof(Tree));

    tree->country = country;
    tree->left = tree->right = NULL;

    return tree;
}

Tree *insereTree(Tree *tree, char *nome, int ouro, int prata, int bronze){
    if(tree == NULL) return criaTree(nome, ouro, prata, bronze);

    if(!strcmp(nome, getNome(tree->country))){
        setBronze(tree->country, bronze);
        setOuro(tree->country, ouro);
        setPrata(tree->country, prata);
    }

    if(strcmp(nome, getNome(tree->country)) > 0) tree->right = insereTree(tree->right, nome, ouro, prata, bronze);
    if(strcmp(nome, getNome(tree->country)) < 0) tree->left = insereTree(tree->left, nome, ouro, prata, bronze);

    return tree;
}

void fillArray(Country ** vet, int * index, Tree * tree){
    if(tree == NULL) return;
    
    vet[*index] = tree->country;
    (*index)++;

    fillArray(vet, index, tree->left);
    fillArray(vet, index, tree->right);
}

int countTree(Tree *tree){
    if(tree == NULL) return 0;

    return countTree(tree->left) + countTree(tree->right) + 1;
}

void criaRankTree(Tree * tree){
    FILE * file = fopen("rankTree.txt", "w");

    int qtd = countTree(tree), index = 0;
    Country * vet[qtd];

    fillArray(vet, &index, tree);
    qsort(vet, qtd, sizeof(Country*), comparaCountry);

    for(int i = 0; i < qtd; i++){
        printCountry(vet[i], file);
    }

    fclose(file);
}

void freeTree(Tree *tree){
    if(tree == NULL) return;

    freeCountry(tree->country);
    freeTree(tree->left);
    freeTree(tree->right);

    free(tree);
}