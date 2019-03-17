/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};


struct node * removeEveryKthNode(struct node *head, int K) {
	int currentK = 2;
	struct node *temp=head,*listCurrent=head,*previousLink=head;

	if (head == NULL||K<=0)
		return NULL;
	

	if (K == 1)
	{
		while (head != NULL)
		{ 
			temp = head;
			head = head->next;
			free(temp);
		}
		return NULL;
	}


	listCurrent = head->next;
	previousLink = head;
	while (listCurrent != NULL)
	{    
		if (currentK % K== 0)
		{
			previousLink->next = listCurrent->next;
			free(listCurrent);
			listCurrent = previousLink->next;
			currentK++;
			continue;
		}
		currentK++;
		previousLink = listCurrent;
		listCurrent = listCurrent->next;
	}

	return head;
}