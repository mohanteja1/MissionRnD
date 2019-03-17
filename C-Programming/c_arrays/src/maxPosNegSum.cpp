
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{

	int c = 0, tempn = 0, tempp = 0, flag = 0, flag2 = 0;
	while (c < length)
	{
		//highest positive number
		if (input[c] >= 0 && input[c] >= tempp)
		{
			flag2 = 1;
			tempp = input[c];
		}

		//highest negative number
		if (input[c]<0)
			if (!flag)
			{
				tempn = input[c];
				flag = 1;
			}
			else if (input[c]>tempn)
				tempn = input[c];

		c++;

	}

	if (flag == 0 || flag2 == 0)
		return 0;
	else
		return tempp + tempn;

}