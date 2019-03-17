/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
 
int inorderRec(struct node *root, int *arr, int *i)
{
	if (root == NULL)
		return 1;
	
	inorderRec(root->left, arr, i);


	 arr[(*i)++] = root->data;
	 inorderRec(root->right, arr, i);
}


int preorderRec(struct node *root, int *arr, int *i)
{
	if (root == NULL)
		return 1;



	arr[(*i)++] = root->data;
	/*printf("lost u = %d \n", root->data);
	printf("%d\n", *i);*/
	preorderRec(root->left, arr, i);
	preorderRec(root->right, arr, i);
}

int postorderRec(struct node *root, int *arr, int *i)
{
	if (root == NULL)
		return 1;

	postorderRec(root->left, arr, i);
	postorderRec(root->right, arr, i);
	arr[(*i)++] = root->data;
	return 1;
}

void inorder(struct node *root, int *arr){
   
	if (root == NULL || arr == NULL)
		return;
	int i = 0;
	inorderRec(root, arr,&i);
	
}







void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int i = 0;
	preorderRec(root, arr, &i);
}


void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int i = 0;
	postorderRec(root, arr, &i);
}

