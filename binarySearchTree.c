/*
	IMPLEMENTACIÓN DE ÁRBOL BINARIO DE BÚSQUEDA
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
    int value;
    struct t_node* leftChild;
    struct t_node* rightChild;
}Node;

Node* FindMin(Node* node){
    if(node == NULL)
        return NULL;
    if(node->leftChild)
        return FindMin(node->leftChild);
    else 
        return node;
}

Node* FindMax(Node* node){
    if(node == NULL)
        return NULL;
    if(node->rightChild)
        FindMax(node->rightChild);
    else 
        return node;
}

Node* Insert(Node* node, int value){
    if(node == NULL){
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->value = value;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
        return temp;
    }
    if(value > node->value)
        node->rightChild = Insert(node->rightChild, value);
    else if(value <= node->value)
        node->leftChild = Insert(node->leftChild, value);
    return node;
}

Node* Find(Node* node, int value){
    if(node==NULL)
        return NULL;
    if(value > node->value)
        return Find(node->rightChild, value);
    else if(value < node->value)
        return Find(node->leftChild, value);
    else
        return node;
}

Node* Delete(Node* node, int value){
    Node* temp;
    if(node == NULL)
        printf("Element not found");
    else if(value < node->value)
        node->leftChild = Delete(node->leftChild, value);
    else if(value > node->value)
        node->rightChild = Delete(node->rightChild, value);
    else {
        if(node->rightChild && node->leftChild){
            temp = FindMin(node->rightChild);
            node->value = temp->value;
            node->rightChild = Delete(node->rightChild, temp->value);
        } else {
            temp = node;
            if(node->leftChild == NULL)
                node = node->rightChild;
            else if(node->rightChild == NULL)
                node = node->leftChild;
            free(temp);
        }
    }
    return node;
}

void PrintInorder(Node* node){
    if(node==NULL)
        return;
    PrintInorder(node->leftChild);
    printf("%d ",node->value);
    PrintInorder(node->rightChild);
}

void PrintPreorder(Node* node){
    if(node==NULL)
        return;
    printf("%d ",node->value);
    PrintPreorder(node->leftChild);
    PrintPreorder(node->rightChild);
}

void PrintPostorder(Node *node){
    if(node==NULL)
        return;
    PrintPostorder(node->leftChild);
    PrintPostorder(node->rightChild);
    printf("%d ",node->value);
}

int main(){
    Node* root = NULL;
    root = Insert(root, 5);
    root = Insert(root, -1);
    root = Insert(root, 3);
    root = Insert(root, -14);
    root = Insert(root, 8);
    root = Insert(root, 10);
    root = Insert(root, 9);
    root = Insert(root, 6);
    PrintInorder(root);
    printf("\n");
    root = Delete(root, 5);
    root = Delete(root, -1);
    PrintInorder(root);
    printf("\n");
    Node* temp;
    temp = FindMin(root);
    printf("Minimum element is %d\n",temp->value);
    temp = FindMax(root);
    printf("Maximum element is %d\n",temp->value);
    temp = Find(root,8);
    if(temp == NULL)
        printf("Element 8 not found\n");
    else
        printf("Element 8 Found\n");
    temp = Find(root, 2);
    if(temp == NULL)
        printf("Element 2 not found\n");
    else
        printf("Element 2 Found\n");
    free(root);
    return 0;
}
