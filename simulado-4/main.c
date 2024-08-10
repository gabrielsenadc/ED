#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "hash.h"

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


    Hash * hash = criaHash(7, comparaPessoa, imprimePessoa, hashFunction, liberaPessoa, setPresenca);

    file = fopen("entrada.txt", "r");

    n = 0;
    fscanf(file, "N %d%*c", &n);

    while(fscanf(file, "%s%*c", nome) == 1){
        Pessoa * pessoa = criaPessoa(nome);
        insereHash(hash, pessoa);
    }

    char p;
    for(int i = 1; i <= n; i++){
        sprintf(fileName, "entrada%d.txt", i);
        FILE * fileFrequency = fopen(fileName, "r");
        while(fscanf(fileFrequency, "%s %c%*c", nome, &p) == 2){
            Pessoa * pessoa = criaPessoa(nome);
            setFrequencia(hash, pessoa, p);
            liberaPessoa(pessoa);
        }

        fclose(fileFrequency);
    }

    imprimeHash(hash);

    liberaHash(hash);
    fclose(file);

    return 0;
}