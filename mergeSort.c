/*
    ORDENAMIENTO POR MEZCLA

    + El peor caso de este algoritmo es O(nlogn)
    + Por tanto, puedes usarlo en la práctica
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 100000

void merge(int* Array, int arraySize, int middle){
    int i, j, k;
    int newArray[arraySize];
    for(i=0, j=middle, k=0; k<arraySize; k++){
        newArray[k] = (j == arraySize) ? Array[i++]
                    : (i == middle) ? Array[j++]
                    : (Array[j] < Array[i]) ? Array[j++]
                    : Array[i++];
    }
    for(i=0; i<arraySize; i++)
        Array[i] = newArray[i];
}

void mergeSort(int* Array, int arraySize){
    if (arraySize < 2)
        return;
    int middle = arraySize / 2;
    mergeSort(Array, middle);
    mergeSort(Array+middle, arraySize-middle);
    merge(Array, arraySize, middle);
}

int main(){
    int numbers[ITEMS], i;
    // Semilla para generar valores distintos cada ejecución
    srand(time(NULL));
    // Llenamos el arreglo con números aleatorios
    for(i=0; i<ITEMS; i++)
        numbers[i] = rand();
    // Y ejecutamos el ordenamiento
    mergeSort(numbers, ITEMS);
    return 0;
}
