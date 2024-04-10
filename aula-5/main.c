#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    Lista *l = criaLista();

    Produto *arroz = criaProduto(1, "arroz", 10);
    Produto *banana = criaProduto(2, "banana", 7);
    Produto *chocolate = criaProduto(3, "chocolate", 15);
    Produto *feijao = criaProduto(4, "feijao", 9);

    l = insereProduto(l, arroz);
    l = insereProduto(l, banana);
    l = insereProduto(l, chocolate);
    l = insereProduto(l, feijao);

    imprimeLista(l);

    l = retiraProduto(l, 1);
    imprimeLista(l);

    l = retiraProduto(l, 2);
    l = retiraProduto(l, 3);
    l = retiraProduto(l, 4);
    imprimeLista(l);

    liberaLista(l);

    liberaProduto(arroz);
    liberaProduto(chocolate);
    liberaProduto(feijao);
    liberaProduto(banana);

    return 0;
}