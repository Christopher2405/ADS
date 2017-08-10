/*
	ORDENAMIENTO RADIX

	+ Este es el algoritmo de ordenamiento más eficiente
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 100000

// Hacer intercambio de valores
void swap(unsigned *a, unsigned *b){
    unsigned tmp = *a;
    *a = *b;
    *b = tmp;
}
 
// Lectura y clasificación de cifras
void bitReader(unsigned* from, unsigned* to, unsigned bit){
	if(!bit || to < from + 1)
		return;
	unsigned* ll = from, *rr = to - 1;
	for(;;){
		while(ll < rr && !(*ll & bit)) ll++;
		while(ll < rr &&  (*rr & bit)) rr--;
		if(ll >= rr) break;
		swap(ll, rr);
	}
	if(!(bit & *ll) && ll < to) ll++;
	bit >>= 1;
	bitReader(from, ll, bit);
	bitReader(ll, to, bit);
}
 
// Función principal del ordenamiento
static void radixSort(int* Array, int arraySize){
	int i;
	unsigned* x = (unsigned*) Array;
	for(i=0; i<arraySize; i++) 
		x[i] ^= INT_MIN;
	bitReader(x, x+arraySize, INT_MIN);
	for(i=0; i<arraySize; i++) 
		x[i] ^= INT_MIN;
}
 
int main(){
	int testValues[ITEMS], i;
	srand(time(NULL));
	for(i=0; i<ITEMS; i++) 
		testValues[i] = rand();
	radixSort(testValues, ITEMS);
	return 0;
}
