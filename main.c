#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>

#define  MAX 1000

// STRUCT ITEM CARDAPIO

struct itemCardapio {
    int id;
    float preco;
};

typedef struct itemCardapio ItemCardapio;

// CRIANDO CARDAPIO

struct cardapio{
    int tamanho;
    ItemCardapio itens[1000];
};
typedef struct cardapio Cardapio;


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

//CRIANDO COMANDA

struct itemComanda{
    int id;
    int qtd; // quantidade de itens consumidos
};
typedef struct itemComanda ItemComanda;

struct comanda{
    char nomeCliente[100];
    int itensTotais;
    ItemComanda itens[20];
    float valorTotal;
    //char *chocolate;
};
typedef struct comanda Comanda;

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

// TAD PILHA

struct pilha {
    char elem[MAX];
    int topo;
};

typedef struct pilha Pilha;

void criarPilha(Pilha *p)
{
    p->topo = -1;
}

void destruirPilha(Pilha *p)
{
    p->topo = -1;
}

bool pilhaVazia(Pilha p)
{
    if (p.topo == -1) return true;
    else return false;
}

bool pilhaCheia(Pilha p)
{
    if (p.topo == (MAX - 1)) return true;
    else return false;
}

bool empilhar(Pilha *p, char X)
{
    if (pilhaCheia(*p) == true) return false;

    else {
        p->topo = p->topo + 1;
        p->elem[ p->topo ] = X;
        return true;
    }
}

bool desempilhar(Pilha *p, char *X)
{
    if (pilhaVazia(*p) == true) return false;
    
    else {
        *X = p->elem[ p->topo ];
        p->topo = p->topo - 1;
        return true;
    }
}

// FIM TAD PILHA

// TAD FILA

struct fila {
    Comanda elementos[MAX];
    int num_elem;
    int primeiro;
    int final;
};

typedef struct fila Fila;

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

void destruirFila(Fila *F)
{
    if (F != NULL) free(F);
}

bool filaVazia(Fila *F)
{
    if (F->num_elem == 0) return true;
    else return false;
}

bool filaCheia(Fila *F)
{
    if (F->num_elem == MAX) return true;
    else return false;
}

bool insere(Fila *F, Comanda comanda)
{
	
	if (filaCheia(F) == true) return false;

	F->elementos[ F->final ] = comanda;
	F->num_elem = F->num_elem + 1;
	
	if (F->final == (MAX-1)) F->final = 0;
	else F->final = F->final + 1;
	
	return true;
}

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

// FIM TAD FILA

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

        if(strcmp(buffer, "-\n") == 0){
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

int main()
{   
    int decisao;
    char nome[256];

    Fila *comandas = criarFila();

    printf("Deseja adicionar mais algum nome a fila? (1- SIM, 2- NAO) ");        
    gets(&decisao);
    while (decisao == '1'){       
        printf("Digite o nome para adicionar na fila: ");
        gets(nome);
        strcat(nome, "\n");

        // LOCALIZA E CALCULA VALOR TOTAL DA COMANDA
        Comanda *comanda = localizarComandaCliente(nome);
        strcpy(comanda->nomeCliente, nome);
        calcularTotalComanda(comanda);
        insere(comandas, *comanda);

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
        printf("Chocolate: Sonho de Valsa\n\n");
    }

    return 0;
}
