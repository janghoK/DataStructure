#include "HashTable.hpp"

void HashTable::DestroyHashTable() {
	free(table);
}

void HashTable::Set(int key, int value) {
	int addr = Hash(key);

	table[addr].key = key;
	table[addr].value = value;
}

int HashTable::Get(int key) {
	int addr = Hash(key);

	return table[addr].value;
}

int HashTable::Hash(int key) {
	return key % tableSize;
}
