/*

problemCode : RepeatedDivision
score : 10

Repeated 2 Division.

Given a Number N, your task is to find a number in the range [1,N]
such that the number is most divisible reptedly by 2

Example :
N = 6

x   -    DivisibleCount
1   -    0
2   -    1
3   -    0
4   -    2
5   -    0
6   -    1

Hence the answer is 4 since it can be repetedly divisible 2 times.

CONSTRAINTS : 
	1 <= N < 2^32

*/
#include<stdio.h>
#include "FunctionHeaders.h"
int power(int num, int pow)
{
	if (pow == 0)
		return 1;
	if (pow == 1)
		return num;
	if (pow % 2 == 0)
	{
		int i = power(num, pow / 2);
		return i*i;
	}
	else
	{
		int i = power(num, pow / 2);
		return num*i*i;
	}
}

int RepeatedDivision(int N){

	if (N < 1)
		return -1;

	int i = 0,temp=0;
	
	int lasttemp = 0;
	while (temp <= N)
	{
		i++;
		lasttemp = temp;
		temp=power(2, i);
	} 
	
	return lasttemp;
}

