#include <stdio.h>
#include "hashCountry.h"

int main(){
    FILE * file = fopen("input.txt", "r");

    Hash * hash = criaHash(17);

    char nome[4];
    int ouro = 0, prata = 0, bronze = 0;
    while(fscanf(file, "%s", nome) == 1){
        fscanf(file, "%d %d %d%*c", &ouro, &prata, &bronze);

        insereHash(hash, nome, ouro, prata, bronze);
    }
    
    criaRank(hash);

    freeHash(hash);

    fclose(file);
}