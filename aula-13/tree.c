#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


struct tree{
    Aluno *aluno;
    Tree *right;
    Tree *left;
};


Tree* createTree(Aluno *aluno){
    Tree *tree = malloc(sizeof(Tree));

    tree->aluno = aluno;
    tree->right = tree->left = NULL;

    return tree;
}

void printTree(Tree *tree){
    if(tree == NULL) return;

    printTree(tree->left);

    imprimeAluno(tree->aluno);

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

Tree *insertTree(Tree *tree, Aluno *aluno){
    if(tree == NULL) return createTree(aluno);

    if(retornaMat(aluno) > retornaMat(tree->aluno)) tree->right = insertTree(tree->right, aluno);
    else tree->left = insertTree(tree->left, aluno);

    return tree;
}

int search(Tree *tree, Aluno *aluno){
    if(tree == NULL) return 0;
    if(retornaMat(aluno) == retornaMat(tree->aluno)) return 1;

    if(retornaMat(aluno) > retornaMat(tree->aluno)) return search(tree->right, aluno);
    else return search(tree->left, aluno);
}

int isLeaf(Tree *tree){
    return (tree->right == NULL && tree->left == NULL);
}

Tree *removeTree(Tree *tree, int mat){
    if(tree == NULL) return tree;

    if(mat == retornaMat(tree->aluno)){
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
            
            Aluno *temp = tree->aluno;
            tree->aluno = righter->aluno;
            righter->aluno = temp;

            tree->left = removeTree(tree->left, mat); 
        }
    } 
    else if(mat > retornaMat(tree->aluno)) tree->right = removeTree(tree->right, mat);
    else tree->left = removeTree(tree->left, mat);

    return tree;
    
}

