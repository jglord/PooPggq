#include <stdio.h>

#define  MAX 5
#define  TRUE 1
#define  FALSE 0

typedef struct sPilha {
    int vetor[MAX];
    int topo
}tPilha;

// Protótipos das funções básicas de manipulação de pilha
tPilha inicializar();
int empilhar(tPilha* pilha, int valor);
int desempilhar(tPilha* pilha, int* retorno);
void exibir(tPilha pilha);

int main(int argc, char const *argv[]) {

    tPilha pilha =  inicializar();
    int desempilhado, i, j, flag;

    // Ultimo caso é pra dá erro
    for(i = 0, j = 1; i < MAX+1; i++, j+=2) {
    
        printf("Empilhando o valor %i...\n", j);
        flag = empilhar(&pilha, j);
        printf("Flag atual = %i\n\n", flag);
    }
        
    if(desempilhar(&pilha, &desempilhado)) {
        printf("Retorno = %i\n", desempilhado);
    } 
    else {
        printf("Erro ao desempilhar\n");
    }

    printf("\n\n");

    exibir(pilha);
    
    return 0;
}

// Cria a pilha e inicializa o topo em -1
tPilha inicializar() {
    tPilha pilha;
    pilha.topo = -1;

    return pilha;  
}

// Testa se a pilha está cheia e empilha 1 elemento
int empilhar(tPilha* pilha, int valor) {
   
    int flag = TRUE;

    if( pilha->topo == MAX - 1 ) {
        printf("ERRO!!! Pilha cheia...\n");
        return FALSE;
    } 
    else {
        pilha->topo++;
        pilha->vetor[ pilha->topo ] = valor;
    }

    return TRUE;
}

// Testa se a pilha está vazia e desempilha 1 elemento
int desempilhar(tPilha* pilha, int* retorno) {
    printf("Desempilhando...\n");

    int flag = TRUE;

    if( pilha->topo == -1 ) {
        printf("ERRO!! Pilha vazia...\n");
        return FALSE;

    }
    else {
        *retorno = pilha->vetor[ pilha->topo ];
        pilha->topo--;

    }
    return TRUE;
}

void exibir(tPilha pilha) {
    int i;

    printf("Exibindo a pilha...\n");
    for(i = 0; i <= pilha.topo ; i++){
        printf("Elemento %i: [ %i ]\n", i, pilha.vetor[i]);
    }

}