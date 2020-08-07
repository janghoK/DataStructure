#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		Node *parent;
		void *Data;
};

class DisjointSet {
	public:
		void UnionSet(Node *set1, Node *set2);
		Node *FindSet(Node *set);
		Node *MakeSet(void *newData);
		void DestroySet(Node *node);
		int isUnion(Node *set1, Node *set2);
};
