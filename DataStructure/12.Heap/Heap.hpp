#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node {
	public:
		int data;
};

class Heap {
	private:
		Node *nodes;
		int capacity;
		int usedSize;

	public:
		Heap(int initialSize) {
			capacity = initialSize;
			usedSize = 0;
			nodes = (Node*)malloc(sizeof(Node) * capacity);
		};
		void DestroyHeap();
		void InsertHeap(int newData);	
		void DeleteMin();
		int GetChild(int index, char dir);
		int GetParent(int index);
		void SwapNodes(int current, int parent);
		void PrintHeap();
};
