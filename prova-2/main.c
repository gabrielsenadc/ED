#include <stdio.h>
#include "hashCountry.h"
#include "treeCountry.h"

int main(){
    FILE * file = fopen("input.txt", "r");

    Hash * hash = criaHash(13);
    Tree * tree = NULL;

    char nome[4];
    int ouro = 0, prata = 0, bronze = 0;
    while(fscanf(file, "%s", nome) == 1){
        fscanf(file, "%d %d %d%*c", &ouro, &prata, &bronze);

        if(prata == 0 && bronze == 0 && ouro == 0) tree = removeTree(tree, nome);
        else tree = insereTree(tree, nome, ouro, prata, bronze);

        if(prata == 0 && bronze == 0 && ouro == 0) removeHash(hash, nome);
        else insereHash(hash, nome, ouro, prata, bronze);
    }
    
    criaRankHash(hash);
    criaRankTree(tree);

    freeHash(hash);
    freeTree(tree);

    fclose(file);
}