/*

Use MainLinkedLists2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.

Objectives of LinkedLists2 Lesson:

->Merging two Linked Lists
->Reversing a LinkedList
->Inserting at a specific index

*/
#include <stdio.h>
#include "FunctionHeadersLinkedLists2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct node {
//	int num;
//	struct node *next;
//};
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->num = num;
//	newNode->next = NULL;
//	return newNode;
//}
//
//struct node * createList(int num) {
//	struct node *head = createNode(num % 10);
//	num /= 10;
//	while (num) {
//		struct node *newNode = createNode(num % 10);
//		newNode->next = head;
//		head = newNode;
//		num /= 10;
//	}
//	return head;
//}

//
//struct node{
//	int data;
//	struct node *next;
//};
//
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->data = num;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void addNode(struct node **head, int data){
//	struct node * cur = createNode(data);
//	if (*head == NULL){
//		*head = cur;
//	}
//	else{
//		struct node *temp = *head;
//		cur->next = temp;
//		*head = cur;
//	}
//}
//struct node{
//	int data;
//	struct node *next;
//};
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->data = num;
//	newNode->next = NULL;
//	return newNode;
//}
//
//void addNode(struct node **head, int data){
//	struct node * cur = createNode(data);
//	if (*head == NULL){
//		*head = cur;
//	}
//	else{
//		struct node *temp = *head;
//		cur->next = temp;
//		*head = cur;
//	}
//}
//void make_it_circular(struct node *head){
//	struct node *temp = head;
//	while (head->next != NULL){
//		head = head->next;
//	}
//	head->next = temp;
//}
struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};
struct passKeyNode *createnode(int num)
{
	struct passKeyNode *new_node = (struct passKeyNode*)malloc(sizeof(struct passKeyNode));
	new_node->num = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

struct passKeyNode* strtoDLL(char *str)
{
	int len = 0;
	while (str[len] != '\0'){
		len++;
	}
	if (len == 0)
		return NULL;

	struct passKeyNode *head = createnode(str[len - 1] - '0');
	for (int i = len - 2; i >= 0; i--)
	{
		struct passKeyNode *temp = createnode(str[i] - '0');
		head->prev = temp;
		temp->next = head;
		head = temp;
	}

	return head;
}

int main(){

	//Test InsertAtEveryKthNode
	//insertAtEveryKthNode(createList(289), 1);
	//Test LinkedListMedian

	//Test merge2 LinkedLists
	//merge2LinkedLists(createList(123), createList(456));
	//merge2LinkedLists(createList(789), createList(123));
	//Test reverse LinkedList
	//printf("%d\n", linkedListMedian(createList(3)));
	
	/*int dates[2][8] = { { 2, 9, 0, 2, 2, 0, 1, 6 }, { 2, 9, 0, 2, 2, 0, 1, 6 } };
	struct node *date1head = NULL, *date2head = NULL;
	for (int i = 7; i >= 0; i--){
		addNode(&date1head, dates[0][i]);
		addNode(&date2head, dates[1][i]);
	}

	int days = between_days(date1head, date2head);
	printf("days=%d\n", days);
*/

	//Test circularlistsmerge
	//int nums[50] = { 1, 3, 5, 10, 20, 30, 40, 50, 60, 100 };
	//int nums2[50] = { 2, 4, 6, 7, 8, 9, 11, 13, 55, 65 };
	////Last 1 is for checking whether A is circular or not .6 should again point to 1
	//int ans[100] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 20, 30, 40, 50, 55, 60, 65, 100, 1 };
	//int l1 = 10, l2 = 10, i;
	//struct node *head1 = NULL;
	//struct node *head2 = NULL;
	//for (i = l1 - 1; i >= 0; i--){
	//	addNode(&head1, nums[i]);
	//}
	//for (i = l2 - 1; i >= 0; i--){
	//	addNode(&head2, nums2[i]);
	//}
	//make_it_circular(head1);
	//make_it_circular(head2);

	//int len = merge_circularlists(&head1, &head2);

	//Test DoorToCross
	//struct passKeyNode *passkey = strtoDLL("53124");
	
	struct passKeyNode *passkey = strtoDLL("8776543212");
	int actualAns = doorstoCross(passkey);
	printf("number of the key=%d\n",actualAns);





	return 0;
}