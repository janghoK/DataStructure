#include "LCRSTree.hpp"

Node *LCRSTree::CreateNode(char newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->LeftChild  = NULL;
	newNode->RightSibling = NULL;
	newNode->Data       = newData;

	return newNode;
}

void LCRSTree::DestroyNode(Node *node) {
	free(node);
}

void LCRSTree::DestroyTree(Node *root) {
	if(root->LeftChild != NULL)
		DestroyTree(root->LeftChild);
	if(root->RightSibling != NULL)
		DestroyTree(root->RightSibling);

	DestroyNode(root);
}

void LCRSTree::AddChildNode(Node *parent, Node *child) {
	if(parent->LeftChild == NULL) {
		parent->LeftChild = child;
	} else {
		Node *tempNode = parent->LeftChild;
		while(tempNode->RightSibling != NULL)
			tempNode = tempNode->RightSibling;

		tempNode->RightSibling = child;
	}
}

void LCRSTree::PrintTree(Node *node, int depth) {
	for(int i=0;i<depth;i++) printf("  ");
	printf("%c\n", node->Data);
	if(node->LeftChild != NULL) 
		PrintTree(node->LeftChild, depth+1);
	if(node->RightSibling != NULL) 
		PrintTree(node->RightSibling, depth);

}
