/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	//error cases
	if (Arr == NULL || len < 0)
		return NULL;

	int i = 0;
	//allocating space for extra int element
	int *P = (int*)malloc(sizeof(int)*(len+1));
	for (i = 0; i< len; i++)
	{

		P[i] = Arr[i];

	}
	P[i + 1] = 0;//intializing last space allocated with 0

	i = 0;
	//to find correct location to insert num 
	while (P[i] < num && i<len)
	{
		i++;
	}


	//shifting element to make a gap
	while (1)
	{

		P[len] = P[len - 1];
		printf("%d", P[len]);

		if (len == i)
			break;

		len--;
	}


	// inserting number
	P[i] = num;



	return P;
}