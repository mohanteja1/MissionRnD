/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int * find_sequences(int *arr, int len){
	
	if (arr == NULL || len <= 0)
		return NULL;


	int *final_arr = (int*)malloc(sizeof(int) * 6);

	int i=0,j=0,flag1=0,flag2=1,flag3=1,flag4=1,AP_count=1,AP_no_counter=0,gpcount=1;



	while (j<len)
	{
		//ap picking
		flag1 = 0;
		AP_no_counter = 0;
		
		while (arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1] && i<len-2 && flag2)
		{
			i++;
			flag1 = 1;
			AP_no_counter++;
		}
		if (flag1)//if ap found
		{
			if (AP_count == 1) //first ap
			{
				final_arr[1] = i + 1;
				final_arr[0] = i - AP_no_counter;
			}
			else              //second ap
			{
				final_arr[3] = i + 1;
				final_arr[2] = i - AP_no_counter;
				flag2 = 0;
			}
			AP_count++; 
		}
		i++;


		//gp picking

		if (flag4)  //allowing single gpseries
			while ((float)arr[j + 1] / arr[j] == (float)arr[j + 2] / arr[j + 1])
		{
			if (flag3)//record initial index;
			{
				final_arr[4] = j;
				flag3 = 0;
				flag4 = 0;
			}
			gpcount++;
			j++;

		}
		j++;
		

	}

	final_arr[5] = final_arr[4] + gpcount;

	
	return final_arr;
}