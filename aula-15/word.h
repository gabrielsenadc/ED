#ifndef word_h
#define word_h

#include <stdio.h>

typedef struct Word Word;

Word *criaWord(char *string);

char * getString(Word *word);

void incrementaWord(Word *word);

void freeWord(Word *word);

void printWord(Word *word);

int compareWords(const void * word1, const void *word2);


#endif 