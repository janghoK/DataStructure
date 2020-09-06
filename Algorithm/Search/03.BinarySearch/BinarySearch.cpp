#include "BinarySearch.hpp"

int BinarySearch::Search(int *dataSet, int size, int target) {
	int left = 0, right = size - 1, mid;
	while(right >= left) {
		mid = (left + right) / 2;
		if(target == dataSet[mid]) return mid;
		else if(target > dataSet[mid]) left = mid+1;
		else right = mid - 1;
	}
	return -1;
}

int BinarySearch::Compare(const void *_em1, const void *_em2) {
	int *em1 = (int*)_em1;
	int *em2 = (int*)_em2;
	return (*em1 - *em2);
}
