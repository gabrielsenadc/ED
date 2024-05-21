#include <stdio.h>
#include <stdlib.h>
#include "pilhaN.h"

void LerNum(TipoPilhaN *pilha){
    int i;
    int * num = malloc(sizeof(TipoItem));
    scanf("%d %d", num, &i);

    push(pilha, num, i);
}

int main(){
    TipoPilhaN *pilha = criaPilha(10);

    for(int i = 0; i < 11; i++){
       LerNum(pilha);
    }

    imprimePilhas(pilha);

    TipoItem *num = pop(pilha, 4);
    push(pilha, num, 5);

    imprimePilhas(pilha);

    liberaPilhas(pilha);

    return 0;
}