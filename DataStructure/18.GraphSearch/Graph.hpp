#ifndef GRAPH_HPP
#define GRAPH_HPP

#define VISITED 0
#define NOTVISITED 1
#include <iostream>
#include <stdlib.h>

class Edge;
class Vertex {
	public:
		int data;
		int visited;
		int index;

		Vertex *next;
		Edge *list;
};

class Edge {
	public:
		int weight;

		Edge *next;
		Vertex *from;
		Vertex *target;
};

class Graph {
	private:
		Vertex *vertices;
		int vertexCount;
	
	public:
		Graph() {
			vertices = NULL;
			vertexCount = 0;
		};
		void DestroyGraph();
		Vertex *CreateVertex(int data);
		void DestroyVertex(Vertex *v);
		Edge *CreateEdge(Vertex *from, Vertex *target, int weight);
		void DestroyEdge(Edge *e);
		void AddVertex(Vertex *v);
		void AddEdge(Vertex *v, Edge *e);
		void PrintGraph();
		Vertex *GetVertices();
};

#endif
