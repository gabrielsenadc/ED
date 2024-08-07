#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct tree{
    Tree * left;
    Tree * right;
    Pessoa * pessoa;
};

Tree * criaTree(char * nome){
    Tree * tree = malloc(sizeof(Tree));

    tree->pessoa = criaPessoa(nome);
    tree->left = tree->right = NULL;

    return tree;
}

Tree * insereTree(Tree * tree, char * nome){
    if(tree == NULL) return criaTree(nome);

    if(strcmp(nome, getNome(tree->pessoa)) > 0) tree->right = insereTree(tree->right, nome);
    else tree->left = insereTree(tree->left, nome);

    return tree;
}

void printTree(Tree * tree, FILE * file){
    if(tree == NULL) return;

    printTree(tree->left, file);
    imprimePessoa(tree->pessoa, file);
    printTree(tree->right, file);
}

void printSortedTree(Tree * tree){
    FILE * file = fopen("saida.txt", "w");

    printTree(tree, file);

    fclose(file);
}

void freeTree(Tree * tree){
    if(tree == NULL) return;

    liberaPessoa(tree->pessoa);
    freeTree(tree->left);
    freeTree(tree->right);

    free(tree);
}

void setPresence(Tree * tree, char * nome, char p){
    if(tree == NULL) return;

    if(strcmp(nome, getNome(tree->pessoa)) > 0) setPresence(tree->right, nome, p);
    if(strcmp(nome, getNome(tree->pessoa)) < 0) setPresence(tree->left, nome, p);
    if(strcmp(nome, getNome(tree->pessoa)) == 0){
        if(p == 'F') incFalta(tree->pessoa);
        else incPresenca(tree->pessoa);
    }
}

void readFrequencyFile(Tree * tree, FILE * file){
    char nome[100], p;
    while(fscanf(file, "%s %c%*c", nome, &p) == 2){
        setPresence(tree, nome, p);
    }
}

