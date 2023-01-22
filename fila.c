#include "fila.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

Fila *criarFila()
{
	Fila *F;
	
	F = (Fila *) malloc(sizeof(Fila));
	if (F != NULL) { 
		F->num_elem = 0;
		F->primeiro = 0;
		F->final = 0;
	}
	
	return F;
}

void destruirFila(Fila *F)
{
    if (F != NULL) free(F);
}

bool filaVazia(Fila *F)
{
    if (F->num_elem == 0) return true;
    else return false;
}

bool filaCheia(Fila *F)
{
    if (F->num_elem == MAX) return true;
    else return false;
}

bool insere(Fila *F, Comanda comanda)
{
	
	if (filaCheia(F) == true) return false;

	F->elementos[ F->final ] = comanda;
	F->num_elem = F->num_elem + 1;
	
	if (F->final == (MAX-1)) F->final = 0;
	else F->final = F->final + 1;
	
	return true;
}

Comanda retira(Fila *F, bool erro)
{
	if (filaVazia(F) == true) erro = true;
	
    Comanda C = F->elementos[F->primeiro];
	F->num_elem = F->num_elem - 1;

	if (F->primeiro == (MAX - 1)) F->primeiro = 0;
	else F->primeiro = F->primeiro + 1;

    erro = false;
	return C;
}