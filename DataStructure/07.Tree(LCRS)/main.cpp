#include "LCRSTree.hpp"

int main() {
	LCRSTree tree;
	Node *root = tree.CreateNode('A');
	Node *B = tree.CreateNode('B');
	Node *C = tree.CreateNode('C');
	Node *D = tree.CreateNode('D');
	Node *E = tree.CreateNode('E');
	Node *F = tree.CreateNode('F');
	Node *G = tree.CreateNode('G');

	tree.AddChildNode(root, B);
	tree.AddChildNode(root, E);

	tree.AddChildNode(B, C);
	tree.AddChildNode(B, D);
	
	tree.AddChildNode(E, F);
	tree.AddChildNode(E, G);

	tree.PrintTree(root, 0);

	tree.DestroyTree(root);

	return 0;
}
