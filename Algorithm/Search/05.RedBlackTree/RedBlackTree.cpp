#include "RedBlackTree.hpp"

void Node::SetColor(int c) {
	switch(c) {
		case 0:
			color = eColor::RED;
			break;

		case 1:
			color = eColor::BLACK;
			break;
	}	
}

int Node::GetColor() {
	switch(color) {
		case eColor::RED:
			return 0;
	
		case eColor::BLACK:
			return 1;
	}
	return -1;
}

Node *RedBlackTree::CreateNode(int newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = newData;
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->SetColor(1);

	return newNode;
}

void RedBlackTree::InsertNodeBefore(Node **tree, Node *newNode) {
	if(*tree == NULL) *tree = newNode;
	else {
		if((*tree)->Data > newNode->Data) {
			if((*tree)->left != NIL) InsertNodeBefore(&(*tree)->left, newNode);
			else {
				(*tree)->left = newNode;	
				newNode->parent = *tree;
			}
		} else {
			if((*tree)->right != NIL) InsertNodeBefore(&(*tree)->right, newNode);
			else {
				(*tree)->right = newNode; 
				newNode->parent = *tree;
			}
		}
	}
}

void RedBlackTree::InsertNode(Node **tree, Node *newNode) {
	InsertNodeBefore(tree, newNode);
	if(*tree != newNode) newNode->SetColor(0);
	newNode->left = NIL;
	newNode->right = NIL;
	RebuildAfterInsert(tree, newNode);
}

Node *RedBlackTree::RemoveNode(Node **tree, int data) {
	Node *removed = NULL;
	Node *succesor = NULL;
	Node *target = SearchNode(*tree, data);
	if(target == NULL) return NULL;
	if(target->left == NIL || target->right == NIL) removed = target;
	else {
		removed = SearchMinNode(target->right);
		target->Data = removed->Data;
	}

	if(removed->left != NIL) succesor = removed->left;
	else succesor = removed->right;
	succesor->parent = removed->parent;

	if(removed->parent == NULL) *tree = succesor;
	else {
		if(removed == removed->parent->left) removed->parent->left = succesor;
		else removed->parent->right = succesor;
	}

	if(removed->GetColor() == 1) RebuildAfterRemove(tree, succesor);
	return removed;
}

void RedBlackTree::DestroyNode(Node *node) {
	free(node);
}

void RedBlackTree::DestroyTree(Node *tree) {
	if(tree->left != NIL) DestroyTree(tree->left);
	if(tree->right != NIL) DestroyTree(tree->right);

	tree->left = NIL;
	tree->right = NIL;

	DestroyNode(tree);
}

void RedBlackTree::RotateNode(Node **tree, Node *parent, char direction) {
	if(direction != 'r' && direction != 'l') return;
	Node *child = (direction == 'r' ? parent->left : parent->right);
	if(parent->parent == NULL) *tree = child;
	else {
		if(parent->parent->left == parent) parent->parent->left = child;
		else parent->parent->right = child;
	}
	switch(direction) {
		case 'r':
			parent->left = child->right;
			if(child->right != NIL) child->right->parent = parent;
			child->right = parent;
			child->parent = parent->parent;
			parent->parent = child;
			break;
		case 'l':
			parent->right = child->left;
			if(child->left != NIL) child->left->parent = parent;
			child->left = parent;
			child->parent = parent->parent;
			parent->parent = child;
			break;
	}
}

