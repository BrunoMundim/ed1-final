#include "comanda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// GERA UMA COMANDA
Comanda* abrirComanda(){
    Comanda *C;
    C->itensTotais = 0;
    C->valorTotal = 0;

    return C;
}

// ADICIONA UM ITEM A COMANDA
void adicionarItem(Comanda *comanda, ItemComanda itemComanda){
    comanda->itens[comanda->itensTotais] = itemComanda;
    comanda->itensTotais++;
}


// CALCULA O VALOR TOTAL DA COMANDA E ADICIONA NO FLOAT valorTotal
void calcularTotalComanda(Comanda* comanda){
    Cardapio cardapio = criarCardapio();    
    // PRIMEIRO for CAMINHA PELOS ITENS PRESENTES NA COMANDA
    for(int i = 0; i < comanda->itensTotais; i++){
        bool flag = false;
        int id = comanda->itens[i].id;
        // SEGUNDO for CAMINHA PELOS ITENS DO CARDAPIO ATE LOCALIZAR O ITEM DA COMANDA PELO ID
        for(int j = 0; j < cardapio.tamanho; j++){
            if(id == cardapio.itens[j].id){
                flag = true;
                float preco = cardapio.itens[j].preco;
                float quantidade = comanda->itens[i].qtd;
                comanda->valorTotal += preco * quantidade;
                break;
            }
        }
        if(flag == false) // CASO NAO CONSIGA LOCALIZAR O ID DO ITEM NO CARDAPIO, MOSTRA ESSE ERRO
            printf("Comanda do cliente \"%s\" possui um item não identificado no cardápio!", comanda->nomeCliente);
    }
}

// LOCALIZA A COMANDA DO CLIENTE NO comandas.txt E GERA UMA STRUCT COMANDA COM OS DADOS LOCALIZADOS
Comanda* localizarComandaCliente(char *nome){
    // ABRINDO comandas.txt
    FILE *comandas;
    comandas = fopen("comandas.txt", "r");
    if(comandas == NULL){
        printf("Erro, comandas não localizadas!");
        exit(1);
    }

    Comanda *comanda = abrirComanda(); // CRIANDO UMA COMANDA
    
    char buffer[256]; // BUFFER UTILIZADO PARA CAMINHAR PELAS LINHAS DO ARQUIVO comandas.txt
    int flag = 0;

    while(fgets(buffer, 256, comandas)){
        // VERIFICA SE NESSE LINHA ESTA O NOME BUSCADO
        if(strcmp(buffer, nome) == 0){
            flag = 1;            
            continue;
        }

        // VERIFICA SE NESSA LINHA ESTA O DIVISOR
        if(strcmp(buffer, "-\r\n") == 0 || strcmp(buffer, "-") == 0){
            flag = 0;
        } 

        // QUANDO O NOME É IDENTIFICADO, SEGUE ESSE PROCEDIMENTO PARA ADICIONAR OS ITENS DA comandas.txt NA STRUCT COMANDA
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

<<<<<<< HEAD
// IMPRIME UMA COMANDA COMPLETA NA TELA
=======
>>>>>>> b66e5f3a9184e7f6fd7039ca785789468ccaa544
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