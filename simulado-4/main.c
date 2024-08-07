#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

int main(){
    Tree * tree = NULL;

    FILE * file = fopen("entrada.txt", "r");

    int n = 0;
    fscanf(file, "N %d%*c", &n);

    char nome[100];
    while(fscanf(file, "%s%*c", nome) == 1){
        tree = insereTree(tree, nome);
    }

    char fileName[100];
    for(int i = 1; i <= n; i++){
        sprintf(fileName, "entrada%d.txt", i);
        FILE * fileFrequency = fopen(fileName, "r");
        readFrequencyFile(tree, fileFrequency);
        fclose(fileFrequency);
    }

    printSortedTree(tree);

    freeTree(tree);
    fclose(file);

    return 0;
}