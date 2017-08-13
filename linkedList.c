/*
	IMPLEMENTACI�N DE LISTAS LIGADAS

	+ Despu�s de grabar el v�deo, note que el c�digo tiene un par de detalles:
	   - Si se elimina el �ltimo elemento, hay que indicarlo en la lista
		- No se decrementa el contador del tama�o de la lista
	   - La verificaci�n debe ser index<ll->size, m�s no index<ll->size-1

	+ Este c�digo ya tiene solucionados esos detalles, puedes usarlo con confianza
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int value;
	t_node* next;
}Node;

typedef struct t_list{
	int size;
	Node* firstItem;
	Node* lastItem;
}LinkedList;

Node* getNode(int value){
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

LinkedList* getNewLinkedList(){
	LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));
	ll->size = 0;
	ll->firstItem = NULL;
	ll->lastItem = NULL;
	return ll;
}

// Implementaci�n de las operaciones CRUD

void add(LinkedList* ll, Node* node){
	if(ll->firstItem == NULL)	ll->firstItem = node;
	else	ll->lastItem->next = node;
	ll->lastItem = node;
	ll->size++;
}

Node* read(LinkedList* ll, unsigned int index){
	if(ll->size && index<ll->size){
		Node* listExplorer = ll->firstItem;
		int i = 0;
		while(i++ < index)
			listExplorer = listExplorer->next;
		return listExplorer;
	}
}


void update(LinkedList* ll, unsigned int index, int newValue){
	if(ll->size && index<ll->size){
		Node* listExplorer = ll->firstItem;
		int i = 0;
		while(i++ < index)
			listExplorer = listExplorer->next;
		listExplorer->value = newValue;
	}
}

void remove(LinkedList* ll, unsigned int index){
	if(ll->size && index<ll->size){
		Node* aux;
		if(index == 0){
			aux = ll->firstItem;
			ll->firstItem = ll->firstItem->next;
		} else {
			Node* listExplorer = ll->firstItem;
			int i = 0;
			while(i++ <index-1)
				listExplorer = listExplorer->next;
			aux = listExplorer->next;
			if(index == ll->size-1){
				listExplorer->next = NULL;
				ll->lastItem = listExplorer;
			} else	listExplorer->next = listExplorer->next->next;
		}
		free(aux);
		ll->size--;
	}
}

int main(){
	LinkedList* LIST = getNewLinkedList();
	Node* a = getNode(1);
	Node* b = getNode(2);
	Node* c = getNode(3);
	add(LIST, a);
	add(LIST, b);
	add(LIST, c);
	printf("%d", read(LIST, 1)->value);
	update(LIST, 1, 10);
	printf("\n%d", read(LIST, 1)->value);
	remove(LIST, 0);
	printf("\n%d", read(LIST, 0)->value);
	free(LIST);
	return 0;
}


