#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "cardapio.h"
#include "comanda.h"
#include "pilha.h"
#include "fila.h"

int main()
{   
    int decisao;
    char nome[256];

    Fila *comandas = criarFila();

    Pilha *pilhaChocolates = criarPilhaChocolates(2);

    printf("Deseja adicionar mais algum nome a fila? (1- SIM, 2- NAO) ");        
    gets(&decisao);
    while (decisao == '1'){       
        printf("Digite o nome para adicionar na fila: ");
        gets(nome);
        strcat(nome, "\r\n");

        // LOCALIZA COMANDA E CALCULA VALOR TOTAL DA COMANDA
        Comanda *comanda = localizarComandaCliente(nome);
        if(comanda->itensTotais > 0){
            strcpy(comanda->nomeCliente, nome);
            calcularTotalComanda(comanda);

            // VERIFICA SE EXISTEM CHOCOLATES NA PILHA E ADICIONA NA COMANDA CASO EXISTA
            char chocolate[100] = "";
            desempilhar(pilhaChocolates, chocolate);
            strcpy(comanda->chocolate, chocolate);

            // INSERE COMANDA NA FILA
            insere(comandas, *comanda);  
        }              

        // VERIFICA SE IRA ADICIONAR MAIS ALGUEM NA FILA
        printf("Deseja adicionar mais algum nome a fila? (1- SIM, 2- NAO) ");
        fflush(stdin);      
        gets(&decisao);
    }
    
    // Calcular total comanda
    
    while(comandas->num_elem > 0) {
        bool erro;
        Comanda comanda = retira(comandas, erro);
        printf("Cliente: %s", comanda.nomeCliente);
        printf("Valor total: %.2f\n", comanda.valorTotal);
        printf("Chocolate: %s\n\n", comanda.chocolate);
    }

    return 0;
}
