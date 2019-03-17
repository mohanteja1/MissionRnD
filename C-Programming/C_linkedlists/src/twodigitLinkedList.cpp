/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};
int nodedata(struct twoDigitNode *node)
{
	return (node->digit1 * 10) + node->digit2;
}
int convert_sll_2digit_to_int(struct twoDigitNode *head){
	struct twoDigitNode *temp = head;
	int currentNodeData,tempOutput=0;
	while (temp != NULL)
	{
		currentNodeData = nodedata(temp);
		printf("current node number :%d\n", currentNodeData);
	    
		tempOutput *= 100;
		tempOutput += currentNodeData;
		temp = temp->next;
	}


	return tempOutput;
}
