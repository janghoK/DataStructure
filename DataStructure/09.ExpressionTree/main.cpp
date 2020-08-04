#include "ExpressionTree.hpp"

int main() {
	ExpressionTree tree;
	Node *root = NULL;

	char postfixExpression[10] = "36*53-+";
	tree.BuildExpressionTree(postfixExpression, &root);

	tree.PrintTree(root, 1);
	printf("\n");

	tree.PrintTree(root, 2);
	printf("\n");

	tree.PrintTree(root, 3);
	printf("\n");

	printf("%f", tree.Evaluate(root));
	printf("\n");


	return 0;
}
