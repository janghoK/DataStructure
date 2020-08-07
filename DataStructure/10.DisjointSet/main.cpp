#include "DisjointSet.hpp"

int main() {
	DisjointSet set;
	int a = 1, b = 2, c = 3;

	Node *set1 = set.MakeSet(&a);
	Node *set2 = set.MakeSet(&b);
	Node *set3 = set.MakeSet(&c);

	printf("Union(set1,set2) = %d\n", set.isUnion(set1, set2));

	set.UnionSet(set1, set2);
	printf("Union(set1,set2) = %d\n", set.isUnion(set1, set2));
	
	set.UnionSet(set2, set3);
	printf("Union(set1,set3) = %d\n", set.isUnion(set1, set3));
	printf("Union(set2,set3) = %d\n", set.isUnion(set2, set3));


	return 0;
}
