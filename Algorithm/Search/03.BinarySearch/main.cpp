#include "BinarySearch.hpp"

int main(void) {
	BinarySearch search;
	int arr[] = {1, 2, 7, 10, 15, 200, 301};
	int size = sizeof(arr) / sizeof(arr[0]);
	int result;
	
	// BinarySearch
	result = search.Search(arr, size, 10);
	printf("result = %d\n", arr[result]);
	result = search.Search(arr, size, 1);
	printf("result = %d\n", arr[result]);
	result = search.Search(arr, size, 301);
	printf("result = %d\n", arr[result]);
	result = search.Search(arr, size, 3);
	if(result < 0) printf("NULL\n");

	// BinarySearch (Stadard Library)
	int target = 10;
	int *result2 = (int*)bsearch(&target, arr, size, sizeof(int), search.Compare);
	printf("result = %d\n", *result2);
	
	return 0;
}
