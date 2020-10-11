#include <stdio.h>
#include <stdlib.h>

class Node {
	public:
		int priority;
		const void *data;
};

class HPriorityQueue {
	private:
		Node *nodes;
		int capacity;
		int usedSize;

	public:
		HPriorityQueue(int initialSize) {
			capacity = initialSize;
			usedSize = 0;
			nodes = (Node*)malloc(sizeof(Node) * capacity);
		};
		void DestroyQueue();
		void Enqueue(int priority, const void *newData);
		void Dequeue();
		int GetChild(int index, char dir);
		int GetParent(int index);
		void SwapNodes(int current, int parent);
		void PrintQueue();
};
