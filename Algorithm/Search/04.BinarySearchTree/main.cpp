#include "BinarySearchTree.hpp"

int main(void) {
	BinarySearchTree search;
	Node *tree = NULL;

	search.InsertNode(&tree, search.CreateNode(50));
	search.InsertNode(&tree, search.CreateNode(20));
	search.InsertNode(&tree, search.CreateNode(1));
	search.InsertNode(&tree, search.CreateNode(25));
	search.InsertNode(&tree, search.CreateNode(23));
	search.InsertNode(&tree, search.CreateNode(41));
	search.InsertNode(&tree, search.CreateNode(100));
	search.InsertNode(&tree, search.CreateNode(60));
	search.InsertNode(&tree, search.CreateNode(200));

	search.PrintTree(tree);
	printf("\n");

	Node *result = NULL;
	result = search.Search(tree, 23);
	printf("result = %d\n", result->Data);
	result = search.Search(tree, 50);
	printf("result = %d\n", result->Data);
	result = search.Search(tree, 200);
	printf("result = %d\n", result->Data);
	result = search.Search(tree, 41);
	printf("result = %d\n", result->Data);
	result = search.Search(tree, 201);
	if(result == NULL) printf("NULL\n");

	search.RemoveNode(tree, NULL, 20);
	search.PrintTree(tree);
	printf("\n");
	search.RemoveNode(tree, NULL, 201);
	search.PrintTree(tree);
	printf("\n");

	search.DestroyTree(tree);

	return 0;
}
