#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define  MAX 1000

// TAD PILHA

struct pilha {
    char elem[MAX];
    int topo;
};

typedef struct pilha Pilha;

void criarPilha(Pilha *p)
{
    p->topo = -1;
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

bool empilhar(Pilha *p, char X)
{
    if (cheia(*p) == true) return false;

    else {
        p->topo = p->topo + 1;
        p->elem[ p->topo ] = X;
        return true;
    }
}

bool desempilhar(Pilha *p, char *X)
{
    if (vazia(*p) == true) return false;
    
    else {
        *X = p->elem[ p->topo ];
        p->topo = p->topo - 1;
        return true;
    }
}

// FIM TAD PILHA

// TAD FILA

struct fila {
    char elementos[MAX];
    int num_elem;
    int primeiro;
    int final;
};

typedef struct fila Fila;

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

bool insere(Fila *F, char X)
{
	
	if (filaCheia(F) == true) return false;

	F->elementos[ F->final ] = X;
	F->num_elem = F->num_elem + 1;
	
	if (F->final == (MAX-1)) F->final = 0;
	else F->final = F->final + 1;
	
	return true;
}

bool retira(Fila *F, char *X)
{
	if (filaVazia(F) == true) return false;
	
	*X = F->elementos[ F->primeiro ];
	F->num_elem = F->num_elem - 1;

	if (F->primeiro == (MAX - 1)) F->primeiro = 0;
	else F->primeiro = F->primeiro + 1;

	return true;
}

// FIM TAD FILA