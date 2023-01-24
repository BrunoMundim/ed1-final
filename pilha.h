#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX 1000

struct pilha {
    char elem[MAX][100];
    int topo;
};
typedef struct pilha Pilha;

Pilha *criarPilha();

void destruirPilha(Pilha *p);

bool pilhaVazia(Pilha p);

bool pilhaCheia(Pilha p);

bool empilhar(Pilha *p, char *X);

void *desempilhar(Pilha *p, char X[100]);

Pilha *criarPilhaChocolates(int qtd);

#endif