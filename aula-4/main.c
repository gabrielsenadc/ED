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

    insereFimProduto(l, arroz);
    insereFimProduto(l, banana);
    insereFimProduto(l, chocolate);
    insereFimProduto(l, feijao);

    imprimeLista(l);

    retiraProduto(l, 1);
    imprimeLista(l);

    liberaLista(l);

    liberaProduto(arroz);
    liberaProduto(chocolate);
    liberaProduto(feijao);
    liberaProduto(banana);

    return 0;
}