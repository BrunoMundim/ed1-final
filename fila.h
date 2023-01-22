#ifndef FILA_H
#define FILA_H

#include "comanda.h"
#include <stdbool.h>

#define MAX 1000

struct fila {
    Comanda elementos[MAX];
    int num_elem;
    int primeiro;
    int final;
};

typedef struct fila Fila;

Fila *criarFila();

void destruirFila(Fila *F);

bool filaVazia(Fila *F);

bool filaCheia(Fila *F);

bool insere(Fila *F, Comanda comanda);

Comanda retira(Fila *F, bool erro);

#endif