#include <stdio.h>
#include "tabelaRot.h"

int main(){
    Table *table = createTable(17);

    insereRot(table, 260, 397);
    insereRot(table, 22, 37);
    insereRot(table, 26, 16);
    insereRot(table, 499, 373);
    insereRot(table, 134, 98);

    FILE * file = fopen("input.txt", "r");

    int dest;
    while(fscanf(file, "%d", &dest) == 1){
        int nextHop = searchRot(table, dest);
        if(nextHop < 0) printf("There is no NextHop for this destination\n");
        else printf("Destination: %d -> NextHop: %d\n", dest, nextHop);
    }

    freeTable(table);

    fclose(file);
}