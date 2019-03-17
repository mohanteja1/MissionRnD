/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :Brute Force
loopcount :1000 times, Took 1.248000 seconds in  sumoftwo brute force
loopcount :10000 times, Took 12.537000 seconds in  sumoftwo brute force
loopcount ;100000 times, Took 123.290000 seconds in  sumoftwo brute force

Way 2 :Sort and Search
loopcount ;1000 times, Took 0.033000 seconds in  sumoftwo sortandsearch
loopcount :10000 times, Took 0.356000 seconds in  sumoftwosortandsearch
loopcount :100000 times, Took 3.648000 seconds in  sumoftwo sortandsearch

Way 3:Extra array  
loopcount :1000 times, Took 0.004000 seconds in  sumoftwo extraarray
loopcount :10000 times, Took 0.038000 seconds in  sumoftwo extraarray
loopcount :100000 times, Took 0.383000 seconds in  sumoftwo extraarray


Conclusion :
sort and search can be usefull if input array size is large
but extra array method uses the extra array as hash table and also given constraints 
 and taken less time with complexity O(n).hence extraarray method is the best one in this case.

*/
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________O(n*n)
*/
int* sumoftwoBF(int *nums, int target, int len){
	int i, j, *p;
	if (nums == NULL || len <= 0)
		return NULL;

	p = (int *)malloc(sizeof(int) * 2);
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				if (nums[i] < nums[j])
				{
					p[0] = nums[i];
					p[1] = nums[j];
				}
				else
				{
					p[0] = nums[j];
					p[1] = nums[i];
				}
				return p;
			}
		}
	}
	
	    
	return NULL;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __________  O(n*logn)



*/


int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array

	if (nums == NULL || len <= 0)
		return NULL;


	qsort(nums, len, sizeof(int), cmpfunc);  //nlogn
	
	int remainpart,*index;
	//Do the task
	int *p;
	for (int i = 0; i < len;i++)
	{ 
		while (nums[i] == nums[i + 1])
			i++;

		
		
		remainpart = target - nums[i];
		index = (int*)bsearch(&remainpart, &nums[i], len-i, sizeof(int), cmpfunc); //binary search in the remaining part 
		

		if (index == NULL)
			;
		else
		{
			p = (int*)malloc(sizeof(int) * 2);

			p[0] = nums[i];
			p[1] = (int)*index;
			return p;
		}
	}

	return NULL;
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/



int* sumoftwoExtraArray(int *nums, int target, int len) {
	                   

	//nosort required
	if (nums == NULL || len <= 0)
		return NULL;

   int *extar = (int*)calloc(101,sizeof(int));
	extar[101] = { 0 };
	
    int i=0, remainpart,extc=0;
	
	for (int k = i; k < len; k++)
	{
		while (nums[k] == nums[k + 1])
			k++;
		
			extar[nums[k]] = nums[k];

			remainpart = target - nums[k];

			if (remainpart>=0)          //excluding negative parts
			if (extar[remainpart] != 0)
			{
				static int *p=(int*)malloc(sizeof(int) * 2);
				p[1] = remainpart;
				p[0] = nums[k];
				
				return p;
			}
		
	}

	return NULL;
}


