/*
Use MainLinkedLists1 File for testing any other function in other Cpp files of the Strings Project.
DO NOT write main function in any other File or else your Build Fails.s
Do not write same add,display function in every CppFile .VS throws an error if two files
have some functions with same signature.
You can either change the signature in each file by using add1,display2 like that or
keep a common header file which has functions for handling common tasks for debugging
like displaying and include that header file in each Problem file .
Only jump into this lesson after you did all specified functions in Tutorial Lesson.
Objectives of C-LinkedLists-1 Lesson:
->Add/Delete/Display nodes in SLL
->Manipulate Links in SLL
->Handling SLL which have nodes of more than one data field
*/


//Do not edit below Header Files 
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersLinkedLists1.h"


//Write  helper functions below with which you can create a sll on your own.
struct node {
	int num;
	struct node *next;
};
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}
int compare(struct node *head, struct node *result) {
	while (head && result && head->num == result->num) {
		printf("%d\n", head->num);
		head = head->next;
		result = result->next;

	}
	return !head && !result;
}

int main(){

	//Test 012SortSll
	//int num = 0;
	//struct node *head = NULL;
	//struct node *actualnodes[100];
	//int actualNodeIndex = 0;
	//int num_array[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	//int output[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	//int len = 10;
	//int i = 0;
	//for (i = 0; i<10; i++)
	//{
	//	struct node * newNode = add(&head, num_array[i]);
	//	actualnodes[actualNodeIndex] = newNode;
	//	actualNodeIndex++;
	//}
	///*while (head != NULL)
	//{
	//printf("%d\n", head->data);
	//head=head->next;
	//}*/

	//sll_012_sort(&head);



	/*int num = 0;
	struct node *head = NULL;
	struct node *actualnodes[100];
	int actualNodeIndex = 0;
	int num_array[100] = { 2, 2, 2, 1, 1, 1, 0, 0, 0 };
	int output[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
	int len = 9;
	int i = 0;
	for (i = 0; i<len; i++)
	{
		struct node * newNode = add(&head, num_array[i]);
		actualnodes[actualNodeIndex] = newNode;
		actualNodeIndex++;
	}
	sll_012_sort_swapData(&head);
*/
	


	//Test numberToLinkedList
	/*int num=0;

	int A[] = { 8, 3, 4, 8 };

	struct node *head = numberToLinkedList(num);
    */

	//Test removeEveryKthNode



	//Test sortLinkedList



	//Test twodigitLinkedList
	struct node *head = createList(1);
	head=sortLinkedList(head);
//	struct node *result = createList(12345);
//	int i = compare(head, result);



	while (head != NULL)
	{
		printf("%d\n", head->num);
		head = head->next;
	}

	//Test isDivSLL

	






   	return 0;
}