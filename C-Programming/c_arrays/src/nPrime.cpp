
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<malloc.h>
int* nPrime(int N)
{
	if (N <= 0)
		return NULL;
	int c = 3, i, j = 2, n = 10, *p, flag;
	p = (int *)malloc(sizeof(int)*n);
	p[0] = 2;
	p[1] = 3;
	while (c <= N)
	{
		flag = 0;
		c += 2;                                        //excluding even numbers
		for (i = 3; i <= c / 2; i++)                   //excluding division with 2
			if (c%i == 0)
			{
				flag = 1;
				break;
			}
		if (!flag)
		{
			if (j <= n - 1)
			{
				n = n + 5;
				p = (int*)realloc(p, n);
			}
			p[j] = c;
			j++;

		}
	}
	return p;
}