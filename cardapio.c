#include "cardapio.h"
#include <string.h>

Cardapio criarCardapio(){
    Cardapio cardapio;
    cardapio.tamanho = 2;

    ItemCardapio item;
    item.id = 001;
    strcpy(item.nome, "Café expresso");
    item.preco = 5.7;
    cardapio.itens[0] = item;

    item.id = 002;
    strcpy(item.nome, "Pão francês com manteiga na chapa");
    item.preco = 4.6;
    cardapio.itens[1] = item;

    return cardapio;
}