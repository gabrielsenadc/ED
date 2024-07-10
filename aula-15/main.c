#include <stdio.h>
#include "hash.h"


int main(){
    Hash *hash = criaHash(17);

    FILE *file = fopen("texto.txt", "r");

    char string[501];
    while(fscanf(file, "%s", string) == 1){
        insereHash(hash, string);
    }

    printSortedHash(hash);

    liberaHash(hash);

    fclose(file);

    return 0;
}
