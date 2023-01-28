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
    Pilha *pilhaChocolates = criarPilhaChocolates(2); // PARA ALTERAR O NUMERO DE CHOCOLATES NA PILHA, BASTA ALTERAR O ARGUMENTO DA FUNÇÃO criarPilhaChocolates
    Fila *comandas = criarFila();    

    char decisao[2];

    // MENU
    do {
        printf("\nDeseja adicionar mais algum nome a fila? (1- SIM, 2- NAO, 3 - MAIS OPCOES) ");
        scanf("\n");
        fgets(decisao, 2, stdin);

        if(decisao[0] == '1')
            resolverComanda(comandas, pilhaChocolates);
        
        if(decisao[0] == '3'){
            char decisaoMaisOpcoes[2];

            printf("\nImprimir fila de cliente - 1\n");
            printf("Imprimir pilha de chocolates - 2\n");
            printf("SAIR - 3\n");
            printf("\nEscolha uma opcao: ");
            scanf("\n");
            fgets(decisaoMaisOpcoes, 2, stdin);
            
            if(decisaoMaisOpcoes[0] == '1') imprimirFila(comandas);

            if(decisaoMaisOpcoes[0] == '2') imprimirPilha(pilhaChocolates);

        }       
    } while(decisao[0] != '2');


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
