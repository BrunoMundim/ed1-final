#include "pilha.h"
#include <stdbool.h>

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
    if (pilhaCheia(*p) == true) return false;

    else {
        p->topo = p->topo + 1;
        p->elem[ p->topo ] = X;
        return true;
    }
}

bool desempilhar(Pilha *p, char *X)
{
    if (pilhaVazia(*p) == true) return false;
    
    else {
        *X = p->elem[ p->topo ];
        p->topo = p->topo - 1;
        return true;
    }
}