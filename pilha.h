#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <stdio.h>

#define MAX 1000

struct pilha {
    char elem[MAX][100];
    int topo;
};
typedef struct pilha Pilha;

// GERA UMA STRUCT PILHA
Pilha *criarPilha();

// DESTROI UMA STRUCT PILHA
void destruirPilha(Pilha *p);

// VERIFICA SE A PILHA ESTA VAZIA
bool pilhaVazia(Pilha p);

// VERIFICA SE A PILHA ESTA CHEIA
bool pilhaCheia(Pilha p);

// ADICIONA UM ITEM A PILHA
bool empilhar(Pilha *p, char *X);

// REMOVE UM ITEM DA PILHA
void *desempilhar(Pilha *p, char X[100]);

// CRIA UMA PILHA DE CHOCOLATES RANDOMICA DE TAMANHO IGUAL A QUANTIDADE INFORMADA
Pilha *criarPilhaChocolates(int qtd);

// IMPRIME A PILHA
void imprimirPilha(Pilha *P);

#endif