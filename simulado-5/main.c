#include <stdio.h>
#include <stdlib.h>

#include "treeWord.h"

int main(){
    Tree * tree = NULL;

    FILE * input = fopen("entrada.txt", "r");
    FILE * output = fopen("saida.txt", "w");

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

    return 0;
}