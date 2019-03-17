/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
//for queue ------------------------------------------------------------------
struct listNode{
	struct node *bstpointer;
	struct listNode *nextpointer=NULL;
	int leftoRright = 0;
};

struct listNode * dequeu(struct listNode *head)
{
	struct listNode *freee = head;
	head = head->nextpointer;
	free(freee);
	return head;
}
struct listNode * enqueue(struct listNode *tail, struct node *bstNode)
{ 
	if (tail == NULL)
	{
		tail = (struct listNode *)malloc(sizeof(struct listNode) * 1);
		tail->bstpointer = bstNode;
		return tail;
	}

	tail->nextpointer = (struct listNode *)malloc(sizeof(struct listNode) * 1);
	tail = tail->nextpointer;
	tail->bstpointer = bstNode;
	return tail;
}
//---------------------------------------------------------------------------------------


//bst no of nodes 
int bstNodes(struct node *root)
{
	
	if (root == NULL)
		return 0;

	return 1 + bstNodes(root->left) + bstNodes(root->right);

}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;


	int noOfNodes = bstNodes(root);
	int *arr = (int *)calloc(noOfNodes,sizeof(int));
	int arrIndex=0;
	struct listNode *current ,*head,*tail=NULL;
     
	head = enqueue(tail, root);
	tail = head;
	current = head;


	while (arrIndex < noOfNodes)
	{
		arr[arrIndex++] = current->bstpointer->data;

		if (current->bstpointer->right!=NULL)
			tail = enqueue(tail, current->bstpointer->right);

		if (current->bstpointer->left != NULL)
			tail = enqueue(tail, current->bstpointer->left);
	
		current = dequeu(current);
        

	}
	


    return arr;
}
