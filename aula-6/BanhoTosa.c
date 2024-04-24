#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BanhoTosa.h"
#include "Lista.h"

struct banhotosa {
    Lista *mansos;
    Lista *bravos;
    char *nome;
};

BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa *loja = malloc(sizeof(BanhoTosa));

    loja->nome = strdup(nome);
    loja->mansos = criaLista();
    loja->bravos = criaLista();

    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    if(obtemComportamentoCachorro(dog) == MANSO) insereAnimal(loja->mansos, (void*) dog, DOG);

    if(obtemComportamentoCachorro(dog) == BRAVO) insereAnimal(loja->bravos, (void*) dog, DOG);
}

void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(obtemComportamentoCachorro(cat) == MANSO) insereAnimal(loja->mansos, (void*) cat, CAT);

    if(obtemComportamentoCachorro(cat) == BRAVO) insereAnimal(loja->bravos, (void*) cat, CAT);
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    if(obtemComportamentoGato(cat) == MANSO)
        if(existeNaLista(loja->bravos, (void*) cat)){
            removeAnimal(loja->bravos, (void*) cat);
            insereAnimal(loja->mansos, (void*) cat, CAT);
        }
    if(obtemComportamentoGato(cat) == BRAVO)
        if(existeNaLista(loja->mansos, (void*) cat)){
            removeAnimal(loja->mansos, (void*) cat);
            insereAnimal(loja->bravos, (void*) cat, CAT);
        }
}

void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    if(obtemComportamentoGato(dog) == MANSO)
        if(existeNaLista(loja->bravos, (void*) dog)){
            removeAnimal(loja->bravos, (void*) dog);
            insereAnimal(loja->mansos, (void*) dog, DOG);
        }
    if(obtemComportamentoGato(dog) == BRAVO)
        if(existeNaLista(loja->mansos, (void*) dog)){
            removeAnimal(loja->mansos, (void*) dog);
            insereAnimal(loja->bravos, (void*) dog, DOG);
        }
}