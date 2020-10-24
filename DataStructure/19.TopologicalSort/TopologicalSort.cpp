#include "TopologicalSort.hpp"

void Sort::TopologicalSort(Vertex *v) {
	while(v != NULL && v->visited == NOTVISITED) {
		DFS(v);
		v = v->next;
	}
}

void Sort::DFS(Vertex *v) {
	Node *head = NULL;
	Edge *e = NULL;

	v->visited = VISITED;
	e = v->list;

	while(e != NULL) {
		if(e->target != NULL && e->target->visited == NOTVISITED) DFS(e->target);
		e = e->next;
	}

	std::cout << v->data << std::endl;

	head = list.CreateNode(v);
	list.InsertHead(head);
}

void Sort::DestroyList() {
	list.DestroyList();
}

Node *Sort::GetList() {
	return list.GetList();
}

void Sort::PrintList() {
	list.PrintList();
}
