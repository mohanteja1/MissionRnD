/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	//error cases
	if (Arr == NULL || len < 0)
		return NULL;

	int j = 0, k, temp, i = 0, flag1 = 0;
	for (i = 0; i < len; i++)
	{
		if (Arr[i]>Arr[i + 1]) 
		{
			if (!(flag1))
			{
				k = i;
				flag1 = 1;
			}
			else{
				j = i + 1;
				break;
			    }

		}
	}

	temp = Arr[j];
	Arr[j] = Arr[k];
	Arr[k] = temp;
	return NULL;
}