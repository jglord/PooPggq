#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct sLista
{
    int id;                     // ID
	char nome[30];   			// Nome
	float valor;           		// Valor
	struct sElemento* pProx;    // Ponteiro para pr�ximo elemento
    
} tLista;


int getProxID(tLista* pInicio);
void inserirInicio(tLista** ppInicio, char* nome, float* valor);
int percorrer(tLista* pInicio);
tLista* buscar(tLista* pInicio, int id);
void inserirFim(tLista** ppInicio, char* nome, float* valor);
void inserirDepoisDe(tLista* pInicio, char* nome, float* valor, int id);
tLista* buscarAnterior(tLista* pInicio, int id);
tLista* remover(tLista** ppInicio, int id);


int getProxID(tLista* pInicio) 
{
    int maior = 0; 		
    tLista* p = NULL; 		
	
	p = pInicio;

    while( p != NULL )
    {
        if( p->id > maior  ) {
            maior = p->id;
        }
        p = p->pProx;
    }

    return (maior + 1);
}


void inserirInicio(tLista** ppInicio, char* nome, float* valor)
{
    // Alocando espa�o e inserindo um novo elemento no inicio
    tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) ); 
    pNovo->id = getProxID(*ppInicio);
    strcpy( pNovo->nome, nome);
    pNovo->valor = *valor;
    pNovo->pProx = NULL;

    if( *ppInicio == NULL ) //Verifica��o para saber se est� vazia.
    {
        *ppInicio = pNovo;
    }
    else
    {
    	
        pNovo->pProx = *ppInicio;
        *ppInicio = pNovo;
    }
}


int percorrer(tLista* pInicio)
{
	int i = 0;
    tLista *p = pInicio; 	// ponteiro temporario

	if(p == NULL) {
		printf("LISTA VAZIA \n");
	}
	else 
    {
        while( p != NULL )
        {
            i++;
            printf("\n");
            printf("i : %d \n", i);
            printf("Ponteiro: %d \n", p);
            printf("Ponteiro Proximo: %d \n", p->pProx);
            printf("ID: %d \n", p->id);
            printf("Nome: %s \n", p->nome);
            printf("Valor: %.1f \n", p->valor);
            printf("\n");
            p = p->pProx;
        }
    }

	printf("Quantidade de Elementos = %d \n", i);
   
    return i; 
}


void inserirFim(tLista** ppInicio, char* nome, float* valor)
{
    tLista *p = *ppInicio;
	
    // Novo elemento    
    tLista* pNovo = (tLista*) calloc(1,sizeof(tLista));    
    pNovo->id = getProxID(*ppInicio);
    pNovo->valor = *valor;
    strcpy( pNovo->nome, nome);
    pNovo->pProx = NULL;

    // verifica se lista est� vazia
    if( *ppInicio == NULL ) { 
        *ppInicio = pNovo;       	    // NovoElemento ser� o primeiro elemento da Lista
    }
    else
    {
        while( p->pProx != NULL) {		// Procuro um P que tem prox NULL
            p = p->pProx;
        }

		// Anexa
        p->pProx = pNovo;
    }
}


tLista* buscar(tLista* pInicio, int id)
{
    tLista* p = pInicio;		// ponteiro temporario

    while( p != NULL )
    {
        if( p->id == id ) {
            return p;
        }
        p = p->pProx;
    }
    
    return NULL;
}

void inserirDepoisDe(tLista* pInicio, char* nome, float* valor, int id)
{

    tLista* p = buscar(pInicio, id);

    if( p == NULL )	// Verifica se o criterio existe
    {
        printf("Criterio invalido \n");
    }
    else
    {
 		//Aloca espa�o e inicializa os elementos.
        tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
     
        pNovo->id = getProxID(pInicio);
        strcpy( pNovo->nome, nome);
        pNovo->valor = *valor;
        pNovo->pProx = NULL;

        pNovo->pProx = p->pProx;
	    p->pProx = pNovo;
    }
}


tLista* buscarAnterior(tLista* pInicio, int id)
{
    tLista* p = pInicio; 	   	// ponteiro temporario
	tLista* anterior = NULL;	  // ponteiro anterior

    while (p != NULL)
    {
        if (p->id == id) {
           return anterior;
        }

		anterior = p;
        p = p->pProx;
    }
    
    return NULL;
}

