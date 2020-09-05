#include "SOSequentialSearch.hpp"

int main(void) {
	SOSequentialSearch search;
	Node *head = NULL;

	search.AppendNode(&head, search.CreateNode(10));
	search.AppendNode(&head, search.CreateNode(31));
	search.AppendNode(&head, search.CreateNode(22));
	search.AppendNode(&head, search.CreateNode(1));
	search.AppendNode(&head, search.CreateNode(9));
	search.AppendNode(&head, search.CreateNode(50));
	search.AppendNode(&head, search.CreateNode(19));

	search.PrintNode(head);


	Node *temp1 = search.MoveToFront(&head, 9);
	search.PrintNode(head);
	temp1 = search.MoveToFront(&head, 19);
	search.PrintNode(head);
	temp1 = search.MoveToFront(&head, 50);
	search.PrintNode(head);
	temp1 = search.MoveToFront(&head, 50);
	search.PrintNode(head);
	temp1 = search.MoveToFront(&head, 8);
	search.PrintNode(head);

	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 1);
	search.PrintNode(head);
	temp1 = search.Transpose(&head, 8);
	search.PrintNode(head);

	search.DestroyList(head);
	return 0;
}
