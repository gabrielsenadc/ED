#include <stdio.h>
#include <stdlib.h>

#include "treeWord.h"
#include "hashWord.h"

int main(){
    Tree * tree = NULL;

    FILE * input = fopen("entrada.txt", "r");
    FILE * output = fopen("saidaTree.txt", "w");

    char word[100];
    while(fscanf(input, "%s", word) == 1) tree = insertTree(tree, word);    
    
    printWords(tree, output);

    fprintf(output, "\n------------------------\n");

    fprintf(output, "%d palavras distintas encontradas\n", getQttTree(tree));
    fprintf(output, "%d palavras no total\n", getQttWords(tree));

    Tree * higher = getHigherFrequency(tree);
    fprintf(output, "%s é a palavra de maior frequência (%d)\n", getWord(higher), getQtt(higher));

    freeTree(tree);
    fclose(input);
    fclose(output);

    input = fopen("entrada.txt", "r");

    Hash * hash = criaHash(13);

    while(fscanf(input, "%s", word) == 1) insereHash(hash, word);

    imprimeHash(hash);

    fclose(input);
    liberaHash(hash);
    
    return 0;
}