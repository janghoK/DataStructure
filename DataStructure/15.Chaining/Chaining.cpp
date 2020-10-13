#include "Chaining.hpp"

void HashTable::DestroyHashTable() {
	for(int i=0;i<tableSize;i++) {
		Node *list = table[i];

		DestroyList(list);
	}

	free(table);
}

void HashTable::DestroyList(Node *list) {
	if(list == NULL) return;

	if(list->next != NULL) DestroyList(list->next);

	DestroyNode(list);
}

Node *HashTable::CreateNode(std::string key, std::string value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void HashTable::DestroyNode(Node *node) {
	free(node);
}

void HashTable::Set(std::string key, std::string value) {
	int addr = Hash(key);
	Node *newNode = CreateNode(key, value);

	if(table[addr] == NULL) table[addr] = newNode;
	else {
		Node *temp = table[addr];
		newNode->next = temp;
		table[addr] = newNode;

		std::cout << "Collision Occured : key(" << key << "), addr(" << addr << ")" << std::endl;
	}
}

std::string HashTable::Get(std::string key) {
	int addr = Hash(key);

	Node *list = table[addr];
	Node *target = NULL;

	if(list == NULL) return NULL;

	while(1) {
		if(list->key.compare(key) == 0) {
			target = list;
			break;
		}

		if(list->next == NULL) return NULL;
		else list = list->next;
	}

	return target->value;
}

int HashTable::Hash(std::string key) {
	int hashValue = 0;

	for(int i=0;i<key.length();i++) {
		hashValue = (hashValue << 3) + key[i];
	}

	hashValue = hashValue % tableSize;

	return hashValue;
}
