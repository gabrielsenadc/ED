#include "vetor.h"

void bubble_sort(long int *vet, long int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void quick_sort(long int *vet, long int n){
    if(n <= 1) return;
    long int x = vet[0], aux;
    long int a = 1, b = n - 1;

    while(a <= b){
        while(a < n && vet[a] <= x) a++;
        while(vet[b] > x) b--;
        if(a < b){
            aux = vet[a];
            vet[a] = vet[b];
            vet[b] = aux;
            a++; b--;
        }
    }

    vet[0] = vet[b];
    vet[b] = x;

    quick_sort(vet, b);
    quick_sort(vet + a, n - a);
}

long int binary_search(long int *vet, long int n, int x){
    int inic = 0, fim = n - 1, meio;

    while(1){
        if(inic >= fim) break;
        meio = (fim + inic) / 2;
        if(vet[meio] == x) return meio;
        if(vet[meio] > x) fim = meio - 1;
        if(vet[meio] < x) inic = meio + 1;
    }

    return -1;

}

long int linear_search(long int *vet, long int n, int x){
    for(int i = 0; i < n; i++){
        if(vet[i] == x) return n;
    }

    return -1;
}

void printa_vetor(long int *vet, long int n){
    for(int i = 0; i < n; i++){
        printf("%ld ", vet[i]);
    }
    printf("\n");
}


