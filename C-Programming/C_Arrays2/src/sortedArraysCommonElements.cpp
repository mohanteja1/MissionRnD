/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
//#include "FunctionHeadersArrays2.h"
#include <iostream>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int strncompare1(char * key, char *data)
{
	for (int i = 6; key[i] != 0; i++)
	{
		if (key[i] != data[i])                      //year
			return key[i] - data[i];
	}
	for (int i = 3; i < 5; i++)
	{
		if (key[i] != data[i])
			return key[i] - data[i];                 //month
	}

	for (int i = 0; i < 2; i++)
	{
		if (key[i] != data[i])
			return key[i] - data[i];                 //day
	}

	return 0;                    //equal;
}

int binarySearch(char * key,struct transaction *Arr,int len,int low)
{
	int  k = 0, high, mid;
	//low = 0;
	high = len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strncompare1(key, Arr[mid].date) == 0)
		{
			k = mid;
			break;


		}
		else if (strncompare1(key, Arr[mid].date)>0)
		{
			high = high;
			low = mid + 1;
		}
		else
		{
			low = low;
			high = mid - 1;
		}
	}

	return mid;
}



struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL ||B== NULL|| BLen <= 0 ||ALen==NULL)
		return NULL;



	int k = 0,count =0,n=1;

	struct transaction *output= (struct transaction *)malloc(sizeof(struct transaction)*1);
	 
	for (int i = 0; i < ALen; i++)
	{
		k = binarySearch(A[i].date, B, BLen, k);           //binary search in the next reduced length
		
		if (strncompare1(A[i].date, B[k].date) == 0)
		{
			
			output = (struct transaction *)realloc(output,sizeof(struct transaction )* (n + 1));
			n++;
			output[count] = A[i];
			count++;
		}
		else 
			if (k >= BLen)  //if the element of one array goes out of boundary while binary search in another array
			{              //then 
				break;
			}

	}
	/*printf("%d\n", count);*/
	if (count == 0)        //no elements common
	{
		free(output);
		return NULL;
	}

	return output;
}