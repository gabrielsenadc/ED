#ifndef vetor_h
#define vetor_h

#include <stdio.h>

void bubble_sort(long int *vet, long int n);

void quick_sort(long int *vet, long int n);

long int binary_search(long int *vet, long int n, int x);

long int linear_search(long int *vet, long int n, int x);

void printa_vetor(long int *vet, long int n);

#endif