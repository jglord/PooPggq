#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct sDados {
    char nome[30];
    float valor;
} tDados;

typedef struct sElemento {
    int id;
    tDados dados;
    struct sElemento* pProx;
} tElemento;

tElemento* inicializarcabeca() {
    // Alocando espaço para elemento cabeca
    tElemento* p = (tElemento*) calloc(1, sizeof(tElemento));

    p->id = 1;
    p->dados.valor = 0.0;
    strcpy(p->dados.nome, "");    
    p->pProx = NULL;
    
    return p;
}

void inserirInicio(tElemento* cabeca, tDados dados) {
    tElemento* pNovo = (tElemento*) calloc(1, sizeof(tElemento));

    strcpy(pNovo->dados.nome, dados.nome);
    pNovo->dados.valor = dados.valor;
    pNovo->id = cabeca->id;
    pNovo->pProx = NULL;

    cabeca->id++;

    // Anexando elementos.
    pNovo->pProx = cabeca->pProx;
    cabeca->pProx = pNovo;
}

