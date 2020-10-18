#include "GraphSearch.hpp"

void Search::DFS(Vertex *v) {
	Edge *e = NULL;

	std::cout << (char)v->data << " ";
	v->visited = VISITED;

	e = v->list;

	while(e != NULL) {
		if(e->target != NULL && e->target->visited == NOTVISITED) DFS(e->target);
		e = e->next;
	}
}

void Search::BFS(Vertex *v) {
	LinkedQueue queue;
	Edge *e = NULL;

	std::cout << (char)v->data << " ";
	v->visited = VISITED;

	queue.Enqueue(queue.CreateNode(v));

	while(!queue.isEmpty()) {
		QNode *popped = queue.Dequeue();
		v = popped->data;
		e = v->list;

		while(e != NULL) {
			v = e->target;
			if( v != NULL && v->visited == NOTVISITED) {
				std::cout << (char)v->data << " ";
				v->visited = VISITED;
				queue.Enqueue(queue.CreateNode(v));
			}
			e = e->next;
		}
		queue.DestroyNode(popped);
	}
	queue.DestroyQueue();
}
