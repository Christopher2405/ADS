/*
	IMPLEMENTACIÓN DE PILAS

	+ Siguen el algoritmo LIFO
	+ Sólo permiten meter elementos y sacar el último de ellos
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
	int value;
	t_node* next;
}Node;

typedef struct t_stack{
	int size;
	Node* top;
}Stack;

Stack* getNewStack(){
	Stack* s = (Stack*) malloc(sizeof(Stack));
	s->size = 0;
	s->top = NULL;
	return s;
}

void push(Stack* s, int value){
	if(s){
		Node* node = (Node*) malloc(sizeof(Node));
		node->value = value;
		node->next = s->top;
		s->top = node;
		s->size++;
	}
}

int pop(Stack* s){
	if(s){
		if(s->size){
			int returnValue;
			Node* aux = s->top;
			returnValue = aux->value;
			s->top = s->top->next;
			s->size--;
			free(aux);
			return returnValue;
		}
	}
}

int main(){
	Stack* STACK = getNewStack();
	push(STACK, 10);
	push(STACK, 20);
	push(STACK, 30);
	push(STACK, 40);
	push(STACK, 50);
	printf("\n%d", pop(STACK));
	printf("\n%d", pop(STACK));
	printf("\n%d", pop(STACK));
	printf("\n%d", pop(STACK));
	printf("\n%d", pop(STACK));
	free(STACK);
	return 0;
}
