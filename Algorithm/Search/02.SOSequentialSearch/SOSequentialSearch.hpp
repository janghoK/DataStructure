#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		Node *nextNode;
		Node *prevNode;
		int Data;
};

class SOSequentialSearch {
	public:
		Node *CreateNode(int newData);
		void AppendNode(Node **head, Node *newNode);
		void DestroyNode(Node *node);
		void DestroyList(Node *head);
		void PrintNode(Node *head);
		Node *MoveToFront(Node **head, int target);
		Node *Transpose(Node **head, int target);
};
