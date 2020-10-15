#include "OpenAddressing.hpp"

void HashTable::DestroyHashTable() {
	free(table);
}


void HashTable::Set(std::string key, std::string value) {
	if((double)opdCount / tableSize > 0.5) Rehash();

	int addr = Hash(key);
	int step = Hash2(key);

	while(table[addr].status != EMPTY && table[addr].key.compare(key) != 0) {
		std::cout << "Collision occured : key(" << key << "), addr(" << addr << "), step(" << step << ")" << std::endl;
		addr = (addr + step) % tableSize;
	}

	table[addr].key = key;
	table[addr].value = value;
	table[addr].status = OCCUPIED;
	opdCount++;

	std::cout << "key(" << key << ") entered at addr(" << addr << ")" << std::endl;
}

std::string HashTable::Get(std::string key) {
	int addr = Hash(key);
	int step = Hash2(key);

	while(table[addr].status != EMPTY && table[addr].key.compare(key) != 0) 
		addr = (addr + step) % tableSize;
	
	return table[addr].value;
}

int HashTable::Hash(std::string key) {
	int hash = 0;

	for(int i=0;i<key.length();i++) {
		hash = (hash << 3) + key[i];
	}

	hash = hash % tableSize;

	return hash;
}

int HashTable::Hash2(std::string key) {
	int hash = 0;
	
	for(int i=0;i<key.length();i++) {
		hash = (hash << 2) + key[i];
	}

	hash = hash % (tableSize - 3);

	return hash + 1;
}

void HashTable::Rehash() {
	std::cout << "Rehas" << std::endl;
	Node *old = (Node*)malloc(sizeof(Node) * tableSize);
	memcpy(old, table, sizeof(Node) * tableSize);
	int oldSize = tableSize;

	tableSize = tableSize * 2;
	table = (Node*)realloc(table, sizeof(Node) * tableSize);
	memset(table, 0, sizeof(Node) * tableSize);
	opdCount = 0;

	for(int i=0;i<oldSize;i++) 
		if(old[i].status == OCCUPIED) Set(old[i].key, old[i].value);

	free(old);
}
