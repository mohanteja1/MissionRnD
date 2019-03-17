/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};


/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

	int onescount = 0, zeroscount = 0;

	struct node *temp = *head;
	while (temp != NULL)
	{
		if (temp->data == 1)onescount++;
		if (temp->data == 0)zeroscount++;
		temp = temp->next;

	}
	temp = *head;
	while (zeroscount > 0)
	{
		temp->data = 0;
		temp = temp->next;
		zeroscount--;
	}
	while (onescount > 0)
	{
		temp->data = 1;
		temp = temp->next;
		onescount--;
	}
	while (temp != NULL)
	{
		temp->data = 2;
		temp = temp->next;
	}
	
	return;


}

/*
This is the actual function. You are supposed to change only the links.
*/

void sll_012_sort(struct node **head){

	int i = 0, j = 0;
	struct node *listCurrent, *currentZeroPointer, *previousLink;
	listCurrent = *head;
	currentZeroPointer = (*head);      //current zero one insertion pointer
	int flag1 = 0, flag = 1;
	previousLink = *head;

	



	//sort zeros -----------------------0000000000000000000---------------------
	while (listCurrent->next != NULL)
	{


		if (listCurrent->data == 0)
		{
			if (flag)
			{
				if (i == 0)//if zero found at head node
				{
					while (listCurrent->data == 0)
					{
						currentZeroPointer = listCurrent;
						listCurrent = listCurrent->next;
						i++;
						if (listCurrent == NULL)
							return;
						
					}


					previousLink = currentZeroPointer;
					flag = 0;
					continue;
				}
				//insert at head
				//delink and join next node
				previousLink->next = previousLink->next->next;
				listCurrent->next = *head;
				*head = listCurrent;
				currentZeroPointer = *head;
				listCurrent = previousLink;
				flag = 0;

			}
			else
			{

				previousLink->next = previousLink->next->next;
				listCurrent->next = currentZeroPointer->next;
				currentZeroPointer->next = listCurrent;
				currentZeroPointer = currentZeroPointer->next;
				listCurrent = previousLink;

			}
		}
		previousLink = listCurrent;
		listCurrent = listCurrent->next;
		i++;
	}


	////last zero patch
	if (listCurrent->data == 0)
	{
		if (flag)
		{
			previousLink->next = previousLink->next->next;
			listCurrent->next = *head;
			*head = listCurrent;
			currentZeroPointer = *head;
			listCurrent = previousLink;
			flag = 0;

		}
		else
		{
			previousLink->next = previousLink->next->next;
			listCurrent->next = currentZeroPointer->next;
			currentZeroPointer->next = listCurrent;
			currentZeroPointer = currentZeroPointer->next;
		}
	}






	//sort one nodes-----------------------111111111111111111111111111-----------



          //if zeros exist
	i = 0;
	listCurrent = currentZeroPointer;
	previousLink = currentZeroPointer;

	if (!flag){      
		while (listCurrent->next != NULL)
		{
			

			if (listCurrent->data == 1)
			{
				previousLink->next = listCurrent->next;
				listCurrent->next = currentZeroPointer->next;
				currentZeroPointer->next = listCurrent;
				currentZeroPointer = currentZeroPointer->next;

			}


			previousLink = listCurrent;
			listCurrent = listCurrent->next;
			i++;

			
		}


		//last one patch

		if (listCurrent->data == 1)
		{
				previousLink->next = previousLink->next->next;
				listCurrent->next = currentZeroPointer->next;
				currentZeroPointer->next = listCurrent;
				currentZeroPointer = currentZeroPointer->next;
			
		}


	}












//if zeros dont exist


	listCurrent = *head;
	currentZeroPointer = *head;
	if (flag)     
	{


		while (listCurrent->next != NULL)
		{


			if (listCurrent->data == 1)
			{
				

				if (flag)
				{
				

					if (i == 0)    //if one found at head node
					{


						while (listCurrent->data == 1)
						{
							currentZeroPointer = listCurrent;
							listCurrent = listCurrent->next;
							i++;
							if (listCurrent == NULL)
								return;
			
						}


						previousLink = currentZeroPointer;
						flag = 0;
						continue;
					}
					//insert at head
					//delink and join next node
					previousLink->next = previousLink->next->next;
					listCurrent->next = *head;
					*head = listCurrent;
					currentZeroPointer = *head;
					listCurrent = previousLink;
					flag = 0;

				}
				else
				{

					previousLink->next = previousLink->next->next;
					listCurrent->next = currentZeroPointer->next;
					currentZeroPointer->next = listCurrent;
					currentZeroPointer = currentZeroPointer->next;
					listCurrent = previousLink;

				}
			}
			previousLink = listCurrent;
			listCurrent = listCurrent->next;
			i++;
		}






		//last one patch
		if (listCurrent->data == 1)
		{
			if (flag)
			{
				previousLink->next = previousLink->next->next;

				listCurrent->next = *head;
				*head = listCurrent;

				currentZeroPointer = *head;

				listCurrent = previousLink;
				flag = 0;
			}
			else
			{
				previousLink->next = previousLink->next->next;

				listCurrent->next = currentZeroPointer->next;
				currentZeroPointer->next = listCurrent;
				currentZeroPointer = listCurrent;
				listCurrent = previousLink;
			}

		}
		previousLink = listCurrent;
		listCurrent = listCurrent->next;


	}

	return;
}

