#include "InsertionSort.hpp"

int main(void) {
	InsertionSort sort;
	int DataSet[6] = {6, 1, 2, 5, 4, 3};

	sort.sort(DataSet, 6);

	for(int i=0;i<6;i++) printf("%d ", DataSet[i]);

	return 0;
}
