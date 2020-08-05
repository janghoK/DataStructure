#include <stdio.h>
#include <stdlib.h>
#include <string>

class Node {
	public:
		Node *Left;
		Node *Right;
		char Data;
};

class ExpressionTree {
	public:
		Node *CreateNode(char newData);
		void DestroyNode(Node *node);
		void DestroyTree(Node *root);
		void PrintTree(Node *root, int mode);
		void BuildExpressionTree(std::string *postfixExpression, Node **node);
		double Evaluate(Node *tree);
};
