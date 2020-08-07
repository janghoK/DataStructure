#include "DisjointSet.hpp"

void DisjointSet::UnionSet(Node *set1, Node *set2) {
	set2 = FindSet(set2);
	set2->parent = set1;
}

Node *DisjointSet::FindSet(Node *set) {
	while(set->parent != NULL) set = set->parent;
	return set;
}

Node *DisjointSet::MakeSet(void *newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->parent = NULL;
	newNode->Data = newData;
}

void DisjointSet::DestroySet(Node *node) {
	free(node);
}

int DisjointSet::isUnion(Node *set1, Node *set2) {
	return (FindSet(set1) == FindSet(set2)? 1:0); 
}
