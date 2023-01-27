#include "pilha.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// LISTA DOS CHOCOLATES POSSIVEIS DA PILHA
char listaChocolates[5][100] = {"Diamante negro", "Laka", "Sonho de valsa", "Ouro branco", "KitKat"};

// GERA UMA STRUCT PILHA
Pilha *criarPilha()
{
    Pilha *P;
	
	P = (Pilha *) malloc(sizeof(Pilha));
	if (P != NULL) { 
		P->topo = -1;
	}
	
	return P;
}

// DESTROI UMA STRUCT PILHA
void destruirPilha(Pilha *p)
{
    p->topo = -1;
}

// VERIFICA SE A PILHA ESTA VAZIA
bool pilhaVazia(Pilha p)
{
    if (p.topo == -1) return true;
    else return false;
}

// VERIFICA SE A PILHA ESTA CHEIA
bool pilhaCheia(Pilha p)
{
    if (p.topo == (MAX - 1)) return true;
    else return false;
}

// ADICIONA UM ITEM A PILHA
bool empilhar(Pilha *p, char *X)
{
    if (pilhaCheia(*p) == true) return false;

    else {
        p->topo = p->topo + 1;
        strcpy(p->elem[p->topo], X);
        return true;
    }
}

// REMOVE UM ITEM DA PILHA
void *desempilhar(Pilha *p, char X[100])
{
    if (pilhaVazia(*p) == true) 
        strcpy(X, "Sem chocolate :(");
    
    else {
        strcpy(X, p->elem[p->topo]);
        p->topo = p->topo - 1;
    }
}

// CRIA UMA PILHA DE CHOCOLATES RANDOMICA DE TAMANHO IGUAL A QUANTIDADE INFORMADA
Pilha *criarPilhaChocolates(int qtd){
    srand(time(NULL));
    Pilha *P = criarPilha();

    for(int i = 0; i < qtd; i++){
        empilhar(P, listaChocolates[rand() % 4]); // EMPILHA UM CHOCOLATE RANDOMICO DA LISTA DE POSSIVEIS CHOCOLATES (LINHA 7)
    }

    return P;
}

// IMPRIME A PILHA
void imprimirPilha(Pilha *P){
    Pilha *P1 = criarPilha();
    char *chocolate;
    printf("\nPilha: ");

    // REMOVE OS ITENS DA PILHA, IMPRIME NA TELA E EMPILHA EM UM PILHA AUXILIAR
    while(pilhaVazia(*P) == false){
        desempilhar(P, chocolate);
        empilhar(P1, chocolate);
        printf("\"%s\"", chocolate);        
    }

    // VOLTA OS ITENS PARA A PILHA ORIGINAL
    while(pilhaVazia(*P1) == false){
        desempilhar(P1, chocolate);
        empilhar(P, chocolate);
    }
    printf("\n");
}