#include <stdlib.h>
#include <string.h>
#include "hashWord.h"

typedef struct word Word;

struct hash{
    Word **tab;
    int size;
};

struct word{
    Word *next;
    char *word;
    int qtd;
};

int hashFunction(char * word, int size){
    int total = 0;
    for(int i = 0; i < strlen(word); i++) total += word[i];

    return total % size;
}

Hash * criaHash(int size){
    Hash * hash = malloc(sizeof(Hash));

    hash->tab = calloc(size, sizeof(Word*));
    hash->size = size;

    return hash;
}

void insereHash(Hash *hash, char *word){
    int index = hashFunction(word, hash->size);

    Word *aux = hash->tab[index];

    while(aux){
        if(!strcmp(aux->word, word)) break;
        aux = aux->next;
    }

    if(aux == NULL){
        aux = malloc(sizeof(Word));

        aux->word = strdup(word);
        aux->next = hash->tab[index];
        hash->tab[index] = aux;

        aux->qtd = 0;
    }

    aux->qtd++;
}

void liberaWord(Word * cell){
    if(cell == NULL) return;

    free(cell->word);
    liberaWord(cell->next);

    free(cell);
}

void liberaHash(Hash * hash){
    for(int i = 0; i < hash->size; i++){
        liberaWord(hash->tab[i]);
    }

    free(hash->tab);
    free(hash);
}

int getQtdHash(Hash * hash){
    int total = 0;
    for(int i = 0; i < hash->size; i++){
        Word * aux = hash->tab[i];
        while(aux){
            total++;
            aux = aux->next;
        }
    }

    return total;
}

int qtdWordsHash(Hash * hash){
    int total = 0;
    for(int i = 0; i < hash->size; i++){
        Word * aux = hash->tab[i];
        while(aux){
            total += aux->qtd;
            aux = aux->next;
        }
    }

    return total;
}

int getQtdWord(Word * word){
    if(word == NULL) return 0;
    return word->qtd;
}

Word * getMaiorFrequencia(Hash * hash){
    Word * higher = NULL;

    for(int i = 0; i < hash->size; i++){
        Word * aux = hash->tab[i];
        while(aux) {
            if(getQtdWord(aux) > getQtdWord(higher)) higher = aux;
            aux = aux->next;
        }
    }

    return higher;
}

int compareWordsHash(const void * word1, const void * word2){
    Word *w1 = *(Word**) word1;
    Word *w2 = *(Word**) word2;

    if(w1->qtd != w2->qtd) return w1->qtd - w2->qtd;
    return strcmp(w1->word, w2->word); 
}

void imprimeHash(Hash *hash){
    FILE * output = fopen("saidaHash.txt", "w");
    int tam = getQtdHash(hash), j = 0;

    Word *vet[tam];
    for(int i = 0; i < hash->size; i++){
        Word * aux = hash->tab[i];
        while(aux){
            vet[j] = aux;
            j++;
            aux = aux->next;
        }
    }

    qsort(vet, tam, sizeof(Word*), compareWordsHash);

    for(int i = 0; i < tam; i++){
        fprintf(output, "%s %d\n", vet[i]->word, vet[i]->qtd);
    }

    fprintf(output, "\n------------------------\n");

    fprintf(output, "%d palavras distintas encontradas\n", getQtdHash(hash));
    fprintf(output, "%d palavras no total\n", qtdWordsHash(hash));

    Word * higher = getMaiorFrequencia(hash);
    fprintf(output, "%s é a palavra de maior frequência (%d)\n", higher->word, higher->qtd);

    fclose(output);
}

