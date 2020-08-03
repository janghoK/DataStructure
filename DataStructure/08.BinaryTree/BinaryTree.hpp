#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		Node *Left;
		Node *Right;
		char Data;
};

class BinaryTree {
	public:
		Node *CreateNode(char Data);
		void DestroyNode(Node *node);
		void DestroyTree(Node *root);
		void PreorderPrintTree(Node *node);
		void InorderPrintTree(Node *node);
		void PostorderPrintTree(Node *node);
};
