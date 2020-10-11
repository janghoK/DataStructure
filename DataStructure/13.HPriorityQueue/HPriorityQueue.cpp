#include "HPriorityQueue.hpp"

void HPriorityQueue::DestroyQueue() {
	free(nodes);
}

void HPriorityQueue::Enqueue(int priority, const void *newData) {
	if(usedSize == capacity) {
		if(capacity == 0) capacity = 1;
		capacity *= 2;
		nodes = (Node*)realloc(nodes, sizeof(Node) * capacity);
	}
	nodes[usedSize].priority = priority;
	nodes[usedSize].data = newData;

	for(int i=usedSize;i>=0;i--) {
		if(nodes[i].priority < nodes[GetParent(i)].priority) {
			SwapNodes(i, GetParent(i));
		}
	}

	usedSize++;
}

void HPriorityQueue::Dequeue() {
	if(usedSize == 0) {
		printf("Queue is empty\n");
		return;
	}

	SwapNodes(0, --usedSize);

	int parent = 0;
	int left = GetChild(0, 'l');
	int right = GetChild(0, 'r');
	while(1) {
		int select = 0;
		if(left >= usedSize) break;

		if(right >= usedSize) select = left;
		else select = (nodes[left].priority > nodes[right].priority ? right : left);
		
		if(nodes[select].priority < nodes[parent].priority) {
			SwapNodes(select, parent);
			parent = select;
		} else break;

		left = GetChild(parent, 'l');
		right = GetChild(parent, 'r');

		if(usedSize == capacity/2) {
			capacity /= 2;
			nodes = (Node*)realloc(nodes, sizeof(Node) * capacity);
		}
	}
}

int HPriorityQueue::GetChild(int index, char dir) {
	return (dir == 'l' ? 2*index+1 : 2*index+2);
}

int HPriorityQueue::GetParent(int index) {
	return (index-1)/2;
}

void HPriorityQueue::SwapNodes(int current, int parent) {
	Node temp = nodes[current];
	nodes[current] = nodes[parent];
	nodes[parent] = temp;
}

void HPriorityQueue::PrintQueue() {
	printf("Remaining tasks: %d\n", usedSize);
	for(int i=0;i<usedSize;i++) printf("WorkName: %s (Priority: %d)\n", nodes[i].data, nodes[i].priority);
}
