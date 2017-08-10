/*
	ORDENAMIENTO BURBUJA

	+ Todavía hasta 10,000 elementos los ordena en menos de 1 segundo
	+ Recuerda nunca usar esto en la vida real por complejidad O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 10000

void bubbleSort(int Array[], int arraySize){
	int i, j, temp;
	for(i=0; i<arraySize-1; i++)
		for(j=0; j<arraySize-i-1; j++)
			if(Array[j] > Array[j+1]){
				temp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = temp;
			}
}

int main(){
	int numbers[ITEMS], i;
	// Semilla para generar valores distintos cada ejecución
	srand(time(NULL));
	// Llenamos el arreglo con números aleatorios
	for(i=0; i<ITEMS; i++)
		numbers[i] = rand();
	// Y ejecutamos el ordenamiento
	bubbleSort(numbers, ITEMS);
	return 0;
}
