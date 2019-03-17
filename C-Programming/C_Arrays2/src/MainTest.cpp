/*
Well Done for completing the first part of the C Course ,If you didnt finish
Do complete them and come here again .

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int main(){

	//Test countGreaterNumbers

	/*struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
	int count = countGreaterNumbers(Arr, 5, "11-11-2015");
	printf("%d\n", count);*/


	//Test findSingleOccurenceNumber

	/*int A[10] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 3 };
	int k = findSingleOccurenceNumber(A, 10);
	printf("%d\n", k);*/


	//Test mergeSortedArray
	//struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	//struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
	////int A[3] = { 1, 2, 3 }, B[3] = { 4, 5, 6 };
	//struct transaction *result = mergeSortedArrays(A, 3, B, 3);
	//for (int i = 0; i < 6; i++)
	//	printf("%d\n", result[i].amount);




	//Test sortedArraysCommonElements
	/*struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction *c = sortedArraysCommonElements(A, 3, B, 3);
	for (int i = 0; i < 3; i++)
		printf("%s\n", c[i].date);*/
	/*struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
	if (sortedArraysCommonElements(A, 3, B, 3) != NULL)
		printf("error\n");*/

	//Test others
	//Test findsequence----------------------------------------------------------------------
	/*int input[10] = { -10, -30, -50, 100, 50, 25, -100, -225 };
	int ans[6] = { 0, 2, 5, 7, 3, 5 };
	int len = 8;
	int *res = find_sequences(input, len);

	for (int i = 0; i < 6; i++)
		printf("%d\n", res[i]);*/
	 //Test Pheights-------------------------------------------------------------------------

	/*int arr[100] = { 0 };
	int len = 100;
	int i = 0;
	int totalElems = 0;
	for (i = 0; i < len; i++){
		arr[i] = len - i;
	}

	int expectedAns[2] = { 0, 0 };

	int *actualArray = getLeaderIndex(arr, len);
	

	printf("_______________________________\n");
	*/
	//int arr[10001] = { 0 };
	//int len = 10001;
	//int smallArr[10] = { 5, 10, 20, 40, 55, 68, 73, 84, 94, 10240 };
	//int i = 0;
	//int totalElems = 0;
	//for (i = 0; i < 100; i++){
	//	int j = 0;
	//	for (j = 0; j < 10; j++){
	//		arr[totalElems] = smallArr[j];
	//		//printf("%d\n", arr[totalElems]);
	//		totalElems++;
	//	}
	//	smallArr[9] = smallArr[9] - 3;
	//}
	//arr[10000] = 0;
	//int expectedAns[2] = { 9, 9 };

	//int *actualArray = getLeaderIndex(arr, totalElems);


	
		/*int arr[100000] = { 0 };
		int len = 100000;
		int i = 0;
		int totalElems = 0;
		for (i = 0; i < len; i++){
			arr[i] = len - i;
		}

		int expectedAns[2] = { 0, 0 };

		int *actualArray = getLeaderIndex(arr, len);*/
	/*int arr[100000] = { 0 };
	int len = 100000;
	int i = 0;
	int totalElems = 0;
	for (i = 0; i < len; i++){
		arr[i] = i;
	}

	int expectedAns[2] = { len - 1, len - 1 };*/

//int arr[100] = { 1, 2400, 50, 30, 20, 0, 2, 4, 2304, 2300, 2000, 1800, 1000, 500, 502, 504, 509, 2301, 2302, 0 };
//int len = 20;
//int expectedArray[2] = { 18, 9 };
//int *actualArray = getLeaderIndex(arr, len);
	
	//printf("%d\n", actualArray[0]);
	//printf("%d\n", actualArray[1]);

	////printf("%d\n", arr[9]);
	//printf("%d\n", arr[actualArray[0]]);

int arr[10] = { 442, 444, 367, 445, 134, 103, 219, 983, 999, 950 };
int len = 9;
int ansLen = 0;
int expectedArray[100] = { 367, 103, 219 };
int expectedLen = 3;

int *ans = getSquareLeaderArray(arr, len, &ansLen);
printf("%d\n", ansLen);
for (int i = 0; i < ansLen; i++)
printf("%d\n", ans[i]);

	return 0;
}