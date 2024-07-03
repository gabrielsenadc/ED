#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


struct tree{
    void *info;
    Tree *right;
    Tree *left;
    void (*imprime)(void*);
    int (*compara)(void*, void*);
};


Tree* createTree(void *info, void (*imprime)(void*), int (*compara)(void*, void*)){
    Tree *tree = malloc(sizeof(Tree));

    tree->info = info;
    tree->right = tree->left = NULL;
    tree->imprime = imprime;
    tree->compara = compara;

    return tree;
}

void printTree(Tree *tree){
    if(tree == NULL) return;

    printTree(tree->left);

    tree->imprime(tree->info);

    printTree(tree->right);

}

Tree* freeTree(Tree *tree){
    if(tree != NULL){
        freeTree(tree->left);
        freeTree(tree->right);

        free(tree);
    }
    return NULL;
}

Tree *insertTree(Tree *tree, void *info, void (*imprime)(void*), int (*compara)(void*, void*)){
    if(tree == NULL) return createTree(info, imprime, compara);

    if(tree->compara(info, tree->info) == 1) tree->right = insertTree(tree->right, info, imprime, compara);
    else tree->left = insertTree(tree->left, info, imprime, compara);

    return tree;
}

int search(Tree *tree, void *info){
    if(tree == NULL) return 0;
    if(!tree->compara(info, tree->info)) return 1;

    if(tree->compara(info, tree->info) == 1) return search(tree->right, info);
    else return search(tree->left, info);
}

int isLeaf(Tree *tree){
    return (tree->right == NULL && tree->left == NULL);
}

Tree *removeTree(Tree *tree, void *info){
    if(tree == NULL) return tree;

    if(!tree->compara(info, tree->info)){
        if(isLeaf(tree)){
            free(tree);
            return NULL;
        }

        else if(tree->right == NULL){
            Tree *temp = tree;
            tree = tree->left;
            free(temp);
        }

        else if(tree->left == NULL){
            Tree *temp = tree;
            tree = tree->right;
            free(temp);
        }

        else{
            Tree *righter = tree->left;
            while(righter->right != NULL){
                righter = righter->right;
            } 
            
            Aluno *temp = tree->info;
            tree->info = righter->info;
            righter->info = temp;

            tree->left = removeTree(tree->left, info); 
        }
    } 
    else if(tree->compara(info, tree->info) == 1) tree->right = removeTree(tree->right, info);
    else tree->left = removeTree(tree->left, info);

    return tree;
    
}

