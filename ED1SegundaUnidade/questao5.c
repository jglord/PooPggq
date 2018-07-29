#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Tipo do Elemento
typedef struct sLista {
	int id;		    // ID
    char nome[30];	// Nome
    float valor;    // Valor
    struct sLista* pAnte;	// Ponteiro para elemento anterior
    struct sLista* pProx;	// Ponteiro para elemento próximo
} tLista;


// Assinaturas das funções: (DICA: implementar nessa ordem facilita)
tLista* inicializarLista();
int inserirInicio(tLista* inicio, char* nome, float* valor);
int percorrer(tLista* inicio);
tLista* buscar(tLista* inicio, int key);
int inserirFim(tLista* inicio, char* nome, float* valor);
void inserirDepoisDe(tLista* pInicio, char* nome, float* valor, int key);
tLista* remover(tLista* inicio, int key);


tLista* inicializarLista()
{
	// Aloca espaço para elemento CABEÇA
	tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista) );
    // Inicializa campos do elemento
	pNovo->id = 1;
    strcpy(pNovo->nome, "");
    pNovo->valor = 0;
    pNovo->pAnte = NULL;
    pNovo->pProx = NULL;
    
    return pNovo;
}

tLista* criarNovo(tLista* pInicio, char* nome, float* valor)
{
	tLista *p = (tLista*) calloc( 1, sizeof(tLista) );
	p->id = pInicio->id;
	strcpy(p->nome, nome);
	p->valor = *valor;
	p->pAnte = NULL;
    p->pProx = NULL;
    
    // Atualiza elemento cabeça
    pInicio->id = pInicio->id + 1;
    
    return p;
}

int inserirInicio(tLista* pInicio, char* nome, float* valor)
{
    // Aloca espaço para elemento NOVO
    tLista *pNovo = criarNovo(pInicio, nome, valor);
    
    // Anexar
    pNovo->pAnte = pInicio;
    pNovo->pProx = pInicio->pProx;

	// OBS: ponteiro  "da direita"  faz backup de  inicio->pProx
    tLista *pDireita = pInicio->pProx;
    pInicio->pProx = pNovo;
    
    if(pDireita == NULL) {
    	// Cenario: inserindo primeiro elemento
    	pInicio->pAnte = pNovo;   // Atualizo o ponteiro para o ultimo elemento
    }
    else {
    	// Cenario: ja ha outros elementos na lista
        pDireita->pAnte = pNovo;
    }
}


int percorrer(tLista* inicio)
{
	// Inicializações
    int i = 0;						// Quantidade de elementos
    tLista* p = inicio->pProx; 	// Ponteiro temporario. Pulo o elemento cabeça.

	// verifica se lista está vazia
    if(p == NULL) {
        printf("Lista Vazia!!! \n");
		return 0;
    }

	// Percorro lista
    while(p != NULL)
    {
        i++;
        printf("i: %d \n", i );
        printf("ID: %d \n", p->id );
        printf("NOME: %s \n", p->nome );
        printf("MEDIA: %.1f \n", p->valor);
        printf("p = %d \n", p);
        printf("pAnte = %d \n", p->pAnte);
        printf("pProx = %d \n\n", p->pProx);
        p = p->pProx; // vai para o próximo elemento
    }

	printf("Quantidade de Elementos = %d \n", i);
    return i; // retorna a quantidade de elementos
}


tLista* buscar(tLista* inicio, int key)
{
	// Inicializações
    tLista* p = inicio->pProx;	// Ponteiro temporario. Pulo a cabeça da lista. 
    
    while(p != NULL) 	// verifica se já chegou no final da lista
    {
        if(p->id == key) {
            return p;
        }

        p = p->pProx; // vai para o próximo elemento
    }

    return NULL;
}


int inserirFim(tLista* pInicio, char* nome, float* valor)
{
	// Aloca espaço para elemento NOVO
    tLista *pNovo = criarNovo(pInicio, nome, valor);

	// Ultimo elemento
    tLista *pUltimo = pInicio->pAnte;

    if(pUltimo == NULL) {
    	// Cenario: lista vazia
        pUltimo = pInicio;
    }
    
    // Anexa elemento NOVO
    pNovo->pAnte = pUltimo;
	pNovo->pProx = NULL;

    pUltimo->pProx = pNovo;

    // Atualiza elemento CABEÇA
    pInicio->pAnte = pNovo;
}


