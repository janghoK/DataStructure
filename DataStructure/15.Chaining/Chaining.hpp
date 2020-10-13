#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

class Node {
	public:
		std::string key;
		std::string value;
		Node *next;
};

class HashTable {
	private:
		int tableSize;
		Node **table;

	public:
		HashTable(int initialSize) {
			tableSize = initialSize;
			table = (Node**)malloc(sizeof(Node) * tableSize);
			
			memset(table, 0, sizeof(Node) * tableSize);
		};
		void DestroyHashTable();
		void DestroyList(Node *list);
		Node *CreateNode(std::string key, std::string value);
		void DestroyNode(Node *node);

		void Set(std::string key, std::string value);
		std::string Get(std::string key);
		int Hash(std::string key);
};
