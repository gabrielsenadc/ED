#ifndef pilhadupla_h
#define pilhadupla_h

#define MaxTam 10

typedef int TipoItem;

typedef struct indice IndicePilha;

typedef struct pilha TipoPilhaDupla;

TipoPilhaDupla* criaPilha();

void push(TipoPilhaDupla *pilha, TipoItem *item, int i);

TipoItem* pop(TipoPilhaDupla *pilha, int i);

void imprimePilhas(TipoPilhaDupla *p);

void liberaPilhas(TipoPilhaDupla *p);



#endif