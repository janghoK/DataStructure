#define EMPTY 0
#define OCCUPIED 1

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

class Node {
	public:
		std::string key;
		std::string value;
		int status;
};

class HashTable {
	private:
		int opdCount;
		int tableSize;

		Node *table;

	public:
		HashTable(int initialSize) {
			table = (Node*)malloc(sizeof(Node) * initialSize);
			memset(table, 0, sizeof(Node) * initialSize);
			tableSize = initialSize;
			opdCount = 0;
		};
		void DestroyHashTable();
		void Set(std::string key, std::string value);
		std::string Get(std::string key);
		int Hash(std::string key);
		int Hash2(std::string key);
		void Rehash();
};
