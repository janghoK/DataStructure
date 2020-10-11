#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		int key;
		int value;
};

class HashTable {
	private:
		Node *table;
		int tableSize;

	public:
		HashTable(int size) {
			tableSize = size;
			table = (Node*)malloc(sizeof(Node) * tableSize);
		};
		void DestroyHashTable();
		void Set(int key, int value);
		int Get(int key);
		int Hash(int key);
};
