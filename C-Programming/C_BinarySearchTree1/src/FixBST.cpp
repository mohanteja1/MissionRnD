/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int bstNodeCount(struct node *root)
{

	if (root == NULL)
		return 0;

	return 1 + bstNodeCount(root->left) + bstNodeCount(root->right);

}
int inorderRecStruct(struct node *root, struct node **arr, int *i)
{
	if (root == NULL)
		return 1;

	inorderRecStruct(root->left, arr, i);


	arr[(*i)++] = root;
	inorderRecStruct(root->right, arr, i);
}






void fix_bst(struct node *root){

	if (root == NULL)
		return;


	int length = bstNodeCount(root);
    
	struct node **arr = (struct node **)malloc(sizeof(struct node*)*length);
	int i = 0;
	inorderRecStruct(root,arr,&i);


	int j = 0;
	int fix1, fix2,flag=1;
	while (j<length-1)
	{
		//printf("%d\n", arr[j]->data);
		if (arr[j]->data > arr[j + 1]->data)
		{
			if(flag)fix1 = j;
			flag = 0;
			fix2 = j+1;

		}

		j++;
	}
	
	//printf("\n%d\n", arr[fix1]->data);
	//printf("%d\n", arr[fix2]->data);

	int temp = arr[fix1]->data;
	arr[fix1]->data = arr[fix2]->data;
	arr[fix2]->data = temp;


}
