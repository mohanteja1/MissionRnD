/*
Final Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/

#include <stdio.h>
#include "FunctionHeaders.h"
#include<malloc.h>

struct node {
	int bin;
	struct node* firstnode;
	struct node* secondnode;
	struct node* thirdnode;
};

struct loopnode {
	int roll;
	struct loopnode * next;
};

int charToInt(char bin){
	switch (bin){
	case '0':	return 0;
	case '1':	return 1;
	case '2':	return 2;
	}
	return -1;
}

struct node* createNewNode(char bin){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->bin = charToInt(bin);
	temp->firstnode = NULL;
	temp->secondnode = NULL;
	temp->thirdnode = NULL;
	return temp;
}
struct loopnode * createnode(int roll)	{
	struct loopnode *new_node = (struct loopnode*)malloc(sizeof(struct loopnode));
	new_node->roll = roll;
	new_node->next = NULL;
	return new_node;
}
struct node* constructTree(char *binString){
	struct node* root = NULL;
	struct node* nodes[2005];
	int i = 0;
	while (binString[i] != '\0'){
		nodes[i] = createNewNode(binString[i]);
		i++;
	}
	int invalid = 2;
	int mid = (i / 3);
	for (int i = 0; i < mid; i++){
		struct node* curnode = nodes[i];
		struct node* firstnode = nodes[(i * 3) + 1];
		struct node* secondnode = nodes[(i * 3) + 2];
		struct node* thirdnode = nodes[(i * 3) + 3];
		if (curnode->bin != invalid){
			if (firstnode->bin != invalid){
				curnode->firstnode = firstnode;
			}
			if (secondnode->bin != invalid){
				curnode->secondnode = secondnode;
			}
			if (thirdnode->bin != invalid){
				curnode->thirdnode = thirdnode;
			}
		}
	}
	root = nodes[0];
	return root;
}


struct loopnode * createListFromArray(int * nums, int len, int loopIndex) {
	struct loopnode* headnode = createnode(nums[0]);
	struct loopnode* curNode = headnode;
	struct loopnode* loopnodeTemp=NULL;
	if (loopIndex == 0){
		loopnodeTemp = headnode;
	}
	int i = 1;
	while (i<len){
		curNode->next = createnode(nums[i]);
		curNode = curNode->next;
		if (i == loopIndex) {
			loopnodeTemp = curNode;
		}
		i++;
	}
	curNode->next = NULL;
	if (loopIndex != -1) {
		curNode->next = loopnodeTemp;
	}
	return headnode;
}








int main(){

	//Test here
	/*

	*/
	/*int res;
	res = RepeatedDivision(10);
	printf("%d\n", res);*/


	/*int piece = 'B';
	long long int sourceX = 5,sourceY = 5;
	long long int destX = 5, destY = 4;
	int res = minimumPieceMoves(sourceX, sourceY, destX, destY, piece);
	printf("%d\n", res);
*/
	/*char binString[100] = "1111111121211";
	struct node* head = constructTree(binString);
	int expectedAnswer = 7;
	int actualAnswer = MaxGold(head);
	printf("\n%d\n", actualAnswer);*/



	int nums[5] = { 10, 20, 5, 3, 1 };
	struct loopnode* head = createListFromArray(nums, 5, 1);
	struct loopnode* headcopy = createListFromArray(nums, 5, 1);
	char* str = storeFormation(headcopy);
	struct loopnode* actualhead = createFormation(str);
	return 0;

}

