/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :Brute Force fo N=10000;
loop count :100 times, Took 2.211000 seconds in nprime bruteforce way
loop count :1000 times, Took 22.370000 seconds in nprime bruteforce way
loop count :10000 times, Took 225.751000 seconds in nprime bruteforce way

Way 2 :Even removed for N=10000;
loop count :100 times, Took 1.312000 seconds in nprime even removed way
loop count :1000 times, Took 13.328000 seconds in nprime even removed way
loop count :10000 times, Took 135.681000 seconds in nprime even removed way

Way 3: Optimized for N=10000;
loop count :100 times, Took 0.021000 seconds in nprime optimized way
loop count :1000 times, Took 0.237000 seconds in nprime optimized way
loop count :10000 times, Took 2.530000 seconds in nprime optimized way

Conclusion :
optimized method is the best method it takes less time.I removed even numbers and only checked modulus with 
prime number in the array that value only upto square root of the number.

*/


#include <stdio.h>
#include <math.h>
#include<malloc.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	
	
	if (N <= 0)
		return NULL;
	int n = 5;
	int *p = (int *)malloc(sizeof(int)*1230); //worst space allocation
	int i,flag=0,j=0;

	
	for (i = 2; i <= N; i++)
	{
		flag = 1;
		for (int k = 2; k < i; k++)
		{
		
			if (i%k==0)
			{
				flag = 0;
				break;
			}
		}
			if (flag)
			{
				if (j <= n - 1)
				{
					n = n + 5;
					p = (int*)realloc(p, n);
				}
				p[j]= i;

				
				j++;
			}
		
		
	}
	return p;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{

	if (N <= 0)
	return NULL;
	int c = 3, i, j = 2, n = 10, flag;
	int *p = (int *)malloc(sizeof(int)*n);
	//int *p = new int[168];
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

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{

	int c = 3, i, j = 2, n = 170, flag, k;// count = 0, count2 = 0;
	int *p = (int *)malloc(sizeof(int)*1230);
	//int *p = new int[1230];
	p[0] = 2;
	p[1] = 3;
	p[2] = 5;
	p[3] = 7;

	for (i = 7; i <= N; i+=2)
	{
		
		if (i % 3 == 0 || i % 5 == 0||i % 7 == 0 && i!=7)
			continue;
			
		//count++;
		flag = 1;
		k = (int)sqrt(i*1.0);
		for (j = 3; p[j] <=k; j++)
		{
			//count2++;
			
			if ( i % p[j] == 0)
			{

				flag = 0;
				break;

			}
		}

		if (flag)
		{
			p[c] = i;
			c++;

		}


	}


	
	return p;
}