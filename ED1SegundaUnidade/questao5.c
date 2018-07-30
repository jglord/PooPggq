// Lista duplamente encadeada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sDados { 
    char nome[50];
    float valor;
} tDados;

typedef struct sElemento {
    int id;             // ID
    tDados dados;       // Nome e Valor
    struct sElemento* proxElemento;     // Ponteiro que aponta para o próximo elemento.
    struct sElemento* anteElemento;     // Ponteiro que aponta para o elemento anterior.
} tElemento;

tElemento* inicializarCabeca();
tElemento* criarNovo(tElemento* cabeca, tDados dados);
int percorrer(tElemento* cabeca);
tElemento* buscar(tElemento* cabeca, int id);

void inserirElementoInicio(tElemento* cabeca, tDados dados);
void inserirElementoFim(tElemento* cabeca, tDados dados);
void inserirDepoisDe(tElemento* cabeca, tDados dados, int id);


int main(int argc, char const *argv[]){

    tElemento* cabeca = inicializarCabeca();
    int opcao, id;
    tDados dados;

    do {
        
        printf("=====Lista duplamente encadeada=====\n");
        printf("1 - Inserir elemento no inicio.\n");
        printf("2 - Inserir elemento depois de um ID.\n");
        printf("3 - Inserir elemento no fim da lista.\n");
        printf("4 - Exibir a lista\n");
        printf("0 - Sair do programa!\n");

        printf("Escolha a opção [ ]\b\b");
        scanf("%i", &opcao);

        fflush(stdin);
        switch(opcao) {
            
            case 1:
                printf("Nome: ");   fgets(dados.nome, 50, stdin);            
                printf("Valor: ");  scanf("%f", &dados.valor);
                inserirElementoInicio(cabeca, dados);
                break;

            case 2:
                printf("Nome: ");   fgets(dados.nome, 50, stdin);            
                printf("Valor: ");  scanf("%f", &dados.valor);
                printf("ID: ");     scanf("%i", &id); 
                inserirDepoisDe(cabeca, dados, id);
                break;

            case 3:
                printf("Nome: ");   fgets(dados.nome, 50, stdin);            
                printf("Valor: ");  scanf("%f", &dados.valor);
                inserirElementoFim(cabeca, dados);
                break;
            
            case 4:
                percorrer(cabeca);
                break;    

            default:
                break;

        }

    }while(opcao != 0);

    printf("Programa finalizado!\n");
    return 0;
}

// Inicializa a cabeca da lista
tElemento* inicializarCabeca() {

    tElemento* cabeca = (tElemento*) calloc(1, sizeof(tElemento));
    
    cabeca->id = 1;

    strcpy(cabeca->dados.nome, "");
    cabeca->dados.valor = 0.0;

    cabeca->proxElemento = NULL;
    cabeca->anteElemento = NULL;

    return cabeca;
}

// Cria novo elemento de uma lista duplamente encadeada
tElemento* criarNovo(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento));

    // Salvando id do elemento
    novoElemento->id = cabeca->id;

    // Guardando valores no elemento
    strcpy(novoElemento->dados.nome, dados.nome);
    novoElemento->dados.valor = dados.valor;

    novoElemento->proxElemento = NULL;
    novoElemento->anteElemento = NULL;

    // Atualizando id da cabeca
    cabeca->id++;

    return novoElemento;   
}

// Percorre a lista e retorna a quantidade de elementos inseridos nela.
int percorrer(tElemento* cabeca) {
    int i = 0;
    tElemento* p = cabeca->proxElemento;

    if(p == NULL) {
        printf("Lista vazia!!!\n\n");
        return 0;
    }

    while( p->proxElemento != NULL ) {
        i++;
        printf("i: %i\n", i);
        printf("ID: %i\n", p->id);
        printf("Nome: %s\n", p->dados.nome);
        printf("Valor: %.2f\n", p->dados.valor);
        printf("P: %p", (void*) p);
        printf("ProxElemento: %p\n", (void*) p->proxElemento);
        printf("AnteElemento: %p\n", (void*) p->anteElemento);
        p = p->proxElemento;
    }

    printf("A lista tem %i elementos.", i);
    return i;
}

// Busca um elemento pelo ID
tElemento* buscar(tElemento* cabeca, int id) {

    tElemento* p = cabeca->proxElemento;

    if(p == NULL) {
        printf("Lista vazia!\n\n");
        return NULL;
    }

    while( p->proxElemento != NULL ) {

        if(p->id == id) {
            return p;
        }

        p = p->proxElemento;
    }
    return NULL;
}

// Insere elemento logo após a cabeca da lista
void inserirElementoInicio(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = criarNovo(cabeca, dados);

    // Anexando elemento na lista
    novoElemento->anteElemento = cabeca;
    novoElemento->proxElemento = cabeca->proxElemento;

    // Guardando o prox da cabeca
    tElemento* direita = cabeca->proxElemento;
    cabeca->proxElemento = novoElemento;


    if(direita == NULL) { // Inserindo primeiro elemento da lista
        cabeca->anteElemento = novoElemento;
    }
    else {  // Já existem outros elementos na lista 
        direita->anteElemento = novoElemento;
    }
}

// Insere elemento no final da lista
void inserirElementoFim(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = criarNovo(cabeca, dados);
    
    tElemento* ultimoElemento = cabeca->anteElemento;

    if(ultimoElemento == NULL) {     // Lista vazia
        ultimoElemento = cabeca;
    }

    // Anexando elemento
    novoElemento->anteElemento = ultimoElemento;
    novoElemento->proxElemento = NULL;

    ultimoElemento->proxElemento = novoElemento;

    cabeca->anteElemento = novoElemento;
}

// Insere elemento depois de um elemento escolhido pelo ID
void inserirDepoisDe(tElemento* cabeca, tDados dados, int id) {

    tElemento* novoElemento = criarNovo(cabeca, dados);
    tElemento* p = buscar(cabeca, id);

    if(p == NULL) {
        printf("ID inválido!\n\n");
    }
    else {
        // Guardando elemento da direito
        tElemento* daDireita = p->proxElemento;

        // Anexando o novo elemento corretamente;
        novoElemento->anteElemento = p;
        novoElemento->proxElemento = p->proxElemento;
        
        p->proxElemento = novoElemento;

        daDireita->anteElemento = novoElemento;

    }



}






    








