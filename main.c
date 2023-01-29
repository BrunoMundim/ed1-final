#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "cardapio.h"
#include "comanda.h"
#include "pilha.h"
#include "fila.h"

// FUNÇÃO RESPONSAVEL POR LIDAR COM A ADIÇÃO DE NOVOS CLIENTES A FILA
void resolverComanda(Fila *comandas, Pilha *chocolates){
    char nome[256];

    printf("Digite o nome para adicionar na fila: ");
    scanf("\n");
    fgets(nome, 256, stdin);

    // LOCALIZA COMANDA CLIENTE
    Comanda *comanda = localizarComandaCliente(nome);

    // VERIFICA SE O CLIENTE CONSUMIU
    if(comanda->itensTotais > 0){
        // ADICIONA NOME DO CLIENTE A COMANDA
        strcpy(comanda->nomeCliente, nome);

        calcularTotalComanda(comanda);

        // VERIFICA SE EXISTEM CHOCOLATES NA PILHA E ADICIONA NA COMANDA
        char chocolate[100] = "";
        desempilhar(chocolates, chocolate);
        strcpy(comanda->chocolate, chocolate);

        // INSERE COMANDA NA FILA
        insere(comandas, *comanda);
    }   
}

int main()
{
    char qtdChocolates[1000];
    printf("Quantos chocolates existirão na pilha: ");
    fgets(qtdChocolates, 1000, stdin);    
    printf("Gerando chocolates randômicos...\n");
    Pilha *pilhaChocolates = criarPilhaChocolates(atoi(qtdChocolates)); // PARA ALTERAR O NUMERO DE CHOCOLATES NA PILHA, BASTA ALTERAR O ARGUMENTO DA FUNÇÃO criarPilhaChocolates
    Fila *comandas = criarFila();    

    char decisao[1000];
    bool flagDecisao = false;
    // MENU
    do {
        printf("\nO que deseja fazer? (1- ADICIONAR CLIENTE A FILA, 2- MAIS OPCOES, 3- SAIR) ");
        scanf("\n");
        fgets(decisao, 1000, stdin);

        if(decisao[0] == '1' && decisao[1] == '\n')
            resolverComanda(comandas, pilhaChocolates);
        
        if(decisao[0] == '2' && decisao[1] == '\n'){
            char decisaoMaisOpcoes[2];

            printf("\nImprimir fila de cliente - 1\n");
            printf("Imprimir pilha de chocolates - 2\n");
            printf("SAIR - 3\n");
            printf("\nEscolha uma opcao: ");
            scanf("\n");
            fgets(decisaoMaisOpcoes, 2, stdin);
            
            if(decisaoMaisOpcoes[0] == '1' && decisao[1] == '\n') imprimirFila(comandas);

            if(decisaoMaisOpcoes[0] == '2' && decisao[1] == '\n') imprimirPilha(pilhaChocolates);

        }  
        if(decisao[0] == '3' && decisao[1] == '\n') flagDecisao = true;
    } while(flagDecisao == false);


    // IMPRIMIR NOME, VALOR TOTAL E CHOCOLATE DE TODOS CLIENTES DA FILA, SEMPRE FAZ SE HOUVEREM CLIENTES NA FILA
    while(comandas->num_elem > 0) {
        bool erro = false;
        Comanda comanda = retira(comandas, erro);
        printf("\nCliente: %s", comanda.nomeCliente);
        printf("Valor total: %.2f\n", comanda.valorTotal);
        printf("Chocolate: %s\n", comanda.chocolate);
    }

    return 0;
}
