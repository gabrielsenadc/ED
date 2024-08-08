#include <stdlib.h>
#include <string.h>

#include "treeWord.h"

struct tree{
    char * word;
    int qtt;
    Tree * left;
    Tree * right;
};

Tree * criaTree(char * word){
    Tree * tree = malloc(sizeof(Tree));

    tree->qtt = 1;
    tree->word = strdup(word);
    tree->left = tree->right = NULL;

    return tree;
}


Tree * insertTree(Tree * tree, char * word){
    if(tree == NULL) return criaTree(word);

    if(strcmp(word, tree->word) > 0) tree->right = insertTree(tree->right, word);
    if(strcmp(word, tree->word) < 0) tree->left = insertTree(tree->left, word);
    if(strcmp(word, tree->word) == 0) tree->qtt++;

    return tree;
}

void freeTree(Tree * tree){
    if(tree == NULL) return;

    free(tree->word);
    freeTree(tree->left);
    freeTree(tree->right);

    free(tree);
}

int compareWords(const void * word1, const void * word2){
    Tree * w1 = *(Tree**) word1;
    Tree * w2 = *(Tree**) word2;

    if(w1->qtt != w2->qtt) return w1->qtt - w2->qtt;
    return strcmp(w1->word, w2->word);
}

void fillArray(Tree ** vet, Tree * tree, int * index){
    if(tree == NULL) return;

    vet[*index] = tree;
    (*index)++;

    fillArray(vet, tree->left, index);
    fillArray(vet, tree->right, index);
}

int getQttTree(Tree * tree){
    if(tree == NULL) return 0;

    return 1 + getQttTree(tree->left) + getQttTree(tree->right);
}

void printWords(Tree * tree, FILE * file){
    int qtt = getQttTree(tree), index = 0;
    Tree *vet[qtt];

    fillArray(vet, tree, &index);

    qsort(vet, qtt, sizeof(Tree*), compareWords);

    for(int i = 0; i < qtt; i++){
        fprintf(file, "%s %d\n", vet[i]->word, vet[i]->qtt);
    }
}

int getQttWords(Tree * tree){
    if(tree == NULL) return 0;

    return tree->qtt + getQttWords(tree->left) + getQttWords(tree->right);
}

int getQtt(Tree * tree){
    if(tree == NULL) return 0;

    return tree->qtt;
}

char * getWord(Tree * tree){
    return tree->word;
}

Tree * getHigherFrequency(Tree * tree){
    if(tree == NULL) return NULL;

    Tree * higherChild = getQtt(tree->left) > getQtt(tree->right) ? tree->left : tree->right;

    return getQtt(tree) > getQtt(higherChild) ? tree : higherChild;
}