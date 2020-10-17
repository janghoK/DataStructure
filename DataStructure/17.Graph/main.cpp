#include "Graph.hpp"

int main(void) {
	Graph g;
	Vertex *V1 = g.CreateVertex('1');
	Vertex *V2 = g.CreateVertex('2');
	Vertex *V3 = g.CreateVertex('3');
	Vertex *V4 = g.CreateVertex('4');
	Vertex *V5 = g.CreateVertex('5');

	g.AddVertex(V1);
	g.AddVertex(V2);
	g.AddVertex(V3);
	g.AddVertex(V4);
	g.AddVertex(V5);

	g.AddEdge(V1, g.CreateEdge(V1, V2, 0));
	g.AddEdge(V1, g.CreateEdge(V1, V3, 0));
	g.AddEdge(V1, g.CreateEdge(V1, V4, 0));
	g.AddEdge(V1, g.CreateEdge(V1, V5, 0));

	g.AddEdge(V2, g.CreateEdge(V2, V1, 0));
	g.AddEdge(V2, g.CreateEdge(V2, V3, 0));
	g.AddEdge(V2, g.CreateEdge(V2, V5, 0));

	g.AddEdge(V3, g.CreateEdge(V3, V1, 0));
	g.AddEdge(V3, g.CreateEdge(V3, V2, 0));

	g.AddEdge(V4, g.CreateEdge(V4, V1, 0));
	g.AddEdge(V4, g.CreateEdge(V4, V5, 0));

	g.AddEdge(V5, g.CreateEdge(V5, V1, 0));
	g.AddEdge(V5, g.CreateEdge(V5, V2, 0));
	g.AddEdge(V5, g.CreateEdge(V5, V4, 0));

	g.PrintGraph();

	g.DestroyGraph();

	return 0;
}
