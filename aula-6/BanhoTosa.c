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
    if(obtemComportamentoGato(cat) == MANSO) insereAnimal(loja->mansos, (void*) cat, CAT);

    if(obtemComportamentoGato(cat) == BRAVO) insereAnimal(loja->bravos, (void*) cat, CAT);
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
    if(obtemComportamentoCachorro(dog) == MANSO)
        if(existeNaLista(loja->bravos, (void*) dog)){
            removeAnimal(loja->bravos, (void*) dog);
            insereAnimal(loja->mansos, (void*) dog, DOG);
        }
    if(obtemComportamentoCachorro(dog) == BRAVO)
        if(existeNaLista(loja->mansos, (void*) dog)){
            removeAnimal(loja->mansos, (void*) dog);
            insereAnimal(loja->bravos, (void*) dog, DOG);
        }
}

void imprimeBanhoTosa(BanhoTosa* loja){
    printf("Nome da loja: %s\n", loja->nome);

    printf("Animais mansos:\n");
    imprimeLista(loja->mansos);

    printf("Animais agressivos:\n");
    imprimeLista(loja->bravos);
}

float calculaReceita(BanhoTosa* loja){
    float valor = 0;

    valor += calculaReceitaLista(loja->mansos);
    valor += calculaReceitaLista(loja->bravos);

    return valor;
}

void liberaBanhoTosa(BanhoTosa* loja){
    liberaLista(loja->bravos);
    liberaLista(loja->mansos);

    free(loja->nome);
    
    free(loja);
}