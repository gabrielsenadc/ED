#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *l = criaLista();

    l = insereProduto(l, 1);
    l = insereProduto(l, 2);
    l = insereProduto(l, 3);
    
    l = retiraProduto(l, 2);

    imprimeLista(l);

    liberaLista(l);

    return 0;
}