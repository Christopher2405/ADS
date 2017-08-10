/*
	ORDENAMIENTO RÁPIDO

	+ El caso promedio de este algoritmo es O(nlogn)
	+ Su peor caso lo llevaría hasta O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 100000

void quickSort(int Array[], unsigned int arraySize){
	if(arraySize >= 2){
		int pivot = Array[arraySize/2];
		int i, j, temp;
		for(i=0, j=arraySize-1; ; i++, j--){
			while(Array[i] < pivot) i++;
			while(Array[j] > pivot) j--;
			if(i >= j) break;
			temp = Array[i];
			Array[i] = Array[j];
			Array[j] = temp;
		}
		quickSort(Array, i);
		quickSort(Array+i, arraySize-i);
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
	quickSort(numbers, ITEMS);
	return 0;
}
