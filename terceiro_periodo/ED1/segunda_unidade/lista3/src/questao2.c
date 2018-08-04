/*
 * Questão 1 da lista 3.
 * Implementando um algoritmo de busca linear em uma estrutura dinâmica, lista simplismente encadeada.
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct sElemento {
    int id;
    char nome[50];
    struct sElemento* proxElemento;
} tElemento;


tElemento* inicializarcabeca();
tElemento* criarNovoElemento(char nome[]);

void inserirElementoFim(tElemento* cabeca, char nome[]);
void inserirElementoInicio(tElemento* cabeca, char nome[]);    

tElemento* buscarAnterior(tElemento* cabeca, int id);
tElemento* remover(tElemento* cabeca, int id);


int main() {

    tElemento* cabeca = inicializarcabeca();
    int i;
    char nome[50];

    for(i = 0; i < 5; i++) {
        printf("Digite um nome: ");
        scanf("%s", &nome);
        inserirElementoFim(cabeca, nome);
    }
    


    
    return 0;
}

bool buscaLinearDinamica(tElemento* cabeca, char entrada[]) {

    tElemento* p = cabeca->proxElemento;

    if(p == NULL) {
        printf("Lista vazia,não tem o que buscar nela.");
        return false;
    }
    else {

        while( p->proxElemento != NULL ) {

            if( !strcmp(p->nome, entrada) )

            p = p->proxElemento;
        }


    }



}


tElemento* inicializarcabeca() {
    tElemento* cabeca = (tElemento*) calloc(1, sizeof(tElemento));
    
    strcpy(cabeca->nome, "");
    cabeca->proxElemento = NULL;
    cabeca->id = 1;

    return cabeca;  

}

tElemento* criarNovoElemento(tElemento* cabeca, char nome[]) {

    tElemento* novoElemento = (tElemento*) calloc(1, sizeof(tElemento));

    strcpy(novoElemento->nome, nome);
    novoElemento->id = cabeca->id;

    novoElemento->proxElemento = NULL;

    cabeca->id++;

    return novoElemento;
}


void inserirElementoFim(tElemento* cabeca, char nome[]) {        
    tElemento* novoElemento = criarNovoElemento(cabeca, nome);
               
    // P saltitante para achar o final da lista
    tElemento* p = cabeca;
        
    while(p->proxElemento != NULL) {
        p = p->proxElemento;
    }
            
    p->proxElemento = novoElemento;

}

void inserirElementoInicio(tElemento* cabeca, char nome[]) {
    
        tElemento* novoElemento = criarNovoElemento(cabeca, nome);
    
        // Anexando elementos
        novoElemento->proxElemento = cabeca->proxElemento;
        cabeca->proxElemento = novoElemento;
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

