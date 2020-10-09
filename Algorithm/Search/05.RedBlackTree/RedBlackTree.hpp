#include <stdio.h>
#include <stdlib.h>

class Node {
	private:
		enum class eColor : unsigned int {RED = 0, BLACK = 1};

	public:
		Node *parent;
		Node *left;
		Node *right;
		eColor color = eColor::BLACK;
		int Data;

		void SetColor(int c);
		int GetColor();
};

class RedBlackTree {
	private:
		Node *NIL;
		
	public:
		RedBlackTree() {
			NIL = (Node*)malloc(sizeof(Node));
			NIL->left = NULL;
			NIL->right = NULL;
			NIL->SetColor(1);
		}
		Node *CreateNode(int newData);
		void InsertNodeBefore(Node **tree, Node *newNode);
		void InsertNode(Node **tree, Node *newNode);
		Node *RemoveNode(Node **tree, int Data);
		void DestroyNode(Node *node);
		void DestroyTree(Node *tree);
		void RotateNode(Node **tree, Node *parent, char direction);
		void RebuildAfterInsert(Node **tree, Node *x);
		void RebuildAfterRemove(Node **tree, Node *succesor);
		Node *SearchNode(Node *tree, int data);
		Node *SearchMinNode(Node *tree);
		void PrintTree(Node *tree, int depth, int bCnt);
};
