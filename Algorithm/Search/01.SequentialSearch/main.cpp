#include "SequentialSearch.hpp"

int main(void) {
	SequentialSearch search;
	Node *head = NULL;
		
	search.InsertNode(&head, search.CreateNode(1));
	search.InsertNode(&head, search.CreateNode(132));
	search.InsertNode(&head, search.CreateNode(10));
	search.InsertNode(&head, search.CreateNode(7));
	search.InsertNode(&head, search.CreateNode(210));

	search.PrintNode(head);

	Node *temp = search.SearchNode(head, 7);
	printf("%d\n", temp->Data);

	temp = search.SearchNode(head, 2);
	if(temp == NULL) printf("NULL\n");

	search.DestroyList(head);
	return 0;
}
