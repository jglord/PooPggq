#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sDados {
    char nome[50];
    float valor;
} tDados;

typedef struct sElemento {
    int inicio, fim;         // Topo
    tDados dados;            // Nome e Valor
    struct sElemento* proxElemento;     // Ponteiro que aponta para o próximo elemento.
    struct sElemento* anteElemento;     // Ponteiro que aponta para o elemento anterior.
} tElemento;

tElemento* inicializarCabeca();
tElemento* criarNovo(tElemento* cabeca, tDados dados);

tElemento* inicializarCabeca() {
    
    tElemento* cabeca = (tElemento*) calloc(1, sizeof(tElemento));
    
    cabeca->inicio  = -1;
    cabeca->fim     = -1;
    
    strcpy(cabeca->dados.nome, "");
    cabeca->dados.valor = 0.0;

    cabeca->proxElemento = NULL;
    cabeca->anteElemento = NULL;

    return cabeca;
}

tElemento* criarNovo(tElemento* cabeca, tDados dados) {

    tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento));

    novoElemento->inicio  = -1;
    novoElemento->fim     = -1;
    
    strcpy(novoElemento->dados.nome, "");
    novoElemento->dados.valor = 0.0;

    novoElemento->proxElemento = NULL;
    novoElemento->anteElemento = NULL;
    
    return novoElemento;
}

void inserirElemento(tElemento* cabeca, tDados dados) {
    
    tElemento* novoElemento =  criarNovo(cabeca, dados);
    
    tElemento* ultimoElemento = cabeca->anteElemento;

    // Lista vazia
    if(ultimoElemento == NULL) {
        ultimoElemento = cabeca;
    }

    novoElemento->anteElemento = ultimoElemento;
    novoElemento->proxElemento = NULL;

    ultimoElemento->proxElemento = novoElemento;

    cabeca->anteElemento = novoElemento;
    
}