void inserirDepoisDe(tLista* pInicio, char* nomeNovo, float* valor, int key)
{
    // Antecessor
    tLista* p = buscar(pInicio, key);

	if(p == NULL)  // Verifica se o criterio existe
	{
        printf("Criterio invalido \n");
	}
	else
	{
        // Aloca espaço para elemento NOVO
    	tLista* pNovo = (tLista*) calloc( 1, sizeof(tLista));
    	pNovo->id = pInicio->id;
    	strcpy(pNovo->nome, nomeNovo);
    	pNovo->valor = *valor;
        pNovo->pAnte = NULL;
        pNovo->pProx = NULL;
    
    	// Atualiza elemento CABEÇA (incrementa o próximo valor do ID)
        pInicio->id = pInicio->id + 1;

		// Anexa elemento NOVO (dica: comece atribuindo os campos NULL)
    	pNovo->pProx = p->pProx;
		pNovo->pAnte = p;

		// OBS: ponteiro  segundo  faz backup de  p->pProx
	    tLista *pSegundo = p->pProx;
	    p->pProx = pNovo;
	    
	    if(pSegundo != NULL) {
	        pSegundo->pAnte = pNovo;
	    }
        else {
            pInicio->pAnte = pNovo;   // Atualizo o ponteiro para o ultimo elemento
        }
	}
}


tLista* remover(tLista* pInicio, int key)
{
    tLista* p = buscar(pInicio, key);
    
    if(p == NULL) {
        printf("ID nao encontrado \n");
    }
    else
    {
        // Faz backup dos elementos ao redor de P
        tLista* pEsquerda = p->pAnte;
        tLista* pDireita  = p->pProx;            
        
        // Anexar
        pEsquerda->pProx = pDireita;
    
        // Verifica se é o último elemento, pra evitar NULL
        if(pDireita != NULL) {
            pDireita->pAnte = pEsquerda;
        }
        else {
            pInicio->pAnte = pEsquerda; // Atualizo o ponteiro para o ultimo elemento
        }
        
        // Isola o elemento recém removido
        p->pAnte = NULL;
        p->pProx = NULL;
    }

    return p;
}


int main()
{    
    tLista* lista1 = inicializarLista();

    int op;
    int id;
    char nome[30];
    float valor;
    tLista *result;

    do
    {

    	printf("MENU: Lista duplamente encadeada \n");
        printf("1 - Percorrer \n");
		printf("2 - Proximo ID (na cabeca) \n");
	    printf("3 - Buscar Elemento \n");
        printf("4 - Inserir no Inicio \n");
        printf("5 - Inserir no Fim \n");
		printf("6 - Inserir (depois de...) \n");
        printf("7 - Remover \n");
        printf("0 - Sair \n");
    
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                printf("PERCORRER \n");
                percorrer(lista1);
                break;

			case 2: 
                printf("PROXIMO ID (na cabeca) \n");
                printf("maior = %d \n", lista1->id);
                break;

            case 3:
                printf("BUSCAR ELEMENTO \n");
                printf("Qual a chave? ");
                scanf("%d", &id);
                result = buscar(lista1, id);
                if(result != NULL) {
                    printf("result = %d \n", result);
                    printf("ID: %d \n", result->id );
                    printf("NOME: %s \n\n", result->nome );
                    printf("MEDIA: %.1f", result->valor);
                }
                else {
                    printf("result VAZIO");
                }
                break;

            case 4:
                printf("Inserir no Inicio \n");
                printf("Nome e media do aluno(Respectivamente): ");
                scanf("%s", &nome);
                scanf("%f", &valor);
                inserirInicio(lista1, nome, &valor);
                break;

            case 5:
                printf("Inserir no Fim \n");
                printf("Nome: ");
                scanf("%s", &nome);
                scanf("%f", &valor);
                inserirFim(lista1, nome, &valor);
                break;

            case 6: 
                printf("INSERIR DEPOIS DE... \n");
                printf("Inserir depois de qual chave? ");
                scanf("%d", &id);
				printf("Qual o nome e a media(Respectivamente)? ");
                scanf("%s", &nome);
                scanf("%f", &valor);
                inserirDepoisDe(lista1, nome, &valor, id);
                break;

            case 7:
                printf("Remover \n");
                printf("ID: ");
                scanf("%d", &id);
                result = remover(lista1, id);
                if(result != NULL) {
                    printf("result = %d \n", result);
                    printf("ID: %d \n", result->id );
                    printf("NOME: %s \n\n", result->nome );
                    free(result);
                }
                else {
                    printf("result VAZIO");
                }
                break;

            case 0:
                printf("Saindo... \n");
                break;

            default: 
                printf("INVALIDO \n");
                break;
        }

		printf("\n\n");
        system("pause"); 	// congela a tela para ver o resultado
        system("cls");		// limpa tela

    }
    while( op != 0 );
    

    system("pause");
    return 0;
}
