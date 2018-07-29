#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sDados {
    char nome[50];
    float valor;
} tDados;

typedef struct sElemento {
    int id;
    tDados dados;
    struct sElemento* proxElemento;
} tElemento;

tElemento* inicializarListaComCabeca();
void inserirElementoInicio(tElemento* cabeca, tDados dados);
void inserirElementoFim(tElemento* cabeca, tDados dados);
int percorrerLista(tElemento* cabeca);      // Percorre a lista, exibe os itens e retorna a quantidade;
tElemento* buscar(tElemento* cabeca,int id);
tElemento* buscarAnterior(tElemento* pInicio, int id);
void inserirDepoisDe(tElemento* cabeca, tDados dados, int id);
tElemento* remover(tElemento* cabeca, int id); 

int main()
{
	int opcao, id;
	tDados dados;
	
    // Primeiro elemento da lista (CABE�A)
    tElemento* cabeca = inicializarListaComCabeca();

    do 
    {
    	printf("\n");
		printf("MENU: Lista simplesmente encadeada \n");
        printf("1-Percorrer \n");
        printf("2-Proximo ID (na cabeca) \n");
        printf("3-Buscar Elemento Atual \n");
        printf("4-Buscar Elemento Anterior \n");
        printf("5-Inserir no Inicio \n");
        printf("6-Inserir no Fim \n");
        printf("7-Inserir (depois de...) \n");
        printf("8-Remover \n");
        printf("0-Sair \n");
        printf("Qual sua opcao? ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
            case 1: printf("PERCORRER \n");
                    percorrerLista(cabeca);
                    break;

			case 2: printf("PROXIMO ID (na cabeca) \n");
                    printf("maior = %d \n", cabeca->id);
                    break;
                    
			case 3: printf("BUSCAR NORMAL \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* result = NULL;
                    result = buscar(cabeca, id);
                    printf("result = %p \n", result);
                    if(result != NULL) {
	        			printf("ID: %d\n", result->id);
	        			printf("Nome: %s\n", result->dados.nome);
	        			printf("pProx: %p\n", result->proxElemento);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

			case 4: printf("BUSCAR ANTERIOR \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tElemento* resultAnterior = NULL;
                    resultAnterior = buscarAnterior(cabeca, id);
                    printf("resultAnterior = %p \n", resultAnterior);
                    if(result != NULL) {
	        			printf("ID: %d\n", resultAnterior->id);
	        			printf("Nome: %s\n", resultAnterior->dados.nome);
	        			printf("pProx: %p\n", resultAnterior->proxElemento);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 5: fflush(stdin);
                    printf("INSERIR INICIO \n");
					printf("Qual o nome do aluno e a media do aluno? ");
                    fgets(dados.nome, 50, stdin);
                    scanf("%f", &dados.valor);
                    inserirElementoInicio(cabeca,dados);
                    break;

            case 6: fflush(stdin);
                    printf("INSERIR FIM \n");
					printf("Qual o nome e a media do aluno? ");
                    fgets(dados.nome, 50, stdin);
                    scanf("%f", &dados.valor);
                    inserirElementoFim(cabeca,dados);
                    break;

            case 7: printf("INSERIR DEPOIS DE... \n");
					printf("Qual o nome e a media do aluno? ");
                    fgets(dados.nome, 50, stdin);
                    scanf("%f", &dados.valor);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(cabeca,dados, id);
                    break;

            case 8: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    tElemento* resultRemove = NULL;
                    resultRemove = remover(cabeca, id);
                    printf("result = %p \n", result);
                    if(resultRemove != NULL) {
	        			printf("ID: %d\n", resultRemove->id);
	        			printf("Nome: %s\n", resultRemove->dados.nome);
	        			printf("pProx: %p\n", resultRemove->proxElemento);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 0: printf("Saindo... \n");
                    break;

            default: printf("OPCAO INVALIDA \n");
                     break;
        }
        
        printf("\n\n");
    }
    while(opcao != 0);
    return 0;
}



tElemento* inicializarListaComCabeca() {

    tElemento* cabecaDaLista = (tElemento*) calloc(1, sizeof(tElemento));
    cabecaDaLista->id = 1;

    strcpy(cabecaDaLista->dados.nome, "");
    cabecaDaLista->dados.valor = 0.0;
    
    cabecaDaLista->proxElemento = NULL;

    return cabecaDaLista;
}


void inserirElementoInicio(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento)); 

    // Inserindo valores no novo elemento
    strcpy(novoElemento->dados.nome, dados.nome);
    novoElemento->dados.valor = dados.valor;
    novoElemento->id = cabeca->id;

    cabeca->id++;

    // Anexando elementos
    novoElemento->proxElemento = cabeca->proxElemento;
    cabeca->proxElemento = novoElemento;
}

void inserirElementoFim(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento));

    strcpy(novoElemento->dados.nome, dados.nome);
    novoElemento->dados.valor = dados.valor;
    novoElemento->id = cabeca->id;

    novoElemento->proxElemento = NULL;

    cabeca->id++;

    // P saltitante para achar o final da lista
    tElemento* p = cabeca;

    while(p->proxElemento != NULL) {
        p = p->proxElemento;
    }
    
    p->proxElemento = novoElemento;
}

int percorrerLista(tElemento* cabeca) {

    int i = 0;
    tElemento* p = cabeca->proxElemento;

    while(p != NULL) {
        i++;
        printf("\n");
        printf("i: %i\n", i);
		printf("p: %p \n", p);
        printf("ID: %i\n", p->id);
        printf("Nome: %s\n", p->dados.nome);
        printf("Valor: %.1f\n", p->dados.valor);
        printf("pProx: %p\n", p->proxElemento);
        printf("\n");
        p = p->proxElemento;
    }

    printf("A lista tem %i elementos.", i);

    return i;
}

tElemento* buscar(tElemento* cabeca,int id) {

    tElemento* p = cabeca->proxElemento;

    while(p != NULL) {

        if(p->id == id) {
            return p;
        }
        p = p->proxElemento;

    }
     return NULL;
}

tElemento* buscarAnterior(tElemento* cabeca, int id) {

    tElemento* p = cabeca->proxElemento;
    tElemento* result = NULL;

    if(p == NULL) {
        printf("Lista vazia!\n");
    }
    else { 
        while(p != NULL) {

            if(p->id == id) {
                return result;
            }

            result = p; // Guarda o anterior
            p = p->proxElemento;
        }  
    }
    return NULL;

}


void inserirDepoisDe(tElemento* cabeca, tDados dados, int id) {

    tElemento* p = buscar(cabeca, id);

    if(p == NULL) {
        printf("Elemento não existe!");
    }
    else {    
        tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento));

        strcpy(novoElemento->dados.nome, dados.nome);
        novoElemento->dados.valor = dados.valor;
        novoElemento->id = cabeca->id;

        cabeca->id++;

        // Anexando elementos
        novoElemento->proxElemento = p->proxElemento;
        p->proxElemento = novoElemento;
    }
}

tElemento* remover(tElemento* cabeca, int id) {

    tElemento* p = NULL;
    tElemento* pAnterior = buscarAnterior(cabeca, id);

    if(p == NULL) {
        printf("Elemento nao existe na lista!");
    }    
    else {
        p = pAnterior->proxElemento;
        pAnterior->proxElemento = p->proxElemento;
        p->proxElemento = NULL;
    }
    return p;
}

