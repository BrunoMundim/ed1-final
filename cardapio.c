#include "cardapio.h"
#include <string.h>

// ESSA FUNÇÃO GERA UM CARDÁPIO (14 itens no total)
Cardapio criarCardapio(){
    Cardapio cardapio;
    cardapio.tamanho = 14;

    ItemCardapio item;
<<<<<<< HEAD
    item.id = 1;
=======
    item.id = 001;
>>>>>>> b66e5f3a9184e7f6fd7039ca785789468ccaa544
    strcpy(item.nome, "Café expresso");
    item.preco = 5.7;
    cardapio.itens[0] = item;

<<<<<<< HEAD
    item.id = 2;
    strcpy(item.nome, "Pingado");
    item.preco = 2.5;
=======
    item.id = 002;
    strcpy(item.nome, "Pão francês com manteiga na chapa");
    item.preco = 4.6;
>>>>>>> b66e5f3a9184e7f6fd7039ca785789468ccaa544
    cardapio.itens[1] = item;

    item.id = 3;
    strcpy(item.nome, "Pão na chapa c/ manteiga");
    item.preco = 4;
    cardapio.itens[2] = item;

    item.id = 4;
    strcpy(item.nome, "Pão na chapa c/ requeijão");
    item.preco = 6.6;
    cardapio.itens[3] = item;

    item.id = 5;
    strcpy(item.nome, "Croissant");
    item.preco = 7.8;
    cardapio.itens[4] = item;

    item.id = 6;
    strcpy(item.nome, "Croissant de queijo");
    item.preco = 9.2;
    cardapio.itens[5] = item;

    item.id = 7;
    strcpy(item.nome, "Croissant de frango");
    item.preco = 9.2;
    cardapio.itens[6] = item;

    item.id = 8;
    strcpy(item.nome, "Coxinha de frango c/ catupiry");
    item.preco = 9.7;
    cardapio.itens[7] = item;

    item.id = 9;
    strcpy(item.nome, "Coxinha de camarão");
    item.preco = 16.9;
    cardapio.itens[8] = item;

    item.id = 10;
    strcpy(item.nome, "Croissant com Nutella");
    item.preco = 15.8;
    cardapio.itens[9] = item;

    item.id = 11;
    strcpy(item.nome, "Coca-cola lata 300mL");
    item.preco = 4;
    cardapio.itens[10] = item;

    item.id = 12;
    strcpy(item.nome, "Coca-cola 600mL");
    item.preco = 6;
    cardapio.itens[11] = item;

    item.id = 13;
    strcpy(item.nome, "Coca-cola 1000mL");
    item.preco = 8;
    cardapio.itens[12] = item;

    item.id = 14;
    strcpy(item.nome, "Guaraná mineiro 600mL");
    item.preco = 5;
    cardapio.itens[13] = item;

    return cardapio;
}