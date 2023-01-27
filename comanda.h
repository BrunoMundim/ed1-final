#ifndef COMANDA_H
#define COMANDA_H
#include "cardapio.h"

struct itemComanda{
    int id;
    int qtd;
};
typedef struct itemComanda ItemComanda;

struct comanda{
    char nomeCliente[100];
    int itensTotais;
    ItemComanda itens[20];
    float valorTotal;
    char chocolate[100];
};
typedef struct comanda Comanda;

Comanda* abrirComanda();

void adicionarItem(Comanda *comanda, ItemComanda itemComanda);

void calcularTotalComanda(Comanda* comanda);

Comanda* localizarComandaCliente(char *nome);

void imprimirComanda(Comanda comanda);

#endif