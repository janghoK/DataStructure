#include "ExpressionTree.hpp"

Node *ExpressionTree::CreateNode(char newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->Data = newData;

	return newNode;
}

void ExpressionTree::DestroyNode(Node *node) {
	free(node);
}

void ExpressionTree::DestroyTree(Node *root) {
	if(root == NULL) return;
	DestroyTree(root->Left);
	DestroyTree(root->Right);
	DestroyNode(root);
}

void ExpressionTree::PrintTree(Node *root, int mode) {
	if(root == NULL) return;
	if(mode == 1) printf("%c ", root->Data);
	PrintTree(root->Left, mode);
	if(mode == 2) printf("%c ", root->Data);
	PrintTree(root->Right, mode);
	if(mode == 3) printf("%c ", root->Data);
}

void ExpressionTree::BuildExpressionTree(std::string *postfixExpression, Node **node) {
	char token = (*postfixExpression)[(*postfixExpression).length()-1];
	(*postfixExpression).resize((*postfixExpression).length()-1);

	switch(token) {
		case '+': case '-': case '*': case '/':
			(*node) = CreateNode(token);
			BuildExpressionTree(postfixExpression, &(*node)->Right);
			BuildExpressionTree(postfixExpression, &(*node)->Left);
			break;
		default:
			(*node) = CreateNode(token);
			break;
	}
}

double ExpressionTree::Evaluate(Node *tree) {
	//char temp[2];
	std::string temp="";
	double left, right, result = 0;
	
	if(tree == NULL) return 0;
	
	switch(tree->Data) {
		case '+' : case '-' : case '*' : case '/':
			left = Evaluate(tree->Left);
			right = Evaluate(tree->Right);
			if(tree->Data == '+') result = left + right;
			else if(tree->Data == '-') result = left - right;
			else if(tree->Data == '*') result = left * right;
			else if(tree->Data == '/') result = left / right;
			break;
		default:
			//memset(temp, 0, sizeof(temp));
			temp = tree->Data;
			//result = atof(temp);
			result = std::stod(temp);
			break;
	}
	return result;
}
