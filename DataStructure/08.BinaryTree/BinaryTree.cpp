#include "BinaryTree.hpp"

Node *BinaryTree::CreateNode(char newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->Data = newData;

	return newNode;
}

void BinaryTree::DestroyNode(Node *node) {
	free(node);
}

void BinaryTree::DestroyTree(Node *root) {
	if(root == NULL) return;
	DestroyTree(root->Left);
	DestroyTree(root->Right);
	DestroyNode(root);
}

void BinaryTree::PreorderPrintTree(Node *node) {
	if(node == NULL) return;
	printf("%c ", node->Data);
	PreorderPrintTree(node->Left);
	PreorderPrintTree(node->Right);
}

void BinaryTree::InorderPrintTree(Node *node) {
	if(node == NULL) return;
	InorderPrintTree(node->Left);
	printf("%c ", node->Data);
	InorderPrintTree(node->Right);
}

void BinaryTree::PostorderPrintTree(Node *node) {
	if(node == NULL) return;
	PostorderPrintTree(node->Left);
	PostorderPrintTree(node->Right);
	printf("%c ", node->Data);
}
