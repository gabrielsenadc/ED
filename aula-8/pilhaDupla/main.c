#include <stdio.h>
#include <stdlib.h>
#include "pilhaDupla.h"

void LerNum(TipoPilhaDupla *pilha, int i){
    int * num = malloc(sizeof(TipoItem));
    scanf("%d", num);

    if(i % 2 == 0) push(pilha, num, 1);
    else push(pilha, num, 2);
}

int main(){
    TipoPilhaDupla *pilha = criaPilha();

    for(int i = 0; i < 11; i++){
       LerNum(pilha, i);
    }

    imprimePilhas(pilha);

    TipoItem *num = pop(pilha, 1);
    push(pilha, num, 2);

    imprimePilhas(pilha);

    liberaPilhas(pilha);
    return 0;
}