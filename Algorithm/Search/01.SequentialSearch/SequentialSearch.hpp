#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		int Data;
		Node *nextNode;
};

class SequentialSearch {
	public:
		Node *CreateNode(int newData);
		void InsertNode(Node **head,Node *newNode);
		void DestroyNode(Node *node);
		void DestroyList(Node *head);
		Node *SearchNode(Node *head, int data);
		void PrintNode(Node *head);
};
