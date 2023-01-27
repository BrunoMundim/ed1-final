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
    int itensTotais;        // ARMAZENA A QUANTIDADE DE ITENS CONSUMIDOS
    ItemComanda itens[20];  // ARRAY COM OS ITENS CONSUMIDOS
    float valorTotal;
    char chocolate[100];    // ARMAZENA QUAL CHOCOLATE FOI DADO AO CLIENTE
};
typedef struct comanda Comanda;

// INICIO TAD COMANDA

// GERA UMA COMANDA
Comanda* abrirComanda();

// ADICIONA UM ITEM A COMANDA
void adicionarItem(Comanda *comanda, ItemComanda itemComanda);

// CALCULA O VALOR TOTAL DA COMANDA E ADICIONA NO FLOAT valorTotal
void calcularTotalComanda(Comanda* comanda);

// LOCALIZA A COMANDA DO CLIENTE NO comandas.txt E GERA UMA STRUCT COMANDA COM OS DADOS LOCALIZADOS
Comanda* localizarComandaCliente(char *nome);

// IMPRIME UMA COMANDA COMPLETA NA TELA
void imprimirComanda(Comanda comanda);

#endif