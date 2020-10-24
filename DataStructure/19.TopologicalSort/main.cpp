#include "Graph.hpp"
#include "TopologicalSort.hpp"

int main(void) {
	Graph g;

	Vertex *A = g.CreateVertex('A');
	Vertex *B = g.CreateVertex('B');
	Vertex *C = g.CreateVertex('C');
	Vertex *D = g.CreateVertex('D');
	Vertex *E = g.CreateVertex('E');
	Vertex *F = g.CreateVertex('F');
	Vertex *G = g.CreateVertex('G');
	Vertex *H = g.CreateVertex('H');

	g.AddVertex(A);
	g.AddVertex(B);
	g.AddVertex(C);
	g.AddVertex(D);
	g.AddVertex(E);
	g.AddVertex(F);
	g.AddVertex(G);
	g.AddVertex(H);

	g.AddEdge(A, g.CreateEdge(A, C, 0));
	g.AddEdge(A, g.CreateEdge(A, D, 0));

	g.AddEdge(B, g.CreateEdge(B, C, 0));
	g.AddEdge(B, g.CreateEdge(B, E, 0));

	g.AddEdge(C, g.CreateEdge(C, F, 0));

	g.AddEdge(D, g.CreateEdge(D, F, 0));
	g.AddEdge(D, g.CreateEdge(D, G, 0));

	g.AddEdge(E, g.CreateEdge(E, G, 0));

	g.AddEdge(F, g.CreateEdge(F, H, 0));

	g.AddEdge(G, g.CreateEdge(G, H, 0));

	Sort s;
	s.TopologicalSort(g.GetVertices());

	s.PrintList();

	s.DestroyList();
	g.DestroyGraph();

	return 0;
}
