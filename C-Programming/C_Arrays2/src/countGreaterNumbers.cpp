/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int strncompare(char * key, char *data)
{
	for (int i = 6; key[i] != 0; i++)
	{
		if (key[i] != data[i])                      //year
			return key[i] - data[i];
	}
	for (int i = 3; i < 5;i++)
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


int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	
	if (Arr == NULL || len <= 0||date==NULL)
		return NULL;
	
	int  k = 0,low,high,mid;
	low = 0;
	high = len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strncompare(date, Arr[mid].date) == 0)
		{
			k = mid;
			while (strncompare(Arr[k].date, Arr[k + 1].date) == 0)  //same date exists
				k++;

			return len - (k + 1);

	
		}
		else if (strncompare(date,Arr[mid].date)>0)
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

	
	if (low>=high)
    return 0;

	return NULL;
}
