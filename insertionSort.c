/*
	ORDENAMIENTO POR INSERCIÓN

	+ Recuerda nunca usar esto en la vida real por complejidad O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 10000

void insertionSort(int Array[], int arraySize){
   int i, j, key;
   for(i=1; i<arraySize; i++){
       key = Array[i];
       j = i-1;
       while(j >= 0 && Array[j] > key){
           Array[j+1] = Array[j];
           j--;
       }
       Array[j+1] = key;
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
	insertionSort(numbers, ITEMS);
	return 0;
}
