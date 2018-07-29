#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sLista{
    int id;        // ID
	char nome[30]; //Nome
	float valor;   //Valor   	
	struct sLista* pProx;    
} tLista;



tLista* inicializarListaComCabeca(); 
void inserirInicio(tLista* pInicio, char* nome, float* valor); 
int percorrer(tLista* pInicio); 
void inserirFim(tLista* pInicio, char* nome, float* valor);
void inserirDepoisDe(tLista* pInicio, char* nome, float* valor, int id); 
tLista* remover(tLista* pInicio, int id); 
tLista* buscar(tLista* pInicio, int id); 


tLista* inicializarListaComCabeca() {
    tLista* p = (tLista*) calloc( 1, sizeof(tLista) );
	strcpy(p->nome, "");
	p->id = 1;
    p->pProx = NULL;

    return p;
}

void inserirInicio(tLista* pInicio, char* nome, float* valor){

	tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
	// Inicializa campos do elemento
	strcpy(pNovo->nome, nome);
    pNovo->valor = *valor;
	pNovo->id = pInicio->id;
	pNovo->pProx = NULL; 
  	
    pInicio->id = pInicio->id + 1;  

	pNovo->pProx = pInicio->pProx;
	pInicio->pProx = pNovo;
}

tLista* buscar(tLista* pInicio, int id){

    tLista* p = pInicio->pProx; 	

    while (p != NULL){ 
        if (p->id == id) {
           return p;
        }

        p = p->pProx; 
    }
    
    return NULL;
}

int percorrer(tLista* pInicio)
{
	
	int i = 0;						
   	tLista* p = pInicio->pProx; 	

	
	if(p == NULL) {
		printf("OPS! LISTA VAZIA!!! \n");
		return 0;
	}

	
	while (p != NULL) 
	{
        i++;
        printf("\n");
        printf("i: %i\n", i);
		printf("p: %i \n", p);
        printf("ID: %i\n", p->id);
        printf("Nome: %s\n", p->nome);
        printf("Valor: %.1f\n", p->valor);
        printf("pProx: %i\n", p->pProx);
        printf("\n");
        p = p->pProx;
	}

	printf("Quantidade de Elementos = %d \n", i);
    return i; 
}

void inserirFim(tLista* pInicio, char* nome, float* valor)
{
	
	tLista* pNovo = (tLista*) calloc(1, sizeof(tLista) );

	strcpy(pNovo->nome, nome);
	pNovo->valor = *valor;
    pNovo->id = pInicio->id;
    pNovo->pProx = NULL; 

    pInicio->id = pInicio->id + 1; 

    tLista* p = pInicio;

    while (p->pProx != NULL) { 
        p = p->pProx;
    }
   
    p->pProx = pNovo;
}


void inserirDepoisDe(tLista* pInicio, char* nome, float* valor, int idCriterio)
{
    
    tLista* p = buscar(pInicio, idCriterio);

	if(p == NULL)  
	{
        printf("Posi��o n�o existente na lista!");
	}
	else
	{
       
    	tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
    
    	strcpy(pNovo->nome, nome);
    	pNovo->valor = *valor;
        pNovo->id = pInicio->id;
        pNovo->pProx = NULL;
    
        pInicio->id = pInicio->id + 1;

    	pNovo->pProx = p->pProx;
    	p->pProx = pNovo;
	}
}


tLista* buscarAnterior(tLista* pInicio, int id)
{
	
    tLista* p 	  = pInicio; 	
	tLista* result = NULL;

	if(pInicio->pProx == NULL) 	// Verifica se lista � vazia
	{
		result = NULL;
	}	
	else
	{
        result = pInicio;

		while (p != NULL)
    	{
	        if (p->id == id) {
	           return result;
	        }

			result = p;		// Armazena o ponteiro anterior
        	p = p->pProx;
    	}
	}

    return NULL;
}


tLista* remover(tLista* pInicio, int id)
{
	// Inicializa��es
    tLista* anterior = buscarAnterior(pInicio, id);
  	tLista* p = NULL;
    
    if(anterior == NULL)
    {
    	printf("anterior NULL. Nao existe elemento com esse id \n");
    	return NULL;
    }
    else
    {
    	p = anterior->pProx;
    	
        anterior->pProx = p->pProx;
        p->pProx = NULL;
    }
	
	return p;
}



int main()
{
	int opcao, id;
	char nome[30];
	float valor;
	
    // Primeiro elemento da lista (CABE�A)
    tLista* pInicio = inicializarListaComCabeca();

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
                    percorrer(pInicio);
                    break;

			case 2: printf("PROXIMO ID (na cabeca) \n");
                    printf("maior = %d \n", pInicio->id);
                    break;
                    
			case 3: printf("BUSCAR NORMAL \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tLista* result = NULL;
                    result = buscar(pInicio, id);
                    printf("result = %d \n", result);
                    if(result != NULL) {
	        			printf("ID: %d\n", result->id);
	        			printf("Nome: %s\n", result->nome);
	        			printf("pProx: %d\n", result->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

			case 4: printf("BUSCAR ANTERIOR \n");
					printf("Qual a chave? ");
                    scanf("%d", &id);
                    tLista* resultAnterior = NULL;
                    resultAnterior = buscarAnterior(pInicio, id);
                    printf("resultAnterior = %d \n", resultAnterior);
                    if(result != NULL) {
	        			printf("ID: %d\n", resultAnterior->id);
	        			printf("Nome: %s\n", resultAnterior->nome);
	        			printf("pProx: %d\n", resultAnterior->pProx);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 5: printf("INSERIR INICIO \n");
					printf("Qual o nome do aluno e a media do aluno? ");
                    scanf("%s", &nome);
                    scanf("%f", &valor);
                    inserirInicio(pInicio, nome, &valor);
                    break;

            case 6: printf("INSERIR FIM \n");
					printf("Qual o nome e a media do aluno? ");
                    scanf("%s", &nome);
                    scanf("%f", &valor);
                    inserirFim(pInicio, nome, &valor);
                    break;

            case 7: printf("INSERIR DEPOIS DE... \n");
					printf("Qual o nome e a media do aluno? ");
                    scanf("%s", &nome);
                    scanf("%f", &valor);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pInicio, nome, &valor, id);
                    break;

            case 8: printf("REMOVER \n");
					printf("Qual o ID? ");
                    scanf("%d", &id);
                    tLista* resultRemove = NULL;
                    resultRemove = remover(pInicio, id);
                    printf("result = %d \n", result);
                    if(resultRemove != NULL) {
	        			printf("ID: %d\n", resultRemove->id);
	        			printf("Nome: %s\n", resultRemove->nome);
	        			printf("pProx: %d\n", resultRemove->pProx);
                        free(resultRemove);
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
        system("pause"); 	// congela a tela para ver o resultado
        system("cls");		// limpa tela
    }
    while(opcao != 0);

    system("pause");
    return 0;
}
