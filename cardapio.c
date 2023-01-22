#include "cardapio.h"

Cardapio criarCardapio(){
    Cardapio cardapio;
    cardapio.tamanho = 2;

    ItemCardapio item;
    item.id = 001;
    //item.nome = "Café expresso";
    item.preco = 5.7;
    cardapio.itens[0] = item;

    item.id = 002;
    //item.nome = "Pão francês com manteiga na chapa";
    item.preco = 4.6;
    cardapio.itens[1] = item;

    return cardapio;
}