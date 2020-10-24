#include "Graph.hpp"

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class Node {
	public:
		Vertex *v;
		Node *nextNode;
};

class LinkedList {
	private:
		Node *list;

	public:
		LinkedList() {
			list = NULL;
		};
		Node *CreateNode(Vertex *newV);
		void DestroyNode(Node *node);
		void DestroyList();
		void InsertHead(Node *node);
		Node *GetList();
		void PrintList();
};

#endif
