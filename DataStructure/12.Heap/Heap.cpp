#include "Heap.hpp"

void Heap::DestroyHeap() {
	free(nodes);
}

void Heap::InsertHeap(int newData) {
	if(usedSize == capacity) {
		capacity *= 2;
		nodes = (Node*)realloc(nodes, sizeof(Node) * capacity);
	}

	nodes[usedSize].data = newData;

	for(int i=usedSize;i>=0;i--) {
		if(nodes[i].data < nodes[GetParent(i)].data) {
			SwapNodes(i, GetParent(i));
		}
	}

	usedSize++;
}

void Heap::DeleteMin() {
	usedSize--;
	SwapNodes(0, usedSize);

	int parent = 0;
	int left = GetChild(0, 'l');
	int right = GetChild(0, 'r');
	while(1) {
		int select = 0;
		if(left >= usedSize) break;

		if(right >= usedSize) select = left;
		else {
			if(nodes[left].data > nodes[right].data) select = right;
			else select = left;
		}

		if(nodes[select].data < nodes[parent].data) {
			SwapNodes(parent, select);
			parent = select;
		} else break;

		left = GetChild(parent, 'l');
		right = GetChild(parent, 'r');
	}

	if(usedSize < (capacity/2)) {
		capacity /= 2;
		nodes = (Node*)realloc(nodes, sizeof(Node) * capacity);
	}
}

int Heap::GetChild(int index, char dir) {
	return (dir == 'l' ? 2*index+1 : 2*index+2);
}

int Heap::GetParent(int index) {
	return (index-1)/2;
}

void Heap::SwapNodes(int current, int parent) {
	Node temp = nodes[current];
	nodes[current] = nodes[parent];
	nodes[parent] = temp;
}

void Heap::PrintHeap() {
	for(int i=0;i<usedSize;i++) printf("%d ", nodes[i].data);
	printf("\n");
}