void RedBlackTree::RebuildAfterInsert(Node **tree, Node *x) {
	while(x != (*tree) && x->parent->GetColor() == 0) {
		if(x->parent == x->parent->parent->left) {
			Node *uncle = x->parent->parent->right;
			if(uncle->GetColor() == 0) {
				x->parent->SetColor(1);
				uncle->SetColor(1);
				x->parent->parent->SetColor(0);
				x = x->parent->parent;
			} else {
				if(x == x->parent->right) {
					x = x->parent;
					RotateNode(tree, x, 'l');
				}
				x->parent->SetColor(1);
				x->parent->parent->SetColor(0);
				RotateNode(tree, x->parent->parent, 'r');
			}
		} else {
			Node *uncle = x->parent->parent->left;
			if(uncle->GetColor() == 0) {
				x->parent->SetColor(1);
				uncle->SetColor(1);
				x->parent->parent->SetColor(0);
				x = x->parent->parent;
			} else {
				if(x == x->parent->parent->left) {
					x = x->parent;
					RotateNode(tree, x, 'r');
				}
				x->parent->SetColor(1);
				x->parent->parent->SetColor(0);
				RotateNode(tree, x->parent->parent, 'l');
			}
		}
	}
	(*tree)->SetColor(1);
}

void RedBlackTree::RebuildAfterRemove(Node **tree, Node *succesor) {
	Node *sibling = NULL;
	while(succesor->parent != NULL && succesor->GetColor() == 1) {
		sibling = (succesor == succesor->parent->left ? succesor->parent->right : succesor->parent->left);
		if(succesor == succesor->parent->left) {
			if(sibling->GetColor() == 0) {
				sibling->parent->SetColor(0);
				sibling->SetColor(1);
				RotateNode(tree, succesor->parent, 'l');
			} else {
				if(sibling->left->GetColor() == 1 && sibling->right->GetColor() == 1) {
					sibling->SetColor(0);
					succesor = succesor->parent;
				} else {
					if(sibling->left->GetColor() == 0) {
						sibling->SetColor(0);
						sibling->left->SetColor(1);
						RotateNode(tree, sibling, 'r');
						sibling = succesor->parent->right;
					}
					sibling->SetColor(succesor->parent->GetColor());
					succesor->parent->SetColor(1);
					sibling->right->SetColor(1);
					RotateNode(tree, succesor->parent, 'l');
					succesor = *tree;
				}
			}
		} else {
			if(sibling->GetColor() == 0) {
				sibling->parent->SetColor(0);
				sibling->SetColor(1);
				RotateNode(tree, succesor->parent, 'r');
			} else {
				if(sibling->right->GetColor() == 1 && sibling->left->GetColor() == 1) {
					sibling->SetColor(0);
					succesor = succesor->parent;
				} else {
					if(sibling->right->GetColor() == 0) {
						sibling->SetColor(0);
						sibling->right->SetColor(1);
						RotateNode(tree, sibling, 'l');
						sibling = succesor->parent->left;
					}
					sibling->SetColor(succesor->parent->GetColor());
					succesor->parent->SetColor(1);
					sibling->left->SetColor(1);
					RotateNode(tree, succesor->parent, 'r');
					succesor = *tree;
				}
			}
		}
	}
	succesor->SetColor(1);
}

Node *RedBlackTree::SearchNode(Node *tree, int data) {
	if(tree == NIL) return NULL;
	if(tree->Data == data) return tree;
	if(tree->Data > data) return SearchNode(tree->left, data);
	else return SearchNode(tree->right, data);
}

Node *RedBlackTree::SearchMinNode(Node *tree) {
	if(tree == NULL) return NULL;
	if(tree->left == NIL) return tree;
	return SearchMinNode(tree->left);
}

void RedBlackTree::PrintTree(Node *tree, int depth, int bCnt) {
	if(tree == NULL) return;

	for(int i=0;i<depth;i++) printf("  ");
	printf("%d", tree->Data);
	if(tree->parent != NULL) {
		char dir = (tree == tree->parent->left ? 'L' : 'R');
		printf("[%d,%c]", tree->parent->Data, dir);
	}
	
	if(tree->GetColor() == 0) printf(" RED");
	else {printf(" BLACK"); bCnt++;}


	if(tree->left == NIL && tree->right == NIL) {
		printf(" BLACKCOUNT: %d", bCnt);
	}
	printf("\n");

	if(tree->left != NIL) PrintTree(tree->left, depth+1, bCnt);
	if(tree->right != NIL) PrintTree(tree->right, depth+1, bCnt);


}
