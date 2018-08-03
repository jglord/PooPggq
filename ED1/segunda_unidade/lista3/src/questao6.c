#include <stdio.h>

#define MAX 10

int main() {
	
	int array[MAX] = { 3, 2, 5, 9, 0, 1, 4, 8, 7, 6 };
	int i, j, aux;
	
	printf("Vetor desordenado: ");
	for(i = 0; i < MAX; i++) {
		printf(" [%i] ", array[i]);
	} printf("\n");
	
	for(i = 0; i < MAX; i++) {
		
		for(j = 0; j < MAX-1; j++) {
			
			if( array[j] > array[j + 1] ){
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;				
			}
			
		}
		
	}
	
	
	printf("Vetor ordenado:    ");
	for(i = 0; i < MAX; i++) {
		printf(" [%i] ", array[i]);
	} printf("\n");
	
	
	
	
	return 0;
}
