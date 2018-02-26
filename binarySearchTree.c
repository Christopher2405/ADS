/*
	IMPLEMENTACIÓN DE UN ÁRBOL BINARIO DE BÚSQUEDA
	
	+ La función ELIMINAR del video no funcionaba, el detalle se ha corregido
	
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct t_tree {
	int data;
	t_tree* leftChild;
	t_tree* rightChild;
} BinarySearchTree;

BinarySearchTree* getNode(int value){
	BinarySearchTree* node = (BinarySearchTree*) malloc(sizeof(BinarySearchTree));
	node->data = value;
	node->leftChild = node->rightChild = NULL;
	return node;
}

BinarySearchTree* insert(BinarySearchTree* root, int value){
	if(root == NULL){
		return getNode(value);
	} else if(root->data == value){
		printf("\n\n\tERROR: Es valor %d ya existe en el arbol", value);
	} else if(value < root->data){
		root->leftChild = insert(root->leftChild, value);
	} else {
		root->rightChild = insert(root->rightChild, value);
	}
	return root;
}

BinarySearchTree* search(BinarySearchTree* root, int value){
	if(root == NULL){
		printf("\n\n\tERROR: El valor %d no existe\n", value);
		return NULL;
	} else if(root->data == value){
		return root;
	} else if(value < root->data){
		search(root->leftChild, value);
	} else {
		search(root->rightChild, value);
	}
}

void update(BinarySearchTree* root, int value, int newValue){
	if((root = search(root, value))){
		root->data = newValue;
	}
}

void preOrder(BinarySearchTree* root){
	if(root == NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->leftChild);
	preOrder(root->rightChild);
}

void inOrder(BinarySearchTree* root){
	if(root == NULL)
		return;
	inOrder(root->leftChild);
	printf("%d ", root->data);
	inOrder(root->rightChild);
}

void postOrder(BinarySearchTree* root){
	if(root == NULL)
		return;
	postOrder(root->leftChild);
	postOrder(root->rightChild);
	printf("%d ", root->data);
}

BinarySearchTree* remove(BinarySearchTree* root, int value){
	if(root == NULL)
		return NULL;
	else if(value < root->data)
		root->leftChild = remove(root->leftChild, value);
	else if(value > root->data)
		root->rightChild = remove(root->rightChild, value);
	else {
		if(root->leftChild==NULL && root->rightChild==NULL)
			root = NULL;
		else if(root->leftChild == NULL)
			root = root->rightChild;
		else if(root->rightChild == NULL)
			root = root->leftChild;
		else {
			BinarySearchTree* explorer = root->rightChild;
			while(explorer->leftChild)
				explorer = explorer->leftChild;
			root->data = explorer->data;
			root->rightChild = remove(root->rightChild, explorer->data);
		}
	}
	return root;
}

void destroyTree(BinarySearchTree* root){
	if(root == NULL)
		return;
	destroyTree(root->leftChild);
	destroyTree(root->rightChild);
	free(root);
	root->data = 0;
	root = root->leftChild = root->rightChild = NULL;
}

int main(){
	BinarySearchTree* TREE = NULL;
	TREE = insert(TREE, 5);
	insert(TREE, 8);
	insert(TREE, 3);
	insert(TREE, 15);
	insert(TREE, 1);
	preOrder(TREE);
	update(TREE, 15, 16);
	printf("\n");
	preOrder(TREE);
	search(TREE, 32);
	remove(TREE, 16);
	printf("\n");
	preOrder(TREE);
	printf("\n");
	inOrder(TREE);
	printf("\n");
	postOrder(TREE);
	destroyTree(TREE);
	return 0;
}
