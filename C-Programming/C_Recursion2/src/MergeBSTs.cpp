/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

void add_node(struct BstNode *main,struct BstNode *node,int *inserted)
{

	//if duplicate present return
	if (main->data == node->data)
		return;
	//inserted variable only for standard


	//search for suitable place 
	if (node->data > main->data && !(*inserted))
	{
		if (main->right == NULL)
		{
			main->right = node;
			*inserted = 1;
			return;
		}
		add_node(main->right, node, inserted);

	}

	if (node->data < main->data && !(*inserted))
	{
		if (main->left == NULL)
		{
			main->left = node;
			*inserted = 1;
			return;
		}


		add_node(main->left, node, inserted);

	}
}

void postorderRec(struct BstNode *root2,struct BstNode *mainRoot)
{
	if (root2 == NULL)
		return;

	postorderRec(root2->left, mainRoot);
	postorderRec(root2->right, mainRoot);
	
	int inserted = 0;
	root2->left = NULL;
	root2->right = NULL;
	add_node(mainRoot, root2, &inserted);
	
	return;
}





void merge_two_bst(struct BstNode **root1, struct BstNode *root2) {
	
	if (*root1 == NULL&&root2 != NULL)
	{
		*root1 = root2;
		return;
	}

	if (root1 == NULL || root2 == NULL)
		return;



	BstNode *mainroot = *root1;

	//postorder since it give leafnodes first
	postorderRec(root2, mainroot);


}