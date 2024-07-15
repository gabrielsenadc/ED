#include <stdio.h>
#include <stdlib.h>
#include "tabelaRot.h"

struct rot{
    int dest;
    int nextHop;

    Rot *next;
};

struct table{
    Rot **hash;
    int tam;
};

int hashFunction(Table * table, int dest){
    return dest%table->tam;
}

Table *createTable(int tam){
    Table * table = malloc(sizeof(Table));

    table->hash = calloc(tam, sizeof(Rot*));
    table->tam = tam;

    return table;
}

void insereRot(Table *table, int dest, int nextHop){
    int index = hashFunction(table, dest);

    Rot * aux = table->hash[index];

    while(aux){
        if(aux->dest == dest) break;

        aux = aux->next;
    }

    if(aux == NULL){
        Rot * rot = malloc(sizeof(Rot));

        rot->dest = dest;
        rot->nextHop = nextHop;
        rot->next = table->hash[index];
        table->hash[index] = rot;
    } else {
        aux->nextHop = nextHop;
    }

}

int searchRot(Table * table, int dest){
    int index = hashFunction(table, dest);

    Rot * rot = table->hash[index];

    while(rot){
        if(rot->dest == dest) return rot->nextHop;

        rot = rot->next;
    }

    return -1;

}

void freeTable(Table *table){
    for(int i = 0; i < table->tam; i++){
        Rot * rot = table->hash[i], * aux = NULL;
        while(rot){
            aux = rot;
            rot = rot->next;
            free(aux);
        }
    }
    free(table->hash);
    free(table);
}


