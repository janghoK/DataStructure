#include "SequentialSearch.hpp"

Node *SequentialSearch::CreateNode(int newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->Data = newData;
	newNode->nextNode = NULL;

	return newNode;
}

void SequentialSearch::InsertNode(Node **head, Node *newNode) {
	if(*head == NULL) *head = newNode;
	else {
		Node *currentNode = *head;
		while(currentNode->nextNode != NULL)
			currentNode = currentNode->nextNode;

		currentNode->nextNode = newNode;
	}
}

void SequentialSearch::DestroyNode(Node *node) {
	free(node);
}

void SequentialSearch::DestroyList(Node *head) {
	if(head->nextNode != NULL) DestroyList(head->nextNode);
	DestroyNode(head);
}

Node *SequentialSearch::SearchNode(Node *head, int data) {
	while(head->nextNode != NULL) {
		if(head->Data == data) return head;
		head = head->nextNode;
	}
	return NULL;
}

void SequentialSearch::PrintNode(Node *head) {
	printf("%d ", head->Data);
	while(head->nextNode != NULL) {
		head = head->nextNode;
		printf("%d ", head->Data);
	}
	printf("\n");
}
