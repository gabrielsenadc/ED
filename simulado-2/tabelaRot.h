#ifndef _tabelaRot_h_
#define _tabelaRot_h_

#include <stdio.h>

typedef struct rot Rot;

typedef struct table Table;

Table *createTable(int tam);

void insereRot(Table *table, int dest, int nextHop);

int searchRot(Table * table, int dest);

void freeTable(Table *table);



#endif
