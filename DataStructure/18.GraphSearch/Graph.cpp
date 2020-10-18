#include "Graph.hpp"

void Graph::DestroyGraph() {
	while(vertices != NULL) {
		Vertex *temp = vertices->next;
		DestroyVertex(vertices);
		vertices = temp;
	}
}

Vertex *Graph::CreateVertex(int data) {
	Vertex *v = (Vertex*)malloc(sizeof(Vertex));
	v->data = data;
	v->visited = NOTVISITED;
	v->index = -1;
	v->next = NULL;
	v->list = NULL;

	return v;
}

void Graph::DestroyVertex(Vertex *v) {
	while(v->list != NULL) {
		Edge *temp = v->list->next;
		DestroyEdge(v->list);
		v->list = temp;
	}
	free(v);
}

Edge *Graph::CreateEdge(Vertex *from, Vertex *target, int weight) {
	Edge *e = (Edge*)malloc(sizeof(Edge));
	e->from = from;
	e->target = target;
	e->weight = weight;
	e->next = NULL;

	return e;
}

void Graph::DestroyEdge(Edge *e) {
	free(e);
}

void Graph::AddVertex(Vertex *v) {
	Vertex *list = vertices;
	if(list == NULL) vertices = v;
	else {
		while(list->next != NULL) list = list->next;
		list->next = v;
	}
	v->index = vertexCount++;
}

void Graph::AddEdge(Vertex *v, Edge *e) {
	if(v->list == NULL) v->list = e;
	else {
		Edge *list = v->list;
		while(list->next != NULL) list = list->next;
		list->next = e;
	}
}

void Graph::PrintGraph() {
	Vertex *v = NULL;
	Edge *e = NULL;

	if((v = vertices) == NULL) return;
	while(v != NULL) {
		std::cout << (char)v->data << " : ";

		if((e = v->list) == NULL) {
			v = v->next;
			std::cout << std::endl;
			continue;
		}

		while(e != NULL) {
			std::cout << e->target->data << "[" << e->weight << "]" ;
			e = e->next;
		}
		std::cout << std::endl;

		v = v->next;
	}
	std::cout << std::endl;
}

Vertex *Graph::GetVertices() {
	return vertices;
}
