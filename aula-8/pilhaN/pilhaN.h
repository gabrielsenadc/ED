#ifndef pilhan_h
#define pilhan_h

#define MAXTAM 100

typedef int TipoItem;

typedef struct indice IndicePilha;

typedef struct pilha TipoPilhaN;

TipoPilhaN* criaPilha(int i);

void push(TipoPilhaN *pilha, TipoItem *item, int i);

TipoItem* pop(TipoPilhaN *pilha, int i);

void imprimePilhas(TipoPilhaN *p);

void liberaPilhas(TipoPilhaN *p);




#endif