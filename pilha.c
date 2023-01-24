#include "pilha.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char listaChocolates[5][100] = {"Diamante negro", "Laka", "Sonho de valsa", "Ouro branco", "KitKat"};

Pilha *criarPilha()
{
    Pilha *P;
	
	P = (Pilha *) malloc(sizeof(Pilha));
	if (P != NULL) { 
		P->topo = -1;
	}
	
	return P;
}

void destruirPilha(Pilha *p)
{
    p->topo = -1;
}

bool pilhaVazia(Pilha p)
{
    if (p.topo == -1) return true;
    else return false;
}

bool pilhaCheia(Pilha p)
{
    if (p.topo == (MAX - 1)) return true;
    else return false;
}

bool empilhar(Pilha *p, char *X)
{
    if (pilhaCheia(*p) == true) return false;

    else {
        p->topo = p->topo + 1;
        strcpy(p->elem[p->topo], X);
        return true;
    }
}

void *desempilhar(Pilha *p, char X[100])
{
    if (pilhaVazia(*p) == true) 
        strcpy(X, "Sem chocolate :(");
    
    else {
        strcpy(X, p->elem[p->topo]);
        p->topo = p->topo - 1;
    }
}

Pilha *criarPilhaChocolates(int qtd){
    Pilha *P = criarPilha();

    for(int i = 0; i < qtd; i++){
        empilhar(P, listaChocolates[rand() % 4]);
    }

    return P;
}