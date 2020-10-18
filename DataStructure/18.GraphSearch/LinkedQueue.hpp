#include "Graph.hpp"

class QNode {
	public:
		Vertex *data;
		QNode *next;
};

class LinkedQueue {
	private:
		QNode *queue;

	public:
		LinkedQueue() {queue = NULL;}
		QNode *CreateNode(Vertex *v);
		void DestroyNode(QNode *node);
		void DestroyQueue();
		void Enqueue(QNode *node);
		QNode *Dequeue();
		int isEmpty();
		void PrintQueue();
};
