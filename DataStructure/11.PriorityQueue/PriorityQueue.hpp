#include <stdio.h>
#include <stdlib.h>

class Node{
	public:
		int Data;
		Node *nextNode;
};

class PriorityQueue{
	private:
		Node *front = NULL;
		
	public:
		Node *CreateNode(int newData);
		void InsertNode(Node *newNode);
		Node *RemoveNode(int data);
		void DestroyNode(Node *node);
		void DestroyQueue();
		void Pop();
		void PrintQueue();

};
