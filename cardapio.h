#ifndef CARDAPIO_H
#define CARDAPIO_H

struct itemCardapio {
    int id;
    float preco;
};
typedef struct itemCardapio ItemCardapio;

struct cardapio{
    int tamanho;
    ItemCardapio itens[1000];
};
typedef struct cardapio Cardapio;

Cardapio criarCardapio();

#endif