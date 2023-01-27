#include "comanda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Comanda* abrirComanda(){
    Comanda *C;
    C->itensTotais = 0;
    C->valorTotal = 0;

    return C;
}

void adicionarItem(Comanda *comanda, ItemComanda itemComanda){
    comanda->itens[comanda->itensTotais] = itemComanda;
    comanda->itensTotais++;
}

void calcularTotalComanda(Comanda* comanda){
    Cardapio cardapio = criarCardapio();
    for(int i = 0; i < comanda->itensTotais; i++){
        int id = comanda->itens[i].id;
        for(int j = 0; j < cardapio.tamanho; j++){
            if(id == cardapio.itens[j].id){
                float preco = cardapio.itens[j].preco;
                float quantidade = comanda->itens[i].qtd;
                comanda->valorTotal += preco * quantidade;
                break;
            }
        }
    }
}

// Localizar cliente pelo nome, e criar a comanda
Comanda* localizarComandaCliente(char *nome){
    // Abrindo arquivos das comandas
    FILE *comandas;
    comandas = fopen("comandas.txt", "r");
    if(comandas == NULL){
        printf("Erro, comandas não localizadas!");
        exit(1);
    }

    Comanda *comanda = abrirComanda(); // Criando struct da comanda
    
    char buffer[256]; // Buffer utilizado para caminhar ao longo do arquivo comandas
    int flag = 0;

    while(fgets(buffer, 256, comandas)){
        if(strcmp(buffer, nome) == 0){
            flag = 1;            
            continue;
        }

        if(strcmp(buffer, "-\r\n") == 0 || strcmp(buffer, "-") == 0){
            flag = 0;
        } 

        if(flag == 1){
            char *token = strtok(buffer, " ");
            ItemComanda itemComanda;
            itemComanda.id = atoi(token);
            token = strtok(NULL, " ");
            itemComanda.qtd = atoi(token);
            adicionarItem(comanda, itemComanda);
        }      
    }

    return comanda;
}

void imprimirComanda(Comanda comanda){
    Cardapio cardapio = criarCardapio();
    printf("Nome cliente: %s", comanda.nomeCliente);    

    for(int i = 0; i < comanda.itensTotais; i++){
        int id = comanda.itens[i].id;
        for(int j = 0; j < cardapio.tamanho; j++){
            if(id == cardapio.itens[j].id){
                printf("Item %d: x%d %s \n", (i+1), comanda.itens[i].qtd, cardapio.itens[j].nome);
                break;
            }
        }
    }

    printf("Valor total: %.2f\n", comanda.valorTotal);
    printf("Chocolate brinde: %s\n", comanda.chocolate);
}