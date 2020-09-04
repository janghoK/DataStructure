#include "BubbleSort.hpp"

void BubbleSort::sort(int *arr, int size) {
	int temp;

	for(int i=0;i<size-1;i++) {
		for(int k=i;k<size-i-1;k++) {
			if(arr[k] > arr[k+1]) {
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
			}
		}
	}
}
