#include "LinkedQueue.hpp"

QNode *LinkedQueue::CreateNode(Vertex *v) {
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = v;
	newNode->next = NULL;

	return newNode;
}

void LinkedQueue::DestroyNode(QNode *node) {
	free(node);
}

void LinkedQueue::DestroyQueue() {
	while(queue != NULL) {
		QNode *temp = queue->next;
		free(queue);
		queue = temp;
	}
}

void LinkedQueue::Enqueue(QNode *node) {
	if(queue == NULL) queue = node;
	else {
		QNode *temp = queue;
		while(temp->next != NULL) temp = temp->next;
		temp->next = node;
	}
}

QNode *LinkedQueue::Dequeue() {
	if(queue == NULL) return NULL;

	QNode *node = queue;
	queue = queue->next;

	return node;
}

int LinkedQueue::isEmpty() {
	return (queue == NULL ? 1 : 0);
}

void LinkedQueue::PrintQueue() {
	QNode *temp = queue;
	if(temp != NULL) {
		std::cout << (char)temp->data->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
