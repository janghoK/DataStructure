#include "BinaryTree.hpp"

int main() {
	BinaryTree tree;

	Node *root = tree.CreateNode('A');
	Node *B = tree.CreateNode('B');
	Node *C = tree.CreateNode('C');
	Node *D = tree.CreateNode('D');
	Node *E = tree.CreateNode('E');
	Node *F = tree.CreateNode('F');
	Node *G = tree.CreateNode('G');

	root->Left = B;
	B->Left = C;
	B->Right = D;
	root->Right = E;
	E->Left = F;
	E->Right = G;

	printf("Preorder\n");
	tree.PreorderPrintTree(root);
	printf("\nInorder\n");
	tree.InorderPrintTree(root);
	printf("\nPostorder\n");
	tree.PostorderPrintTree(root);

	tree.DestroyTree(root);

	return 0;
}
