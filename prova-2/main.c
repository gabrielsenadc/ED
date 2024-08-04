#include <stdio.h>
#include "hashCountry.h"
#include "treeCountry.h"

int main(){
    FILE * file = fopen("input.txt", "r");

    Hash * hash = criaHash(17);
    Tree * tree = NULL;

    char nome[4];
    int ouro = 0, prata = 0, bronze = 0;
    while(fscanf(file, "%s", nome) == 1){
        fscanf(file, "%d %d %d%*c", &ouro, &prata, &bronze);

        insereHash(hash, nome, ouro, prata, bronze);
        tree = insereTree(tree, nome, ouro, prata, bronze);
    }
    
    criaRankHash(hash);
    criaRankTree(tree);

    freeHash(hash);
    freeTree(tree);

    fclose(file);
}