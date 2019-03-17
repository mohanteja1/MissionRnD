/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {

	struct node *listCurrent = head, *listPrevious = head, *tempCurrent = head, *tempPrevious = head, *temp = head, *minNumNode = head, *minNumPrevious = head,*tempprint=head;
	int flag=0;
	//null check
	if (head == NULL)
		return NULL;
	



	//headnode

	temp = head->next;
	minNumNode = head->next;
	while (temp != NULL)
	{
		
		if (temp->num < minNumNode->num)
		{
			flag = 1;  //flag to check if head is already minimum
			listPrevious = tempPrevious;
			minNumNode = temp;

		}
		tempPrevious = temp;
		temp = temp->next;
	}


	 //make minimumnode head;

	if (flag){
		listPrevious->next = listPrevious->next->next;
		minNumNode->next = head;
		head = minNumNode;
	}
	
	
	//sorting after minimum head

	listCurrent = head->next;
	listPrevious = head;
	int minNodesCount = 0;
	tempprint = head;
	while (listCurrent != NULL)
	{

		minNodesCount = 1; //set minimum nodes less than current node to one so as to enter loop once
		
		while (minNodesCount){
			tempCurrent = listCurrent->next; //compare current node from its next node
			tempPrevious = listCurrent;
			minNumNode = listCurrent;  //initialize minimum node with current node
		
			minNodesCount = 0;  //make minimum nodecount to zero after entering loop
		
			while (tempCurrent != NULL)
			{
			
				if (tempCurrent->num <= listCurrent->num)
				{
						
					minNodesCount++;   //increament count if node less than the current node found
					if (tempCurrent->num <= minNumNode->num) //point minimum node in them
					{
						minNumPrevious = tempPrevious;
						minNumNode = tempCurrent;

				    }
					
				}
				
				tempPrevious = tempCurrent;
				tempCurrent = tempCurrent->next;

			}
	
			
			if (minNodesCount == 0) //if no nodes less than current node found break
				break;

			//insert minimum node before current node
			minNumPrevious->next = minNumPrevious->next->next;
			minNumNode->next = listCurrent;
			listPrevious->next = minNumNode;
			listPrevious = listPrevious->next;
			minNodesCount--;  //continue till all minimum nodes inserted
		
		}
		//continue till all nodes
		listPrevious = listCurrent;
		listCurrent = listCurrent->next;
	}
	   
	     
	
	
	 

	return head;
}