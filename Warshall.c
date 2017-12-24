/* +----------------------------------------------------
	| IMPLEMENTACIÓN DEL ALGORITMO DE WARSHALL
	|
	|	- Creo un tipo matriz para no usar el típico array bidimensional
	|	- Además, así puedes usar este código para algún otro proyecto
	|
	+---------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (x > y)?x:y

// Definimos un tipo matriz (de adyacencia). Recordemos que es cuadrada
typedef struct t_matrix {
	unsigned dimension;
	int** edgeSet;
} AdjacencyMatrix;

// Función para crear una nueva matriz
AdjacencyMatrix* getNewMatrix(unsigned size){
	unsigned i;
	AdjacencyMatrix* m = (AdjacencyMatrix*) malloc(sizeof(AdjacencyMatrix));
	m->dimension = size;
	m->edgeSet = (int**) malloc(size*sizeof(int*));
	for(i=0; i<size; i++)
		m->edgeSet[i] = (int*) malloc(size*sizeof(int));
	return m;
}

// Función para llenar una matriz
void fillMatrix(AdjacencyMatrix* M){
	unsigned i, j;
	for(i=0; i<M->dimension; i++)
		for(j=0; j<M->dimension; j++){
			printf("\nM[%d][%d]: ", i, j);
			scanf("%d", &M->edgeSet[i][j]);
			// Validamos que sea de adyacencia
			if(abs(1-M->edgeSet[i][j]) > 1){
				printf("\n\tERROR: La matriz solo admite valores binarios\n");
				j--;
			}
		}
}

// Función para imprimir los valores de una matriz
void printMatrix(AdjacencyMatrix* M){
	unsigned i, j;
	for(i=0; i<M->dimension; i++){
		printf("\n\n\t");
		for(j=0; j<M->dimension; j++)
			printf("%d ", M->edgeSet[i][j]);
	}
}

// Implementación del algoritmo de Warshall
AdjacencyMatrix* Warshall(AdjacencyMatrix* M){
	AdjacencyMatrix* Wk = M;
	unsigned i, j, k;
	for(i=0; i<M->dimension; i++)
		for(j=0; j<M->dimension; j++)
			for(k=0; k<M->dimension; k++)
				Wk->edgeSet[j][k] = MAX(Wk->edgeSet[j][k], (Wk->edgeSet[j][i] & Wk->edgeSet[i][k]));
	return Wk;
}

int main(){
	// La matriz del vídeo es de dimensión 5
	AdjacencyMatrix* ADJ_MATRIX = getNewMatrix(5);
	fillMatrix(ADJ_MATRIX);
	printMatrix(ADJ_MATRIX);
	printMatrix(Warshall(ADJ_MATRIX));
	free(ADJ_MATRIX);
	return 0;
}
