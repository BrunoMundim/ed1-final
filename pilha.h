#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX 1000

struct pilha {
    char elem[MAX];
    int topo;
};

typedef struct pilha Pilha;

void criarPilha(Pilha *p);

void destruirPilha(Pilha *p);

bool pilhaVazia(Pilha p);

bool pilhaCheia(Pilha p);

bool empilhar(Pilha *p, char X);

bool desempilhar(Pilha *p, char *X);

#endif