#include "fila.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

// GERA UM STRUCT FILA
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

// DESTROI O STRUCT FILA
void destruirFila(Fila *F)
{
    if (F != NULL) free(F);
}

// VERIFICA SE A FILA ESTÁ VAZIA
bool filaVazia(Fila *F)
{
    if (F->num_elem == 0) return true;
    else return false;
}

// VERIFICA SE A FILA ESTA CHEIA
bool filaCheia(Fila *F)
{
    if (F->num_elem == MAX) return true;
    else return false;
}

// INSERE UMA COMANDA NA FILA
bool insere(Fila *F, Comanda comanda)
{
	
	if (filaCheia(F) == true) return false;

	F->elementos[ F->final ] = comanda;
	F->num_elem = F->num_elem + 1;
	
	if (F->final == (MAX-1)) F->final = 0;
	else F->final = F->final + 1;
	
	return true;
}

// RETORNA UMA COMANDA RETIRADA DA FILA
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

// IMPRIME A FILA
void imprimirFila(Fila *F){
	Fila *F1 = criarFila();
	Comanda comanda;
	bool erro;
	for(int i = 1; filaVazia(F) == false; i++){
		printf("\nCliente %d: \n", i);
		comanda = retira(F, erro);
		imprimirComanda(comanda);
		insere(F1, comanda);
	}
	while(filaVazia(F1) == false)
		insere(F, retira(F1, erro));
}