/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int strncompare2(char * key, char *data)
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

int binarySearch2(char * key, struct transaction *Arr, int len, int low)
{
	int  k = 0, high, mid;
	//low = 0;
	high = len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strncompare2(key, Arr[mid].date) == 0)
		{
			k = mid;
			break;


		}
		else if (strncompare2(key, Arr[mid].date)>0)
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



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || BLen <= 0 || ALen == NULL)
		return NULL;


	struct transaction *output = (struct transaction *)malloc(sizeof(struct transaction) * (BLen+ALen));
	int Ap = 0, Bp = 0;
	int k=0;
     int firstA = binarySearch2(A[0].date, B, BLen, 0);
	 int firstB = binarySearch2(B[0].date, A, ALen, 0);
	/* int lastA = binarySearch2(A[ALen-1].date, B, BLen, 0);
	 int lastB = binarySearch2(B[BLen-1].date, A, ALen, 0);
	 printf("%d-%d-%d-%d\n", firstA, firstB, lastA, lastB);
	 */


	 // reducing comparisions
	 if (firstA > firstB)
	 {
		 for (int i = 0; i < firstA; i++)
		 {
			 output[i] = B[i];
			 Bp = i;
			// printf("%d\n", output[i].amount);

		 }
		 k = Bp;
	 }
	 else 
	 {
		 for (int i =0; i < firstB; i++,k++)
		 {
			 output[i] = A[i];
			 Ap = i;
			// printf("%d\n", output[i].amount);
		 }
		 k = Ap;
	 }

	 //comparisions part
	 while (Ap<ALen && Bp <BLen)
	 {
	      
		 if (strncompare2(A[Ap].date, B[Bp].date) == 0)
		 {
			 output[k++] = A[Ap++];
				 output[k++] = B[Bp++];
		 }
	else
		 if (strncompare2(A[Ap].date,B[Bp].date)<0)
			 output[k++] = A[Ap++];
		 else
			 output[k++] = B[Bp++];
	 }

	 while (Ap < ALen)
		 output[k++] = A[Ap++];

	 while (Bp< BLen)
		 output[k++] = B[Bp++];



	return output;
}