#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


#define MAX 1000


// CARDAPIO


struct itemCardapio {
    int id;
    float preco;
    char nome[100];
};
typedef struct itemCardapio ItemCardapio;


struct cardapio{
    int tamanho;
    ItemCardapio itens[MAX];
};
typedef struct cardapio Cardapio;


// ESSA FUNÇÃO GERA UM CARDÁPIO (14 itens no total)
Cardapio criarCardapio(){
    Cardapio cardapio;
    cardapio.tamanho = 14;


    ItemCardapio item;
    item.id = 1;
    strcpy(item.nome, "Cafe expresso");
    item.preco = 5.7;
    cardapio.itens[0] = item;


    item.id = 2;
    strcpy(item.nome, "Pingado");
    item.preco = 2.5;
    cardapio.itens[1] = item;


    item.id = 3;
    strcpy(item.nome, "Pao na chapa c/ manteiga");
    item.preco = 4;
    cardapio.itens[2] = item;


    item.id = 4;
    strcpy(item.nome, "Pao na chapa c/ requeijao");
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
    strcpy(item.nome, "Coxinha de camarao");
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


// CARDAPIO FIM


// COMANDA INICIO


struct itemComanda{
    int id;
    int qtd;
};
typedef struct itemComanda ItemComanda;


struct comanda{
    char nomeCliente[100];
    int itensTotais;        // ARMAZENA A QUANTIDADE DE ITENS CONSUMIDOS
    ItemComanda itens[20];  // ARRAY COM OS ITENS CONSUMIDOS
    float valorTotal;
    char chocolate[100];    // ARMAZENA QUAL CHOCOLATE FOI DADO AO CLIENTE
};
typedef struct comanda Comanda;


// GERA UMA COMANDA
Comanda* abrirComanda(){
    Comanda *C = malloc(sizeof(Comanda));
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
            printf("Comanda do cliente \"%s\" possui um item nao identificado no cardápio!", comanda->nomeCliente);
    }
}


// LOCALIZA A COMANDA DO CLIENTE NO comandas.txt E GERA UMA STRUCT COMANDA COM OS DADOS LOCALIZADOS
Comanda* localizarComandaCliente(char *nome){
    // CORRIGINDO
    nome[strlen(nome) - 1] = '\0';
    strcat(nome, "\n");
    


    // ABRINDO comandas.txt
    FILE *comandas;
    comandas = fopen("comandas.txt", "r");
    if(comandas == NULL){
        
        exit(1);
    }


    Comanda *comanda = abrirComanda(); // CRIANDO UMA COMANDA
    
   
    char buffer[256]; // BUFFER UTILIZADO PARA CAMINHAR PELAS LINHAS DO ARQUIVO comandas.txt
    int flag = 0;

    while(fgets(buffer, 256, comandas)){
        // VERIFICA SE NESSE LINHA ESTA O NOME BUSCADO
       

        if(strcmp(nome, buffer) == 0){
            flag = 1;       
            continue;
        }


        // VERIFICA SE NESSA LINHA ESTA O DIVISOR
        if(strcmp(buffer, "-\n") == 0 || strcmp(buffer, "-") == 0){
            flag = 0;
        }


        // QUANDO O NOME E IDENTIFICADO, SEGUE ESSE PROCEDIMENTO PARA ADICIONAR OS ITENS DA comandas.txt NA STRUCT COMANDA
        if(flag == 1){
            char *token = strtok(buffer," ");
           
            ItemComanda itemComanda;
            itemComanda.id = atoi(token);
            token = strtok(NULL, " ");
           
            itemComanda.qtd = atoi(token);
            adicionarItem(comanda, itemComanda);
        }      
    }

    return comanda;
}


// IMPRIME UMA COMANDA COMPLETA NA TELA
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


// COMANDA FIM


// FILA INICIO


struct fila {
    Comanda elementos[MAX];
    int num_elem;
    int primeiro;
    int final;
};
typedef struct fila Fila;


// GERA UM STRUCT FILA
Fila *criarFila()
{
    Fila *F;
   
    F = (Fila *) malloc(sizeof(Fila));
    if (F != NULL) {
        F->num_elem = 0;
        F->primeiro = 0;
        F->final = 0;
    }
   
    return F;
}


// DESTROI O STRUCT FILA
void destruirFila(Fila *F)
{
    if (F != NULL) free(F);
}


// VERIFICA SE A FILA ESTÁ VAZIA
bool filaVazia(Fila *F)
{
    if (F->num_elem == 0) return true;
    else return false;
}


// VERIFICA SE A FILA ESTA CHEIA
bool filaCheia(Fila *F)
{
    if (F->num_elem == MAX) return true;
    else return false;
}


