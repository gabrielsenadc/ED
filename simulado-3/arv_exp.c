#include <stdio.h>
#include <stdlib.h>
#include "arv_exp.h"

struct arv{
    int num;
    char op;
    Arv *left;
    Arv *right;
};

Arv* CriaVazia(void){
    return NULL;
}

Arv* CriaOperador(char c, Arv* esq, Arv* dir){
    Arv *tree = malloc(sizeof(Arv));

    tree->num = 0;
    tree->op = c;
    tree->left = esq;
    tree->right = dir;

    return tree;
}

Arv* CriaOperando(int valor){
    Arv *tree = malloc(sizeof(Arv));

    tree->num = valor;
    tree->op = '\0';
    tree->left = tree->right = NULL;

    return tree;
}

void Imprime(Arv* arv){
    if(arv == NULL) return;

    if(arv->left != NULL) printf("(");
    Imprime(arv->left);
    
    if(arv->left == NULL) printf("%d", arv->num);
    else printf("%c", arv->op);

    Imprime(arv->right);
    if(arv->left != NULL) printf(")");
}

Arv* Libera (Arv* arv){
    if(arv == NULL) return NULL;

    arv->left = Libera(arv->left);
    arv->right = Libera(arv->right);

    free(arv);

    return NULL;
}

float Avalia(Arv* arv){
    if(arv->left == NULL) return arv->num;

    int num1 = Avalia(arv->left);
    int num2 = Avalia(arv->right);

    switch (arv->op){
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '-': return num1 - num2;
        case '+': return num1 + num2;
    }
}

int Folhas(Arv* arv){
    if(arv->left == NULL && arv->right == NULL) return 1;
    return Folhas(arv->left) + Folhas(arv->right);
}

int Altura(Arv* arv){
    int hL = 0, hR = 0;

    if(arv->left) hL = Altura(arv->left) + 1;
    if(arv->right) hR = Altura(arv->right) + 1;

    return hL > hR ? hL : hR;
}