#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "word.h"

struct Word{
    char *string;
    int qtd;
};

Word *criaWord(char *string){
    Word *word = malloc(sizeof(Word));

    word->qtd = 1;
    word->string = strdup(string);

    return word;
}

char * getString(Word *word){
    return word->string;
}

void incrementaWord(Word *word){
    word->qtd++;
}

void freeWord(Word *word){
    free(word->string);
    free(word);
}

void printWord(Word *word){
    printf("%s %d\n", word->string, word->qtd);
}

int compareWords(const void * word1, const void *word2){
    Word *w1 = *(Word**) word1;
    Word *w2 = *(Word**) word2;
    return w1->qtd - w2->qtd;
}