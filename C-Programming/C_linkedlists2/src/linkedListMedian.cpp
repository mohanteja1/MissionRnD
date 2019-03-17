/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	struct node *tempHead = head,*listCurrent=head,*median=head;
	int listCount = 1,flag=0;

	if (head == NULL)
		return -1;
	if (head->next == NULL)
		return head->num;


	while (listCurrent->next != NULL)
	{
		//move median for odd value of present count
		if (listCount % 2 == 1 && flag==1) //flag for excepting 1%2 for the first time
			median = median->next;

		flag = 1;

		listCurrent = listCurrent->next;

		listCount++;
	}

	if (listCount % 2)
		return median->next->num;
	else
		return (median->num + median->next->num) / 2;

	return -1;
}
