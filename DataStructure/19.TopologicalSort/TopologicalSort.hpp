#include "Graph.hpp"
#include "LinkedList.hpp"

#ifndef TOPOLOGICALSORT_HPP
#define TOPOLOGICALSORT_HPP

class Sort {
	private:
		LinkedList list;

	public:
		void TopologicalSort(Vertex *v);
		void DFS(Vertex *v);
		void DestroyList();
		Node *GetList();
		void PrintList();
};

#endif
