/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{ 
     if(n<=0)
		 return -1;
	 
	 
	int i = 2, j = 0, a, m = 1;
	while (i <= n)
	{
		a = m;
		m += j;
		j = a;
		i++;

	}
	return j;
}

int nthPrime(int num)
{
	if(num<=0)
		 return -1;
	 
	int i=1, j,flag,count =0;
	while (count < num)
	{	
		i++;
		flag = 0;

		for (j = 2; j <= i/2;j++)
		{
			if (i%j == 0)
			{
				flag = 1;
				break;
			}
               
		}
		if (flag == 0)
		{
			count++;
		}
		

	}
	
	return i;
}