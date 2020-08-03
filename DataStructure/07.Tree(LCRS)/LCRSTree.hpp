#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		Node *LeftChild;
		Node *RightSibling;
		char Data;
};

class LCRSTree {
	public:
		Node *CreateNode(char newData);
		void DestroyNode(Node *node);
		void DestroyTree(Node *root);
		void AddChildNode(Node *parent, Node *child);
		void PrintTree(Node *node, int depth);
};
