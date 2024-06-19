#include <stdio.h>
#include "vetor.h"
#include <stdlib.h>

int main(){
    long int n = 100000;
    long int vet[n];
    for(long int i = 0; i < n; i++){
        vet[i] = rand() % 100;
    }

    quick_sort(vet, n);

    printa_vetor(vet, n);

    printf("Posicao do 11: %ld\n", binary_search(vet, n, 11));

    return 0;
}