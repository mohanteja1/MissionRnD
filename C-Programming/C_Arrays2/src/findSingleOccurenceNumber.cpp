/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>


int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len <= 0)
		return -1;


	int num,n = 1,hlen=(len/3)+1;
	
    int **hash = (int**)calloc((len%3)+1,sizeof(int));
	
	for (int i = 0; i < hlen; i++)
		hash[i] = (int*)calloc(2, sizeof(int));

	

	int flag1 = 0;

	for (int i = 0,j=0; i < len; i++)
	{
		flag1 = 1;
		
		for (int k = 0; k <j; k++)
		{
			
		
			if (hash[k][0]==A[i])
			{
				
				    hash[k][1] = 1;//marking 1 if element found again
					flag1 = 0;
					break;
				
			}
		}


		if (flag1)
		{
			
			hash[j][0] = A[i];
			j++;
		}
	}


	for (int i = 0; i < hlen; i++)
		if (hash[i][1] == 0)
		{

			num = hash[i][0];
			/*free(*hash);
			free(hash);*/
			/*for (i = 0; i<hlen; i++)
			{
				realloc(hash[i],0);
			}

			realloc(hash,0);*/

			return num;
		
		}



	return -1;
}