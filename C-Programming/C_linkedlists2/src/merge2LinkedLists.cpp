/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	//NULL check
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;


	struct node *list1Current = head1, *list2Current = head2, *tempprint=head1,*list1Previous = head1, *list2Previous = head2,*tempNode;

	while (list2Current!=NULL)   //insert nodes of list 2 into list1 
	{

		if (list1Current == NULL)  //if list 1 ends attach list2 remaining
		{
			list1Previous->next = list2Current;
			break;
		}


		if (list1Current->num >= list2Current->num)//compare node numbers
		{

			if (list1Current == head1)//if list2 's head num is smaller than list1's then make it as head node to list1
			{
				tempNode = list2Current;
				list2Current = list2Current->next;
				tempNode->next = head1;
				head1 = tempNode;
				//soft reset of loop again
				list2Previous = head1;
				list1Current = head1;
				
			}
			else //insert list2 node into list1  
			{

				tempNode = list2Current;
				list2Current = list2Current->next;
				tempNode->next = list1Current;
				list1Previous->next = tempNode;
				list1Previous = list1Previous->next;
			}

		}
		else //if l2 node is not small increment list1 current pointer
		{
			
			list1Previous = list1Current;
			list1Current = list1Current->next;
			
		}
	}
	

	




	return head1;
}
