#include "SOSequentialSearch.hpp"

Node *SOSequentialSearch::CreateNode(int newData){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = newData;
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;

	return newNode;
}

void SOSequentialSearch::AppendNode(Node **head, Node *newNode){
	if(*head == NULL) *head = newNode;
	else {
		Node *currentNode = *head;
		while(currentNode->nextNode != NULL) currentNode = currentNode->nextNode;
		currentNode->nextNode = newNode;
		newNode->prevNode = currentNode;
	}
}

void SOSequentialSearch::DestroyNode(Node *node) {
	free(node);
}

void SOSequentialSearch::DestroyList(Node *head) {
	if(head->nextNode != NULL) DestroyList(head->nextNode);
	DestroyNode(head);
}

void SOSequentialSearch::PrintNode(Node *head) {
	printf("%d ", head->Data);
	while(head->nextNode != NULL) {
		head = head->nextNode;
		printf("%d ", head->Data);
	}
	printf("\n");
}

Node *SOSequentialSearch::MoveToFront(Node **head, int target) {
	printf("MoveToFront : %d -> ", target);
	Node *currentNode = *head;
	Node *match = NULL;
	while(currentNode !=  NULL) {
		if(currentNode->Data == target) {
			match = currentNode;
			if(currentNode->prevNode != NULL) {
				if(match->prevNode != NULL) match->prevNode->nextNode = match->nextNode;
				if(match->nextNode != NULL) match->nextNode->prevNode = match->prevNode;
				match->nextNode = *head;
				(*head)->prevNode = match;

				*head = match;
				(*head)->prevNode = NULL;
			}
			break;
		}
		currentNode = currentNode->nextNode;
	}
	return match;
}

Node *SOSequentialSearch::Transpose(Node **head, int target) {
	printf("Transpose : %d -> ", target);
	Node *currentNode = *head;
	Node *match = NULL;
	while(currentNode != NULL) {
		if(currentNode->Data == target) {
			match = currentNode;
			if(match->prevNode != NULL) {
				Node *prev = match->prevNode;
				Node *next = match->nextNode;

				match->prevNode = prev->prevNode;
				match->nextNode = prev;
				if(prev->prevNode != NULL) prev->prevNode->nextNode = match;

				if(prev->prevNode == NULL) *head = match;
				prev->prevNode = match;
				prev->nextNode = next;
				if(next != NULL) next->prevNode = prev;
			}
			break;
		}
		currentNode = currentNode->nextNode;
	}
	return match;
}
