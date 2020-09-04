#include "InsertionSort.hpp"

void InsertionSort::sort(int *arr, int size) {
	int temp = 0;
	for(int i=1;i<size;i++) {
		if(arr[i-1] <= arr[i]) continue;
		temp = arr[i];
		
		for(int k=0;k<i;k++) {
			if(arr[k] > temp) {
				std::memmove(&arr[k+1], &arr[k], sizeof(arr[0])*(i-k));
				arr[k] = temp;
				break;
			}
		}
	}
}
