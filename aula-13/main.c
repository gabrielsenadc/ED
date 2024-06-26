#include <stdio.h>
#include "tree.h"

int main(){
    Aluno *gabriel = criaAluno("gabriel", 1);
    Aluno *aline = criaAluno("aline", 2);
    Aluno *eduardo = criaAluno("eduardo", 3);
    Aluno *tales = criaAluno("tales", 4);
    Aluno *marcela = criaAluno("marcela", 5);
    Aluno *malu = criaAluno("malu", 6);
    Aluno *raony = criaAluno("raony", 7);

    Tree *tree = createTree(tales);
    tree = insertTree(tree, gabriel);
    tree = insertTree(tree, marcela);
    tree = insertTree(tree, aline);
    tree = insertTree(tree, eduardo);
    tree = insertTree(tree, malu);

    printTree(tree);
    printf("\n");

    removeTree(tree, 4);

    printTree(tree);
    printf("\n");

    (search(tree, gabriel)) ? printf("Tem gabriel\n") : printf("Nao tem gabriel\n");
    (search(tree, raony)) ? printf("Tem raony\n") : printf("Nao tem raony\n");

    tree = freeTree(tree);
    liberaAluno(gabriel);
    liberaAluno(aline);
    liberaAluno(eduardo);
    liberaAluno(tales);
    liberaAluno(marcela);
    liberaAluno(malu);
    liberaAluno(raony);

}