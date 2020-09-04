#include <stdio.h>
#include <stdlib.h>

class QuickSort {
	public:
		static int compare(const void *_a, const void *_b);
		void sort(int *arr, int left, int right);
};
