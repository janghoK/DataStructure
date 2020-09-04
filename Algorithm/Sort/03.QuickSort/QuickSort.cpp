#include "QuickSort.hpp"

int QuickSort::compare(const void *_a, const void *_b) {
	int *a = (int*)_a;
	int *b = (int*)_b;

	return (*a - *b);
}

void QuickSort::sort(int *arr, int left, int right) {
	if(left >= right) return;
	int first = left;
	int last = right;
	int pivot = arr[first];
	int temp;
	++left;

	while( left <= right) {
		while(arr[left] <= pivot && left < right) ++left;
		while(arr[right] > pivot && left <= right) --right;
		if(left < right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		} else {
			temp = arr[first];
			arr[first] = arr[right];
			arr[right] = temp;
			break;
		}
	}

	sort(arr, first, right-1);
	sort(arr, right + 1, last);
}
