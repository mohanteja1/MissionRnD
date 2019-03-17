
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

Problem Code :SC
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {


	int lowbd = 0, highbd = len - 1, midp, datalocation;
	//errorcheck
	if (Arr == NULL || len < 0)
		return NULL;
	//binary search
	while (lowbd <= highbd)
	{

		midp = lowbd + (highbd - lowbd) / 2;


		if (Arr[midp] == score)
		{
			datalocation = midp;
			break;
		}
		else
		{
			if (Arr[midp] < score)
			{

				lowbd = midp + 1;
			}
			else
			{
				highbd = midp - 1;
			}
		}
	}
	//pointing correct index of dive num 
	if (Arr[midp] == score)//if present in array
	{
		int j = 0, i = 0, k = 0;
		if (Arr[midp + 1] == score || Arr[midp - 1] == score)//redundancy of given num exists
		{

			i = midp;
			while (Arr[--i] == score)//midpoint right redundancy
			{
				j++;
			}

			i = midp;
			while (Arr[++i] == score)//mid point left redundancy
			{
				k++;
			}
			*moreCount = len - (midp + 1 + k);
			*lessCount = midp - j;
			return NULL;

		}
		else //no redundancy
		{
			*moreCount = len - (midp + 1);
			*lessCount = midp;
		}

	}
	else  //if num not exist in array
		if (Arr[midp] >= score)
		{
			*moreCount = len - midp;
			*lessCount = midp;
		}
    else
		if (Arr[midp] <= score)
	{

		*moreCount = len - (midp + 1);
		*lessCount = midp + 1;

	}

}
