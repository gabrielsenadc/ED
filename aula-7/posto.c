#include <stdlib.h>
#include <string.h>
#include "posto.h"
#include "fila.h"

struct posto {
    char *nome;
    Fila *naoProcessado;
    Fila *negativo;
    Fila *positivo;
};

Posto* inicPosto(char* nome){
    Posto *posto = malloc(sizeof(Posto));

    posto->nome = strdup(nome);
    posto->naoProcessado = criaFila();
    posto->negativo = criaFila();
    posto->positivo = criaFila();

    return posto;
}

void imprimePosto(Posto* posto){
    printf("Dados do Posto: %s\n", posto->nome);

    printf("Amostras não processadas:\n");
    imprimeFila(posto->naoProcessado);

    printf("Amostras com resultados positivos:\n");
    imprimeFila(posto->positivo);

    printf("Amostra com resultados negativos:\n");
    imprimeFila(posto->negativo);

    printf("\n");
}

void realizaColeta(Posto* posto, char* pessoa, int idade){
    Amostra *amostra = inicAmostra(pessoa, idade);

    if(idade >= 60) inserePrerencial(posto->naoProcessado, amostra);
    else insereAmostra(posto->naoProcessado, amostra);
}

void processaLoteAmostras(Posto* posto){
    while(temAmostraFila(posto->naoProcessado)){
        Amostra *amostra = retiraAmostra(posto->naoProcessado);

        if(retornaCargaViral(amostra) > LIMITE_CARGA_VIRAL){
            registraResultado(amostra, POSITIVO);
            insereAmostra(posto->positivo, amostra);
        } else{
            registraResultado(amostra, NEGATIVO);
            insereAmostra(posto->negativo, amostra);
        }
    }
}

void liberaPosto(Posto* posto){
    free(posto->nome);
    liberaFila(posto->naoProcessado);
    liberaFila(posto->negativo);
    liberaFila(posto->positivo);
    free(posto);
}