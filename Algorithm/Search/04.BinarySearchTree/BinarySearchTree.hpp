#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		int Data;
		Node *left;
		Node *right;
};

class BinarySearchTree {
	public:
		Node *CreateNode(int newData);
		void InsertNode(Node **tree, Node *newNode);
		void DestroyNode(Node *node);
		void DestroyTree(Node *tree);
		Node *Search(Node *tree, int target);
		Node *SearchMin(Node *tree);
		Node *RemoveNode(Node *tree, Node *parent, int target);
		void PrintTree(Node *tree);
};
