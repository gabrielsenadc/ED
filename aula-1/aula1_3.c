#include <stdio.h>
#include <stdlib.h>

int** inverte2 (int n, int* vet){
    int **vet2 = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        vet2[i] = &vet[i];
    }
    int *aux;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(*vet2[i] > *vet2[j]){
                aux = vet2[i];
                vet2[i] = vet2[j];
                vet2[j] = aux;
            }
        }
    }
    return vet2;
}

int main() {    
    int qtd = 0;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &qtd);
    int *vet = malloc(qtd * sizeof(int));
    printf("Digite os numeros do vetor ");
    for(int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }

    int **vet2 = inverte2(qtd, vet);
    for(int i = 0; i < qtd; i++){
        printf("%d ", *vet2[i]);
    }
    pritnf("\n");
    free(vet2);
    free(vet);
}