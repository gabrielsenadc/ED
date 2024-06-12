#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


struct tree{
    Aluno *aluno;
    Tree *right;
    Tree *left;
};

Tree* createTreeEmpty(){
    return NULL;
}

Tree* createTree(Aluno *aluno, Tree *left, Tree *right){
    Tree *tree = malloc(sizeof(Tree));

    tree->aluno = aluno;
    tree->right = right;
    tree->left = left;

    return tree;
}

void printTree(Tree *tree){
    if(emptyTree(tree)) return;

    printTree(tree->left);

    imprimeAluno(tree->aluno);


    printTree(tree->right);

}

Tree* freeTree(Tree *tree){
    if(!emptyTree(tree)){
        freeTree(tree->left);
        freeTree(tree->right);

        free(tree);
    }
    return NULL;
}

int thereIs(Tree *tree, Aluno *aluno){
    if(emptyTree(tree)) return 0;

    return tree->aluno == aluno || thereIs(tree->left, aluno) || thereIs(tree->right, aluno);
}

int emptyTree(Tree *tree){
    return tree == NULL;
}

int leafs(Tree *tree){
    int n = 0;
    if(emptyTree(tree->right) && emptyTree(tree->left)) return 1;

    if(!emptyTree(tree->right)) n += leafs(tree->right);
    if(!emptyTree(tree->left)) n += leafs(tree->left);

    return n;
}

int frequency(Tree *tree, char* nome){
    if(emptyTree(tree)) return 0;

    return frequency(tree->right, nome) + frequency(tree->left, nome) + verificaNome(tree->aluno, nome);
}

int height(Tree *tree){
    if(emptyTree(tree)) return 0;

    int n1 = 1 + height(tree->left);
    int n2 = 1 + height(tree->right);
    
    if(emptyTree(tree->left) && emptyTree(tree->right)) return 0;
    return (n1 > n2) ? n1 : n2;
}
