#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define MAX 4

typedef struct sDados {
    char nome[30];
    float valor;
} tDados;

typedef struct sFila {
    tDados vetor[MAX];
    int inicio, fim;
} tFila;

tFila inicializarFila();
bool inserirElemento(tFila*, tDados);
void exibir(tFila fila);
bool removerNoInicio(tFila* fila, tDados* retorno);    

int main() {

    tFila fila = inicializarFila();
    tDados dadosRetornados;

    tDados dado1;
    strcpy(dado1.nome, "Nome1");
    dado1.valor = 1.0;
    inserirElemento(&fila,dado1);

    tDados dado2;
    strcpy(dado2.nome, "Nome2");
    dado2.valor = 1.0;
    inserirElemento(&fila,dado2);
    
    tDados dado3;
    strcpy(dado3.nome, "Nome3");
    dado3.valor = 1.0;
    inserirElemento(&fila,dado3);

    tDados dado4;
    strcpy(dado4.nome, "Nome4");
    dado4.valor = 1.0;
    inserirElemento(&fila,dado4);

    tDados dado5;
    strcpy(dado5.nome, "Nome5");
    dado5.valor = 1.0;
    inserirElemento(&fila,dado5);

    if( removerNoInicio(&fila, &dadosRetornados)  == true) {
        printf("\n\nNome: %s\n", dadosRetornados.nome);
        printf("Valor: %.2f\n\n", dadosRetornados.valor);
    }

    exibir(fila);


    return 0;
}

tFila inicializarFila() {
    tFila p;

    p.inicio = -1;
    p.fim = -1;

    return p;
}


bool inserirElemento(tFila* fila, tDados dados) {
    
    int fimTemp = (fila->fim + 1) % MAX;

    if( fimTemp == fila->inicio ) {
        printf("Fila cheia!");
        return false;
    }

    fila->fim = fimTemp;

    strcpy(fila->vetor[fila->fim].nome, dados.nome);
    fila->vetor[fila->fim].valor = dados.valor;

    if(fila->inicio == -1) {
        fila->inicio = 0;
    }

    printf("Valores adicionados com sucesso!\n");
    return true;
}

bool removerNoInicio(tFila* fila, tDados* retorno) {
    
    if( fila->inicio == -1 ) {
        printf("Fila vazia!\n");
        return false;
    }

    strcpy(retorno->nome, fila->vetor[fila->inicio].nome);
    retorno->valor = fila->vetor[fila->inicio].valor;
    

    // Bloco executado quando está removendo o ultimo elemento
    if( fila->inicio == fila->fim ) {
        fila->inicio = -1;
        fila->fim = -1;
    }
    else {
        fila->inicio = (fila->inicio + 1) % MAX;
    }

    return true;
}

void exibir(tFila fila) {

    int contador = fila.inicio;
    
    while(contador != fila.fim) {
        printf("Posicao %i\n", contador);
        printf("Nome: %s\n", fila.vetor[contador].nome);
        printf("Valor: %.2f\n\n", fila.vetor[contador].valor);
        
        contador++;

        if (contador == MAX) {
            contador = 0;
        }
    }

    printf("Posicao %i\n", contador);
    printf("Nome: %s\n", fila.vetor[contador].nome);
    printf("Valor: %.2f\n\n", fila.vetor[contador].valor);
}








