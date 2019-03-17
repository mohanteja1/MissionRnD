/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [1, 3].

If target is 5 ,Return [0,3]
If target is 22 ,return [1,3]

Note : 
Return_Array[0] should always be less than Return_Array[1]

Constraints : 
len <100000 
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .
*/
#include <stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int* sumoftwo(int *nums, int target, int len){
	


	if (nums == NULL || len <2 || len>100000)
		return NULL;

	int *ReturnArray = (int *)malloc(sizeof(int) * 2);


	for (int i = 0; i < len; i++)
	{
		if (nums[i]>100000 || nums[i] < -100000)
			return NULL;

		for (int j = i + 1; j < len; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				ReturnArray[0] = i;
				ReturnArray[1] = j;
				return ReturnArray;
			}
		}
	}

	return NULL;

	//printf("after time test");
}