/*
Mock Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include "FunctionHeadersRecursion2.h"
#include<stdlib.h>
struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};

struct node_dll {
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

struct node_bst {
	int data;
	struct node_bst *left;
	struct node_bst *right;
};
struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

struct node_dll *newNode_DLL_spec(int key){
	struct node_dll *temp = (struct node_dll *)malloc(sizeof(struct node_dll));
	temp->data = key;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

struct node_dll * make_dll_spec(int *arr, int len){
	struct node_dll *root = newNode_DLL_spec(arr[0]);
	struct node_dll *temp = root;
	for (int i = 1; i < len; i++){
		struct node_dll *cur = newNode_DLL_spec(arr[i]);
		temp->next = cur;
		cur->prev = temp;
		temp = temp->next;
	}
	return root;
}

struct node_bst *newNode_spec(int key)
{
	struct node_bst *temp = (struct node_bst *)malloc(sizeof(struct node_bst));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node_bst * add_node_spec(struct node_bst *root, int data){
	if (root == NULL) return newNode_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

struct node_bst * make_bst_spec(int *arr, int len){
	struct node_bst *root = NULL;
	for (int i = 0; i < len; i++){
		root = add_node_spec(root, arr[i]);
	}
	return root;
}

struct BstNode *newNode_mergeBST(int key){
	struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct BstNode * insertNode_mergeBST(struct BstNode *root, int data) {
	if (root == NULL) return newNode_mergeBST(data);
	if (data < root->data)
		root->left = insertNode_mergeBST(root->left, data);
	else if (data > root->data)
		root->right = insertNode_mergeBST(root->right, data);
	return root;
}

struct BstNode * create_BST(int *arr, int len) {
	struct BstNode *root = NULL;
	for (int i = 0; i < len; i++) {
		root = insertNode_mergeBST(root, arr[i]);
	}
	return root;
}









int main(){
	/*
		Recursion Main
	*/
//identify kid--------------------------
	//char res = identifyKid(10, 100);
	////char res = identifyKid(15441, 879875);
	//if (res == 0)
	//	printf("rey");
	//else
	//printf("\n%c", res);

//magic tool-------------------------------
	/*char pixels[][4] = {
		{ 'r', 'g', 'r', 'b' },
		{ 'g', 'r', 'r', 'b' },
		{ 'r', 'g', 'b', 'b' }
	};

	bool visited[3][4] = {
		{ false, false, false, true },
		{ false, false, false, true },
		{ false, false, true, true }
	};
	int m = 2;
	int n = 3;

	Point pivot = { 2, 3 };

	result res = select_wrapper(&pixels[0][0], m, n, pivot);*/
//newyork----------------------------------
	//int res = NewYork(10, 10, 3);


	//printf("%d", res);


//dll_bst----------------------------------

	/*int arr[5] = { 1, 2, 3, 4 };
	int bst_arr[5] = { 5, 3, 2, 1, 4 };
	int len1 = 4;
	int len2 = 5;
	struct node_dll * head = make_dll_spec(arr, len1);
	struct node_bst *root = make_bst_spec(bst_arr, len2);
	int check = is_identical(head, root);*/
	
	
	
	//bst merge------------------


	int b1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; int len1 = 10;
	int b2[] = { 11, 15, 99, 52 }; int len2 = 4;

	BstNode *Nodes[30]; int len = 0;
	BstNode *bst1 = create_BST(b1, len1);
	BstNode *bst2 = create_BST(b2, len2);
	
	
	merge_two_bst(&bst1, bst2);
	
	
	
	
	//int result = NewYork(3, 3, 2);
 	return 0;
}

