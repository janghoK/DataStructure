#include "Heap.hpp"

int main(void) {
	Heap heap(5);

	heap.InsertHeap(10);
	heap.InsertHeap(31);
	heap.InsertHeap(22);
	heap.InsertHeap(132);
	heap.InsertHeap(67);
	heap.InsertHeap(92);
	heap.InsertHeap(5);
	heap.InsertHeap(1);
	heap.InsertHeap(7);
	heap.InsertHeap(45);
	heap.PrintHeap();

	heap.DeleteMin();
	heap.PrintHeap();

	heap.DeleteMin();
	heap.PrintHeap();

	heap.DeleteMin();
	heap.PrintHeap();

	heap.DeleteMin();
	heap.PrintHeap();

	heap.DeleteMin();
	heap.PrintHeap();

	heap.DeleteMin();
	heap.PrintHeap();

	heap.DestroyHeap();

	return 0;
}
