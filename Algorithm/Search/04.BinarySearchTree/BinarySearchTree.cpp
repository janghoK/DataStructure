#include "BinarySearchTree.hpp"

Node *BinarySearchTree::CreateNode(int newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = newData;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void BinarySearchTree::InsertNode(Node **tree, Node *newNode) {
	if(*tree == NULL) *tree = newNode;
	else if((*tree)->Data > newNode->Data) {
		if((*tree)->left == NULL) (*tree)->left = newNode;
		else InsertNode(&(*tree)->left, newNode);
	} else {
		if((*tree)->right == NULL) (*tree)->right = newNode;
		else InsertNode(&(*tree)->right, newNode);
	}
}

void BinarySearchTree::DestroyNode(Node *node) {
	free(node);
}

void BinarySearchTree::DestroyTree(Node *tree) {
	if(tree->left != NULL) DestroyTree(tree->left);
	if(tree->right != NULL) DestroyTree(tree->right);
	DestroyNode(tree);
}

Node *BinarySearchTree::Search(Node *tree, int target) {
	if(tree == NULL) return NULL;
	if(tree->Data == target) return tree;
	else if(tree->Data > target) return Search(tree->left, target);
	else return Search(tree->right, target);
}

Node *BinarySearchTree::SearchMin(Node *tree) {
	if(tree->left != NULL) return SearchMin(tree->left);
	return tree;
}

Node *BinarySearchTree::RemoveNode(Node *tree, Node *parent, int target) {
	Node *removed = NULL;
	if(tree == NULL) return NULL;
	if(tree->Data > target) removed = RemoveNode(tree->left, tree, target);
	else if(tree->Data < target) removed = RemoveNode(tree->right, tree, target);
	else {
		removed = tree;
		if(tree->left == NULL && tree->right == NULL) {
			if(tree == parent->left) parent->left = NULL;
			else parent->right = NULL;
		} else if(tree->left != NULL && tree->right != NULL) {
			Node *minNode = SearchMin(tree->right);
			removed = RemoveNode(tree->right, NULL, minNode->Data);
			tree->Data = minNode->Data;
		} else {
			Node *temp = NULL;
			if(tree->left != NULL) temp = tree->left;
			else temp = tree->right;
			if(tree == parent->left) parent->left = temp;
			else parent->right = temp;
		}
	}
	return removed;
}

void BinarySearchTree::PrintTree(Node *tree) {
	if(tree->left != NULL) PrintTree(tree->left);
	printf("%d ", tree->Data);
	if(tree->right != NULL) PrintTree(tree->right);
}
