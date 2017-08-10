/*
	ORDENAMIENTO POR SELECCIÓN

	+ Recuerda nunca usar esto en la vida real por complejidad O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 10000

void selectionSort(int Array[], int arraySize){
	int i, j, temp, selectedIndex;
	for(i=0; i<arraySize-1; i++){
		selectedIndex = i;
		for(j=i+1; j<arraySize; j++){
			if(Array[j] < Array[selectedIndex])
				selectedIndex = j;
			temp = Array[selectedIndex];
			Array[selectedIndex] = Array[i];
			Array[i] = temp;
		}
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
	selectionSort(numbers, ITEMS);
	return 0;
}
