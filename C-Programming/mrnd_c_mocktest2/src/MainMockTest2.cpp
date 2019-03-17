/*
Mock Test 2
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.
95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/
#define ___ '.'
#define _b_ 'b'
#define _w_ 'w'


#include <stdio.h>
#include "FunctionHeadersMockTest2.h"
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};


struct node *newNode_Mango(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node )*1);
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * constructBinaryTree_spec(int *arr, int len){
	struct node *root = NULL;
	struct node *nodes[100];
	for (int i = 0; i < len; i++){
		nodes[i] = newNode_Mango(arr[i]);
	}
	int mid = (len / 2);
	for (int i = 0; i < mid; i++){
		struct node *curnode = nodes[i];
		struct node *leftnode = nodes[(i * 2) + 1];
		struct node *rightnode = nodes[(i * 2) + 2];
		if (curnode->data != -999){
			if (leftnode->data != -999){
				curnode->left = leftnode;
			}
			if (rightnode->data != -999){
				curnode->right = rightnode;
			}
		}
	}
	root = nodes[0];
	return root;
}

int compare_arrays_mc_spec(int *arr1, int *arr2, int len){
	int i = 0;
	while (i < len){
		if (arr1[i] != arr2[i]){
			return 0;
		}
		i++;
	}
	return 1;
}
void testMangoCollector(int advance, int *arr, int k, int ways_exp, int len, int *shortestpath_exp, int shortestpath_len_exp){
	struct node *root = constructBinaryTree_spec(arr, len);
	int finalarray[1000];
	int fl = 0;
	int ways = 0;
	ways = mangocity_count_ways(root, k, finalarray, &fl);
	
	printf("ways = %d", ways);

}
int main(){
	

	/*
	char *s1 = "abc,3\nbca,4\n";
	char *s2 = "bca,99\n";
	char *s3 = "cca,100\n";
	char * output = mini_leaderboard(s1,s2,s3);
	printf("[%s]", output);
	*/

	//testEncodeDecode();
	

	/*char board[8][8] =
	{
		{ _w_, ___, ___, ___, ___, ___, ___, ___ },
		{ ___, ___, ___, ___, ___, ___, ___, ___ },
		{ ___, ___, ___, ___, ___, ___, ___, ___ },
		{ ___, ___, _b_, ___, ___, ___, ___, ___ },
		{ ___, ___, _w_, _b_, ___, ___, ___, ___ },
		{ ___, ___, _b_, ___, ___, ___, ___, ___ },
		{ ___, ___, ___, ___, ___, ___, ___, ___ },
		{ _b_, ___, ___, ___, ___, ___, ___, ___ },
	};


	char colorWon;
	int minMoves = chessGame(board, &colorWon);
	printf("moves == %d\n", minMoves);*/


	int arr[] = { 10, 2, 3, 0, -16, 1, 2,
		0, 0, -999, -999, -18, -18, -999, -1,
		-999, -999, -16, -999, -999, -999, -999, -999, 8, -999, 0, -999, -999, -999, -18, -999 };
	int k = -4;
	int ways_exp = 4;
	int shortestpath[] = { 10, 2, -16 };
	int shortestpath_len = 3;
	int len = sizeof(arr) / sizeof(arr[0]);
	testMangoCollector(1, arr, k, ways_exp, len, shortestpath, shortestpath_len);

	return 0;
}