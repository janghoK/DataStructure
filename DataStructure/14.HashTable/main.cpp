#include "HashTable.hpp"

int main(void) {
	HashTable table(193);

	table.Set(39, 20190610);
	table.Set(1000, 20210330);
	table.Set(72, 19980617);
	table.Set(1, 20201011);


	printf("key: %d, value: %d\n", 39, table.Get(39));
	printf("key: %d, value: %d\n", 1000, table.Get(1000));
	printf("key: %d, value: %d\n", 72, table.Get(72));
	printf("key: %d, value: %d\n", 1, table.Get(1));

	table.DestroyHashTable();
	
	return 0;
}
