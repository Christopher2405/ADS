/*
	IMPLEMENTACIÓN DE COLAS
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int value;
	t_node* next;
}Node;

typedef struct t_queue{
	int size;
	Node* front;
	Node* tail;
}Queue;

Node* getNode(int value){
	Node* node = (Node*) malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

Queue* getNewQueue(){
	Queue* q = (Queue*) malloc(sizeof(Queue));
	q->size = 0;
	q->front = NULL;
	q->tail = NULL;
	return q;
}

void Enqueue(Queue* q, Node* node){
	if(q->front == NULL)	q->front = node;
	else	q->tail->next = node;
	q->tail = node;
	q->size++;
}

int Dequeue(Queue* q){
	if(q->size){
		int returnValue;
		Node* aux = q->front;
		returnValue = aux->value;
		q->front = q->front->next;
		free(aux);
		q->size--;
		return returnValue;
	}
	return -1;
}

int main(){
	Queue* QUEUE = getNewQueue();
	Node* a = getNode(10);
	Node* b = getNode(20);
	Node* c = getNode(30);
	Enqueue(QUEUE, a);
	Enqueue(QUEUE, b);
	Enqueue(QUEUE, c);
	printf("%d ", Dequeue(QUEUE));
	printf("%d ", Dequeue(QUEUE));
	printf("%d ", Dequeue(QUEUE));
	free(QUEUE);
	return 0;
}
