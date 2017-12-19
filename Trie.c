#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define FALSE 0
#define TRUE 1

typedef struct t_node{
	t_node* letters[ALPHABET_SIZE];
	unsigned isEndOfWord;
} Node;

Node* getNewTrie(){
	unsigned i;
	Node* trie = (Node*) malloc(sizeof(Node));
	trie->isEndOfWord = FALSE;
	for(i=0; i<ALPHABET_SIZE; i++)
		trie->letters[i] = NULL;
	return trie;
}

void insert(Node* root, const char* word){
	Node* trieExplorer = root;
	unsigned i, index;
	for(i=0; i<strlen(word); i++){
		index = tolower(word[i]) - 'a';
		if(trieExplorer->letters[index] == NULL)
			trieExplorer->letters[index] = getNewTrie();
		trieExplorer = trieExplorer->letters[index];
	}
	trieExplorer->isEndOfWord = TRUE;
}

unsigned search(Node* root, const char* word){
	Node* trieExplorer = root;
	unsigned i, index;
	for(i=0; i<strlen(word); i++){
		index = tolower(word[i]) - 'a';
		if(trieExplorer->letters[index] == NULL)
			return FALSE;
		trieExplorer = trieExplorer->letters[index];
	}
	return (trieExplorer == NULL)?0:1;
}

int main(){
	Node* TRIE = getNewTrie();
	insert(TRIE, "algoritmos");
	insert(TRIE, "udemy");
	insert(TRIE, "christopher");
	insert(TRIE, "programacion");
	printf("%d\n", search(TRIE, "progra"));
	free(TRIE);
	return 0;
}