// INSERE UMA COMANDA NA FILA
bool insere(Fila *F, Comanda comanda)
{
   
    if (filaCheia(F) == true) return false;


    F->elementos[ F->final ] = comanda;
    F->num_elem = F->num_elem + 1;
   
    if (F->final == (MAX-1)) F->final = 0;
    else F->final = F->final + 1;
   
    return true;
}


// RETORNA UMA COMANDA RETIRADA DA FILA
Comanda retira(Fila *F, bool erro)
{
    if (filaVazia(F) == true) erro = true;
   
    Comanda C = F->elementos[F->primeiro];
    F->num_elem = F->num_elem - 1;


    if (F->primeiro == (MAX - 1)) F->primeiro = 0;
    else F->primeiro = F->primeiro + 1;


    erro = false;
    return C;
}


// IMPRIME A FILA
void imprimirFila(Fila *F){
    Fila *F1 = criarFila();
    Comanda comanda;
    bool erro = false;
    for(int i = 1; filaVazia(F) == false; i++){
        printf("\nCliente %d: \n", i);
        comanda = retira(F, erro);
        imprimirComanda(comanda);
        insere(F1, comanda);
    }
    while(filaVazia(F1) == false)
        insere(F, retira(F1, erro));
}


// FILA FIM


// PILHA INICIO


struct pilha {
    char elem[MAX][100];
    int topo;
};
typedef struct pilha Pilha;


// LISTA DOS CHOCOLATES POSSIVEIS DA PILHA
char listaChocolates[5][100] = {"Diamante negro", "Laka", "Sonho de valsa", "Ouro branco", "KitKat"};


// GERA UMA STRUCT PILHA
Pilha *criarPilha()
{
    Pilha *P;
   
    P = (Pilha *) malloc(sizeof(Pilha));
    if (P != NULL) {
        P->topo = -1;
    }
   
    return P;
}


// DESTROI UMA STRUCT PILHA
void destruirPilha(Pilha *p)
{
    p->topo = -1;
}


// VERIFICA SE A PILHA ESTA VAZIA
bool pilhaVazia(Pilha p)
{
    if (p.topo == -1) return true;
    else return false;
}


// VERIFICA SE A PILHA ESTA CHEIA
bool pilhaCheia(Pilha p)
{
    if (p.topo == (MAX - 1)) return true;
    else return false;
}


// ADICIONA UM ITEM A PILHA
bool empilhar(Pilha *p, char *X)
{
    if (pilhaCheia(*p) == true) return false;


    else {
        p->topo = p->topo + 1;
        strcpy(p->elem[p->topo], X);
        return true;
    }
}


// REMOVE UM ITEM DA PILHA
void desempilhar(Pilha *p, char X[100])
{
    if (pilhaVazia(*p) == true)
        strcpy(X, "Sem chocolate :(");
   
    else {
        strcpy(X, p->elem[p->topo]);
        p->topo = p->topo - 1;
    }
}


// CRIA UMA PILHA DE CHOCOLATES RANDOMICA DE TAMANHO IGUAL A QUANTIDADE INFORMADA
Pilha *criarPilhaChocolates(int qtd){
    srand(time(NULL));
    Pilha *P = criarPilha();


    for(int i = 0; i < qtd; i++){
        empilhar(P, listaChocolates[rand() % 4]); // EMPILHA UM CHOCOLATE RANDOMICO DA LISTA DE POSSIVEIS CHOCOLATES (LINHA 7)
    }


    return P;
}


// IMPRIME A PILHA
void imprimirPilha(Pilha *P){
    Pilha *P1 = criarPilha();
    char *chocolate = (char *)malloc(100);
    printf("\n Pilha de chocolates: ");


    // REMOVE OS ITENS DA PILHA, IMPRIME NA TELA E EMPILHA EM UM PILHA AUXILIAR
    while(pilhaVazia(*P) == false){
        desempilhar(P, chocolate);
        empilhar(P1, chocolate);
        printf("\"%s\" \n", chocolate);  
    }


    // VOLTA OS ITENS PARA A PILHA ORIGINAL
    while(pilhaVazia(*P1) == false){
        desempilhar(P1, chocolate);
        empilhar(P, chocolate);
    }

   if (pilhaVazia(*P) == true){
    printf("\nChocolates esgotados\n");
   }
    printf("\n");
}


// PILHA FIM2


// FUNÇAO RESPONSAVEL POR LIDAR COM A ADIÇAO DE NOVOS CLIENTES A FILA
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
    printf("Quantos chocolates existirao na pilha: ");
    fgets(qtdChocolates, 1000, stdin);
    printf("Gerando chocolates randomicos...\n");
    Pilha *pilhaChocolates = criarPilhaChocolates(atoi(qtdChocolates));
     // PARA ALTERAR O NUMERO DE CHOCOLATES NA PILHA, BASTA ALTERAR O ARGUMENTO DA FUNÇAO criarPilhaChocolates
    Fila *comandas = criarFila();    
    bool flagDecisao = false;
    char decisao[1000];
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
