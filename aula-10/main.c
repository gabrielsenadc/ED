#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "aluno.h"

int main(){
    Aluno *gabriel = criaAluno("gabriel", 1);
    Aluno *aline = criaAluno("aline", 2);
    Aluno *eduardo = criaAluno("eduardo", 3);
    Aluno *tales = criaAluno("tales", 4);
    Aluno *mona = criaAluno("tales", 5);
    Aluno *malu = criaAluno("malu", 5);

    Tree *tree = createTree(gabriel, 
                            createTree(aline,
                                createTree(tales, 
                                    createTreeEmpty(), 
                                    createTreeEmpty()), 
                                createTree(mona, 
                                    createTreeEmpty(), 
                                    createTreeEmpty())),
                            createTree(eduardo, 
                                createTreeEmpty(), 
                                createTreeEmpty()));

    printTree(tree);
    printf("\n");

    printf("folhas: %d\n", leafs(tree));
    printf("n de tales: %d\n", frequency(tree, "tales"));
    printf("altura: %d\n", height(tree));
    (thereIs(tree, gabriel)) ? printf("Tem gabriel\n") : printf("Nao tem gabriel\n");
    (thereIs(tree, malu)) ? printf("Tem malu\n") : printf("Nao tem malu\n");

    tree = freeTree(tree);
    liberaAluno(gabriel);
    liberaAluno(aline);
    liberaAluno(eduardo);
    liberaAluno(tales);
    liberaAluno(mona);
    liberaAluno(malu);
}
