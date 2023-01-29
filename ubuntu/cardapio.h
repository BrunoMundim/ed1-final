#ifndef CARDAPIO_H
#define CARDAPIO_H

struct itemCardapio {
    int id;
    float preco;
    char nome[100];
};
typedef struct itemCardapio ItemCardapio;

struct cardapio{
    int tamanho;
    ItemCardapio itens[1000];
};
typedef struct cardapio Cardapio;

// FUNÇÃO QUE CRIA UM CARDAPIO
Cardapio criarCardapio();

#endif