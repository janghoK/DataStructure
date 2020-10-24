#include "LinkedList.hpp"

Node *LinkedList::CreateNode(Vertex *newV) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->v = newV;
	newNode->nextNode = NULL;

	return newNode;
}

void LinkedList::DestroyNode(Node *node) {
	free(node);
}

void LinkedList::DestroyList() {
	if(list == NULL) return;
	while(list != NULL) {
		Node *temp = list->nextNode;
		DestroyNode(list);
		list = temp;
	}
}

void LinkedList::InsertHead(Node *node) {
	if(list == NULL) list = node;
	else {
		node->nextNode = list;
		list = node;
	}
}

Node *LinkedList::GetList() {
	return list;
}

void LinkedList::PrintList() {
	while(list != NULL) {
		std::cout << list->v->data << " ";
		list = list->nextNode;
	}
	std::cout << std::endl;
}
