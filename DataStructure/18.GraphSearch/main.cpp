#include "Graph.hpp"
#include "GraphSearch.hpp"

int main(void) {
	int mode = 0;
	Graph g;

	Vertex *v1 = g.CreateVertex('1');
	Vertex *v2 = g.CreateVertex('2');
	Vertex *v3 = g.CreateVertex('3');
	Vertex *v4 = g.CreateVertex('4');
	Vertex *v5 = g.CreateVertex('5');
	Vertex *v6 = g.CreateVertex('6');
	Vertex *v7 = g.CreateVertex('7');

	g.AddVertex(v1);
	g.AddVertex(v2);
	g.AddVertex(v3);
	g.AddVertex(v4);
	g.AddVertex(v5);
	g.AddVertex(v6);
	g.AddVertex(v7);

	g.AddEdge(v1, g.CreateEdge(v1, v2, 0));
	g.AddEdge(v1, g.CreateEdge(v1, v3, 0));

	g.AddEdge(v2, g.CreateEdge(v2, v4, 0));
	g.AddEdge(v2, g.CreateEdge(v2, v5, 0));

	g.AddEdge(v3, g.CreateEdge(v3, v4, 0));
	g.AddEdge(v3, g.CreateEdge(v3, v6, 0));

	g.AddEdge(v4, g.CreateEdge(v4, v5, 0));
	g.AddEdge(v4, g.CreateEdge(v4, v7, 0));

	g.AddEdge(v5, g.CreateEdge(v5, v7, 0));

	g.AddEdge(v6, g.CreateEdge(v6, v7, 0));

	std::cout << "Enter Search Mode (0: DFS, 1: BFS) : ";
	std::cin >> mode;

	Search s;
	if(mode == 0) s.DFS(g.GetVertices());
	else {
		s.BFS(v1);
	}

	g.DestroyGraph();

	return 0;
}
