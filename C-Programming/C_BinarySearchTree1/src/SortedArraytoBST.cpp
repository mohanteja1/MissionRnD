/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node * newNode1(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *sortArrToBst(int arr[], int start, int end)
{
	if (start > end)
		return NULL;

	int mid = (start + end) / 2;

	struct node *root = newNode1(arr[mid]);



	root->left = sortArrToBst(arr, start, mid - 1);

	root->right = sortArrToBst(arr, mid + 1, end);

	return root;
}

struct node * convert_array_to_bst(int *arr, int len){


	if (len < 0||arr==NULL)
		return NULL;


	return sortArrToBst(arr, 0, len - 1);




	//2nd method

	//int flag=1,flag1=0;

	//
	//struct node *root = newNode1(arr[len/2]);
	//
	//printf("%d-%d- %d\n", arr[len/2],len/2,len);
	//if (len == 3)
	//{
	//	root->right = convert_array_to_bst(&arr[(len / 2) + 1], (len / 2)+1);
	//	root->left = convert_array_to_bst(&arr[0], (len / 2)+1);
	//}
	//else{
	//	root->right = convert_array_to_bst(&arr[(len / 2) + 1], (len / 2) - 1);
	//	root->left = convert_array_to_bst(&arr[0], (len / 2) - 1);
	//}

	//


	//return root;//sortArrToBst(arr,0,len-1);
}

