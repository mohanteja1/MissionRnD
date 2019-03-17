/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>
#include "FunctionHeadersBST.h"
#define RIGHT 1
#define LEFT -1


struct listNode{
	struct node *bstpointer=NULL;
	struct listNode *nextpointer = NULL;
	int leftoRright = 0;
};



struct node{
  struct node * left;
  int data;
  struct node *right;
};


int find_tempNodeParents(struct node *presentNode, int data,struct listNode * listCurrent)
{
	

	if (presentNode == NULL)
		return 0;

	

    if (presentNode->data == data) return 0;

	//put parent in the list
       listCurrent = enqueue(listCurrent, presentNode);



	   if (presentNode->data > data){
		//update direction to the next node
		   listCurrent->leftoRright = -1;

          return 1 + find_tempNodeParents(presentNode->left, data, listCurrent);
	   }

	   if (presentNode->data < data){
		   //update direction to the next node
		   listCurrent->leftoRright = 1;

		   return 1 + find_tempNodeParents(presentNode->right, data, listCurrent);
	   }

	return 0;

}

int shortest_height(struct node *root){   //it returns the shortest leaf node distance below the node

	//check if leaf node
 	if (root->left == NULL && root->right==NULL)
		return 0;

	
	int count1 = 0, count2 = 0;

	if (root->left !=NULL)
	 count1 = shortest_height(root->left);

	if (root->right!=NULL)
	count2 = shortest_height(root->right);

	return 1 + max(count1, count2);

}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	//input check
	if (root == NULL || temp == NULL)
		return -1;
	
	//check shortest distance below the given temp node
	int shortLeafBelow = shortest_height(temp);

	
	struct listNode current,*head=NULL, *tail = NULL;
	//initialize list 
	head = enqueue(tail, root);
 
	//find parents and list the hierarchy
	int parentCount = find_tempNodeParents(root, temp->data,head);
      


	int minimum = shortLeafBelow;

	int tempmin=0;



	// move front dummy node which is used to initialize list
     head = head->nextpointer;
 

 
  
	while (parentCount)
	{


		//dont check distance in temp node direction		
		if (head->leftoRright == RIGHT&& head->bstpointer->left != NULL) 
		     tempmin =parentCount+1+shortest_height( head->bstpointer->left);
		else if (head->leftoRright==LEFT&&head->bstpointer->right!=NULL)
			 tempmin =parentCount + 1 + shortest_height(head->bstpointer->right);
		else
		{
			parentCount--;
			head=head->nextpointer;
			continue;
		}

		
		
		
		
	


		if (tempmin < minimum)   minimum = tempmin;
			                   
		//loop controls
		head = head->nextpointer;
		parentCount--;
	}
	

  return minimum;
}