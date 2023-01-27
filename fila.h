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

// GERA UM STRUCT FILA
Fila *criarFila();

// DESTROI O STRUCT FILA
void destruirFila(Fila *F);

// VERIFICA SE A FILA ESTÁ VAZIA
bool filaVazia(Fila *F);

// VERIFICA SE A FILA ESTA CHEIA
bool filaCheia(Fila *F);

// INSERE UMA COMANDA NA FILA
bool insere(Fila *F, Comanda comanda);

// RETORNA UMA COMANDA RETIRADA DA FILA
Comanda retira(Fila *F, bool erro);

<<<<<<< HEAD
// IMPRIME A FILA
=======
>>>>>>> b66e5f3a9184e7f6fd7039ca785789468ccaa544
void imprimirFila(Fila *F);

#endif