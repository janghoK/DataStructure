#include <stdio.h>
#include <stdlib.h>

class BinarySearch {
	public:
		int Search(int *dataSet, int size, int target);
		static int Compare(const void *_em1, const void *_em2);
};
