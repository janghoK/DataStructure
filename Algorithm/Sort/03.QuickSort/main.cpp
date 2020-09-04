#include "QuickSort.hpp"

int main(void) {
	QuickSort sort;

	// 퀵정렬 알고리즘
	printf("QuickSort Algorithm\n");
	int DataSet[] = {9, 1, 5, 3, 8, 6, 4, 7, 2, 10};
	int left = 0;
	int right = sizeof(DataSet)/sizeof(DataSet[0])-1;

	sort.sort(DataSet, left, right);

	for(int i=0;i<right+1;i++)
		printf("%d ", DataSet[i]);
	printf("\n");

	// 표준 라이브러리 퀵정렬
	printf("standard library QuickSort\n");
	int DataSet2[] = {1, 4, 10, 2, 3, 9, 7, 8, 5, 6};
	int size = sizeof(DataSet2)/sizeof(DataSet2[0]);
	qsort((void*)DataSet2, size, sizeof(int), sort.compare);
	for(int i=0;i<size;i++) 
		printf("%d ", DataSet2[i]);

	return 0;
}
