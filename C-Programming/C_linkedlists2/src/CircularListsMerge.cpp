/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
  
int merge_circularlists(struct node **head1, struct node **head2){

	if (*head1 == NULL || *head2 == NULL)
		return -1;


	struct node *list1Current = *head1, *list2Current = *head2,*list2Previous=*head1,*list1Previous=*head2,*tempNode,*list1End,*list2End;
	int listendflag = 1;
	int nodeCount = 0;
	  //make given lists into non circular
	    tempNode = *head1;
		//printf("list1 nodes -----------\n");
		while (tempNode->next!=*head1)
		{   
			//printf("%d\n", tempNode->data);
			nodeCount++;
			tempNode = tempNode->next;
			
		}
		nodeCount++;
		tempNode->next = NULL;
		list1End = tempNode;

		tempNode = *head2;
		//printf("list2 nodes -----------\n");
		while (tempNode->next != *head2)
		{
			//printf("%d\n", tempNode->data);
			nodeCount++;
			tempNode = tempNode->next;
		}
		nodeCount++;
		tempNode->next = NULL;
		list2End = tempNode;


		
	while (list2Current != NULL)   //insert nodes of list 2 into list1 
	{

		if (list1Current == NULL)  //if list 1 ends attach list2 remaining and point list2end to head1
		{
			list1Previous->next = list2Current;
			list2End->next = *head1;
			listendflag = 0;
			break;
		}


		if (list1Current->data >= list2Current->data)//compare node numbers
		{

			if (list1Current == *head1)//if list2 's head num is smaller than list1's then make it as head node to list1
			{
				tempNode = list2Current;
				list2Current = list2Current->next;
				tempNode->next = *head1;
				*head1 = tempNode;
				//soft reset of loop again
				list2Previous = *head1;
				list1Current = *head1;

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

	if (listendflag)
		list1End->next = *head1;


	//result
	/*tempNode = *head1;
	printf("final nodes -----------\n");
	while (tempNode->next != *head1)
	{
		printf("%d\n", tempNode->data);
		tempNode = tempNode->next;

	}
	printf("%d\n", tempNode->data);
	printf("count=%d\n", nodeCount);*/

	return nodeCount;
}