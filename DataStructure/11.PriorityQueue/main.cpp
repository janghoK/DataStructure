#include "PriorityQueue.hpp"

int main() {
	PriorityQueue queue;

	queue.InsertNode(queue.CreateNode(2));
	queue.InsertNode(queue.CreateNode(10));
	queue.InsertNode(queue.CreateNode(22));
	queue.InsertNode(queue.CreateNode(25));
	queue.InsertNode(queue.CreateNode(31));
	queue.InsertNode(queue.CreateNode(1));
	queue.InsertNode(queue.CreateNode(2));

	queue.PrintQueue();

	queue.Pop();
	queue.PrintQueue();

	Node *temp = queue.RemoveNode(10);
	queue.DestroyNode(temp);
	queue.PrintQueue();

	temp = queue.RemoveNode(25);
	queue.DestroyNode(temp);
	queue.PrintQueue();

	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Pop();

	queue.DestroyQueue();
	return 0;
}
