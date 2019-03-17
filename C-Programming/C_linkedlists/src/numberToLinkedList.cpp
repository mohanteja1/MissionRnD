/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

int findNoDigits(int num)
{
	int i = 0;
	if (num == 0)
		return 1;

	while (num)
	{
		i++;
		num /= 10;
	}
	return i;
}

int power(int base, int pow)
{
	int result = 1;
	for (int i = 0; i < pow; i++)
	{
	   result *= base;
	}
	return result;
}
struct node * numberToLinkedList(int N) {

	if (N < 0)
		N *= -1;



	int lenthOfNum = findNoDigits(N);
	int digit;
	int k;
	//printf("digit=%d\n", lenthOfNum);
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *nextnode,*link;
	 nextnode=head;

	while (lenthOfNum)
	{
		//extract digit

		k = (power(10, lenthOfNum - 1));

		digit = N / k;

		N = N - (digit*k);
       
	  
		
		
	

		//new link

	     link=(struct node *)malloc(sizeof(struct node));

	//insert data

         link->num = digit;

		//connect link
		
       
		nextnode->next = link;

		nextnode = nextnode->next;

		lenthOfNum--;

	}
	nextnode->next = NULL;
	head = head->next;


	/*while (head != NULL)
	{
		printf("%d\n", head->num);
		head=head->next;
	}*/

	return head;
}