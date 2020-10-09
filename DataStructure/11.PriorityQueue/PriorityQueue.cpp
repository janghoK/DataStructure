#include "PriorityQueue.hpp"

Node *PriorityQueue::CreateNode(int newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = newData;
	newNode->nextNode = NULL;

	return newNode;
}

void PriorityQueue::InsertNode(Node *newNode) {
	if(front == NULL) front = newNode;
	else {
		if(front->Data >= newNode->Data) {
			newNode->nextNode = front;
			front = newNode;
		} else {
			Node *temp = front;
			while(temp != NULL) {
				if((temp->nextNode != NULL && temp->nextNode->Data >= newNode->Data) || (temp->nextNode == NULL && temp->Data < newNode->Data)) {
					newNode->nextNode = temp->nextNode;
					temp->nextNode = newNode;
					return;
				}
				temp = temp->nextNode;
			}
		}
	}
}

Node *PriorityQueue::RemoveNode(int data) {
	if(front == NULL) return NULL;

	Node *temp = front;
	Node *prev = NULL;
	while(temp != NULL) {
		if(temp->Data == data) {
			if(prev == NULL) front = temp->nextNode;
			else prev->nextNode = temp->nextNode;
			return temp;
		}
		prev = temp;
		temp = temp->nextNode;
	}

	return NULL;
}

void PriorityQueue::DestroyNode(Node *node) {
	if(node == NULL) return;
	free(node);
}

void PriorityQueue::DestroyQueue() {
	Node *temp = front;
	while(temp != NULL) {
		DestroyNode(temp);
		temp = front->nextNode;
		front = temp;
	}
}

void PriorityQueue::Pop() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	Node *temp = front;
	Node *prev = NULL;
	while(temp->nextNode != NULL) {
		prev = temp;
		temp = temp->nextNode;
	}
	if(prev != NULL) prev->nextNode = NULL;
	else front = NULL;
	printf("Pop() : %d\n", temp->Data);
	DestroyNode(temp);
	
}

void PriorityQueue::PrintQueue() {
	if(front == NULL) return;
	Node *temp = front;
	while(temp != NULL) {
		printf("%d ", temp->Data);
		temp = temp->nextNode;
	}
	printf("\n");
}