tLista* remover(tLista** ppInicio, int id)
{	
	tLista* anterior = NULL;
	tLista* atual = NULL;

	if(*ppInicio == NULL) {
        printf("Lista Vazia!!! \n");
        return NULL;
    }
    else { 
		anterior = buscarAnterior(*ppInicio, id); 

		if( anterior == NULL ) {
			if( (*ppInicio)->id == id ) {   
				atual = *ppInicio;

				if( atual->pProx == NULL ) {
					printf("Remove o primeiro e unico elemento \n");
					*ppInicio = NULL;
				}
				else {
	        		printf("Remove o primeiro elemento \n");
        			*ppInicio = atual->pProx;
                	atual->pProx = NULL;
				}
			}
    	}
		else
		{
			atual = anterior->pProx;

    		printf("Remove elemento meio ou ultimo \n");
    		anterior->pProx = atual->pProx; 
            atual->pProx = NULL;
		}
    }

	return atual;
}

int main()
{
    tLista* pInicio = NULL;

    int opcao;
    int id;
    char nome[30];
	float valor;

    do 
    {
     	printf("\n");
        printf("1-Percorrer \n");
        printf("2-Buscar Maior ID \n");
        printf("3-Buscar Elemento Atual \n");
        printf("4-Buscar Elemento Anterior \n");
        printf("5-Inserir no pInicio \n");
        printf("6-Inserir no Fim \n");
        printf("7-Inserir (depois de...) \n");
        printf("8-Remover \n");
        printf("0-Sair \n");

        printf("Qual sua opcao? ");
		fflush(stdin);
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
            case 1: printf("PERCORRER LISTA \n");
                    percorrer(pInicio);
                    break;

    		case 2: printf("OBTER MAIOR ID \n");
                    int maiorID = getProxID(pInicio);
                    printf("Maior ID = %d \n", maiorID);
                    break;

			case 3: printf("BUSCAR ATUAL \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    tLista *resultBusca = buscar(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->id);
                        printf("Nome: %s \n", resultBusca->nome);
                        printf("Media: %.1f \n", resultBusca->valor);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;

			case 4: printf("BUSCAR ANTERIOR \n");
                    printf("Qual a matricula? ");
                    scanf("%d", &id);
                    resultBusca = buscarAnterior(pInicio, id); 
                    if( resultBusca != NULL) {
                        printf("Ponteiro: %d \n", resultBusca);
                        printf("Matricula: %d \n", resultBusca->id);
                        printf("Nome: %s \n", resultBusca->nome);
                        printf("Media: %.1f \n", resultBusca->valor);
                    }
                    else {
                        printf("NAO ACHOU \n");
                    }
                    break;

            case 5: printf("INSERIR no pInicio \n");
                    printf("Digite o nome e a media do novo Aluno: ");
                    scanf("%s", &nome);
                    scanf("%f", &valor);
                    inserirInicio(&pInicio, nome, &valor);
                    break;
            
            case 6: printf("INSERIR no FIM \n");
                    printf("Digite o nome e a media do novo Aluno: ");
                    scanf("%s", &nome);
                    scanf("%f", &valor);
                    inserirFim(&pInicio, nome, &valor);
                    break;

            case 7: printf("INSERIR (depois de ...) \n");
					printf("Qual o nome e a media do novo aluno? ");
                    scanf("%s", &nome);
                    scanf("%f", &valor);
                    printf("Inserir depois de qual chave? ");
                    scanf("%d", &id);
                    inserirDepoisDe(pInicio, nome, &valor, id);
                    break;

            case 8: printf("REMOVER \n");
					printf("Qual a chave a ser removida? ");
                    scanf("%d", &id);
                    tLista* resultRemocao = remover(&pInicio, id); 
                    printf("resultRemocao = %d \n", resultRemocao);
                    if(resultRemocao != NULL) {
	        			printf("Matr: %d\n",  resultRemocao->id);
	        			printf("Nome: %s\n",  resultRemocao->nome);
	        			printf("Media: %.1f\n", resultRemocao->valor);
	        			printf("pProx: %d\n", resultRemocao->pProx);
                        free(resultRemocao);
                    }
                    else {
						printf("Nenhum elemento encontrado \n");
                    }
                    break;

            case 0: printf("SAINDO... \n");
                    break;

            default: printf("Valor invalido \n");
                    break;
        }
        
        printf("\n\n");
        system("pause"); 
        system("cls");		
    }
    while(opcao != 0);

    system("pause");
    return 0;
}
