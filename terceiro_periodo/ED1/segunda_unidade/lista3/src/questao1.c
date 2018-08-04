/* Questão 1 da lista 3.
 * Implementando um algoritmo de busca linear em uma estrutura estática.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int procuraInt(int array[], int tamanho, int procurado);
int procuraChar(char array[], int tamanho, char procurado);

int main() {

    char procurado;
    char array[] = "Arlicia";
    int tam = strlen(array);

    printf("Qual caractere você quer procurar no array?");
    scanf("%c", &procurado);

    int busca = procuraChar(array, tam, procurado);

    printf("Entrada: %s\n", array);

    if(busca) {
    	printf("O valor %c foi encontrado na posicao %i do array!!\n", procurado, busca);
    }
    else {
    	printf("RETRNO DA BUSCA = %i. O valor %c não foi encontrado no array!\n",busca, procurado);
    }

    return 0;
}

int procuraChar(char vetor[], int tamanho, char elementoProcurado) {

    int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == elementoProcurado) {
            return i;
        }
    }

    return -1;
}
