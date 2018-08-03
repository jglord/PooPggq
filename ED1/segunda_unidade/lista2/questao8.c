#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sDados {
    char nome[50];
    float valor;
} tDados;

typedef struct sElemento {
    int idTopo;         // Topo
    tDados dados;       // Nome e Valor
    struct sElemento* proxElemento;     // Ponteiro que aponta para o próximo elemento.
    struct sElemento* anteElemento;     // Ponteiro que aponta para o elemento anterior.
} tElemento;

tElemento* inicializarCabeca();
tElemento* criarNovo(tElemento* cabeca, tDados dados);

void empilhar(tElemento* cabeca, tDados dados);
tElemento* desempilhar(tElemento* cabeca);

void exibirPilha(tElemento* cabeca);

int main() {

	tElemento* cabeca = inicializarCabeca();
	tElemento* desempilhado;
    tDados dados;

    printf("Pilha sobre lista duplamente encadeada!\n");

    printf("Empilhando...\n");
    strcpy(dados.nome,"João");
    dados.valor = 8.7;
    empilhar(cabeca, dados);

    printf("Empilhando...\n");
    strcpy(dados.nome,"Leyvino");
    dados.valor = 10.0;
    empilhar(cabeca, dados);

    printf("Empilhando...\n");
    strcpy(dados.nome,"Arthur");
    dados.valor = 8.5;
    empilhar(cabeca, dados);

    printf("Empilhando...\n");
    strcpy(dados.nome,"Washigton");
    dados.valor = 10.0;
    empilhar(cabeca, dados);

    printf("\n\nPilha inicial...\n");
    exibirPilha(cabeca);

    desempilhado = desempilhar(cabeca);

    printf("\nElemento desempilhado...\n");
    printf("Nome: %s\n", desempilhado->dados.nome);
    printf("Valor: %.2f\n", desempilhado->dados.valor);

    printf("\n\nPilha depois de remover um elemento...\n\n");
    exibirPilha(cabeca);

    return 0;
}

// Inicializa a cabeca da lista
tElemento* inicializarCabeca() {

    tElemento* cabeca = (tElemento*) calloc(1, sizeof(tElemento));

    cabeca->idTopo = -1;

    strcpy(cabeca->dados.nome, "");
    cabeca->dados.valor = 0.0;

    cabeca->proxElemento = NULL;
    cabeca->anteElemento = NULL;

    return cabeca;
}

// Cria novo elemento de uma lista duplamente encadeada
tElemento* criarNovo(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento));

    novoElemento->idTopo = cabeca->idTopo;

    // Guardando valores no elemento
    strcpy(novoElemento->dados.nome, dados.nome);
    novoElemento->dados.valor = dados.valor;

    novoElemento->proxElemento = NULL;
    novoElemento->anteElemento = NULL;

    cabeca->idTopo++;

    return novoElemento;
}

void empilhar(tElemento* cabeca, tDados dados) {

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

tElemento* desempilhar(tElemento* cabeca) {

	// Guardando elemento desempilhado.
    tElemento* desempilhado = cabeca->anteElemento;

    // Definindo o novo topo da pilha
    tElemento* novoTopo = desempilhado->anteElemento;

    novoTopo->proxElemento = NULL;

    // Atualizando o idTopo da cabeca
    cabeca->idTopo = novoTopo->idTopo;

    return desempilhado;
}


void exibirPilha(tElemento* cabeca) {
	int i = 0;
	tElemento* p = cabeca->proxElemento;

	printf("Exibindo a pilha...\n");

	while(p != NULL) {
		printf("Posicao: %i\n", i);
		printf("Nome: %s\n", p->dados.nome);
		printf("Valor: %.2f\n\n", p->dados.valor);
		i++;
		p = p->proxElemento;
	}
}

