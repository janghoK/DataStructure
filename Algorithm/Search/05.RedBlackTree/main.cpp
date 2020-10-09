#include "RedBlackTree.hpp"

int main(void) {
	RedBlackTree t;
	Node *tree = NULL;
	Node *temp = NULL;

	t.InsertNode(&tree, t.CreateNode(10));
	t.InsertNode(&tree, t.CreateNode(9));
	t.InsertNode(&tree, t.CreateNode(8));
	t.InsertNode(&tree, t.CreateNode(7));
	t.InsertNode(&tree, t.CreateNode(6));
	t.InsertNode(&tree, t.CreateNode(5));
	t.InsertNode(&tree, t.CreateNode(4));
	t.InsertNode(&tree, t.CreateNode(3));
	t.InsertNode(&tree, t.CreateNode(2));
	t.InsertNode(&tree, t.CreateNode(1));

	t.PrintTree(tree, 0, 0);
	printf("\n");

	temp = t.RemoveNode(&tree, 7);
	t.PrintTree(tree, 0, 0);
	t.DestroyNode(temp);
	printf("\n");

	temp = t.RemoveNode(&tree, 5);
	t.PrintTree(tree, 0, 0);
	t.DestroyNode(temp);
	printf("\n");

	temp = t.RemoveNode(&tree, 10);
	t.PrintTree(tree, 0, 0);
	t.DestroyNode(temp);
	printf("\n");

	temp = t.RemoveNode(&tree, 2);
	t.PrintTree(tree, 0, 0);
	t.DestroyNode(temp);
	printf("\n");

	t.DestroyTree(tree);
	return 0;
}
