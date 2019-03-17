/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}



void print2DUtil(struct node *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += 10;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = 10; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child
	print2DUtil(root->left, space);
}


void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
int main(){

	//Use it for testing ,Creating BST etc


	/*struct node *root = NULL;
	int nums[10] = { 5, 2, 10, 7, 12 };
	int elements = 5;
	for (int i = 0; i < elements; i++){
		root = add_node_spec(root, nums[i]);
	}

	int ans[3][5] = {
		{ 2, 5, 7, 10, 12 },
		{ 5, 2, 10, 7, 12 },
		{ 2, 7, 12, 10, 5 }
	};
	int results[3][5];
	int temp_inorder[5];
	
	print2DUtil(root, 0);
	
	printf("\n--------------------------------------------------------------\n");
	printf("height %d\n",get_height(root));
	inorder(root, results[0]);
	printf("\n\n");
	preorder(root, results[1]);
	printf("\n\n");
	postorder(root, results[2]);
	printf("\ninordder\n");
 for (int i = 0; i < 5; i++)
		printf("%d\t", results[1][i]);

*/




	/*struct node *root = NULL;
	int nums[20] = { 10, 2, 1, 15, 25, 100, 300 };

	for (int i = 0; i < 7; i++){
		root = add_node_spec(root, nums[i]);
	}


	int h = get_height(root);
	int ls = get_left_subtree_sum(root);
	int rs = get_right_subtree_sum(root);
	int ans[3] = { 5, 3, 440 };
	int actualans[3] = { h, ls, rs };*/

	//array to b bst---------------------------------------------------

	//int arr[10] = { -123, 12, 120, 455, 1160, 2100, 4545, 12124, 12344 };
	//struct node *root1,*root = NULL;
	//root = convert_array_to_bst(arr, 8);
	//int check = isBalanced(root);
	//int c2 = 0, c3 = 0;
	//int i = 0;
	//int len = 9;


	//print2DUtil(root, 0);

	//printf("\n--------------------------------------------------------------\n");
	//printf("height %d\n", get_height(root));
	//printf("\n\n");
	//printf("\n--------------------------------------------------------------\n");
	//printf("ls =%d\nrs=%d\n", ls, rs);
	//root1 = sortedArrayToBST(arr, 0, len-1);
	//print2DUtil(root1, 0);

	//printf("\n--------------------------------------------------------------\n");




	//bst rows---------------------------------------------------------------------------------------


	/*struct node *root = NULL;
	int nums[10] = { 10, 5, 12, 12, 15 };

	for (int i = 0; i < 3; i++){
		root = add_node_spec(root, nums[i]);
	}
	printf("\n--------------------------------------------------------------\n");

	print2DUtil(root, 0);

	int *arr = BSTRighttoLeftRows(root);
	int ans[5] = { 10, 12, 5 };
	int len = 3;

	printf("\n--------------------------------------------------------------\n");

	for (int i = 0; i < len; i++){
		printf("%d\t", arr[i]);


	}
*/
//struct node *root = NULL;
//int nums[20] = { 50, 25, 75, 15, 35, 90, 5, 17, 45, 120, 1, 2, 19, 39, 49, 100 };
//
//for (int i = 0; i < 16; i++){
//	root = add_node_spec(root, nums[i]);
//}
//struct node *swaplist[2];
//int originaldata[2];
//swaplist[0] = root->left->right->right->left;
//swaplist[1] = root->right->right->right->left;
//originaldata[0] = swaplist[0]->data;
//originaldata[1] = swaplist[1]->data;
//
//swap_nodes(swaplist[0], swaplist[1]);
//
//print2DUtil(root,0);
//
//printf("\n--------------------------------------------------------------\n");
//fix_bst(root);
//printf("\n--------------------------------------------------------------\n");

struct node *root = NULL;
int nums[10] = { 2, 1, 3, 4, 5, 6 };

for (int i = 0; i < 6; i++){
	root = add_node_spec(root, nums[i]);
}
print2DUtil(root, 0);
printf("\n_----------------------------------------------------------------------\n");
struct node *temp = root->right->right;
int ans = 2;
int dist = get_closest_leaf_distance(root, temp);

printf("\ndistance =%d\n", dist);




	return 0;
}






