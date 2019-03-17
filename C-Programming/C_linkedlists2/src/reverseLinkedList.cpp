/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * recursionRevList(struct node *head)
{
	if (head->next == NULL)
		return head;

	//link last returned heads next to present head
	recursionRevList(head->next)->next = head;

	return head;
}


struct node * reverseLinkedList(struct node *head) {

	if (head == NULL)
		return NULL;

	struct node *templast = head,*listCurrent=head,*lastnode,*reverseListHead;
	//pointing last node in the list as head node in reversed list
	while (templast->next!=NULL)
	{
		templast = templast->next;
	}
	reverseListHead = templast;
	//recursive function returns last node after reversing
	lastnode = recursionRevList(head);
	//make its next as null
	lastnode->next = NULL;


	/*while (reverseListHead != NULL)
	{
		printf("%d\n", reverseListHead->num);
		reverseListHead = reverseListHead->next;
	}*/

	head = reverseListHead;
	return head;
}
