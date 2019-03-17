/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 :BRUTE FORCE: DATA:232910011
    LOOP_COUNT: 5  TIME_TOOK :12.448000 SECONDS
	LOOP_COUNT: 10 TIME_TOOK :23.468000  SECONDS
	LOOP_COUNT: 20 TIME_TOOK :42.151000 S ECONDS

Way 2 :SQUARE_ROOT : DATA:232910011
   Loop count :   10K times,   Time Took 1.764000 seconds
   Loop count :	  100K times,  Time Took 12.201000 seconds

Way 3:OPTIMIZED  : DATA:232910011
     Loop count : 10K times,   Time  Took 0.688000 seconds
     loop count:  100K times,  Time Took 5.982000 seconds
Conclusion : 
      optimized method done the task well in less time 


*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){

	for (int i = 1; i <= number; i++)
	{
		if (i ==1)
			continue;
		else
			if (i==number)
			{
				return 1;
			}
		else 
			if (number%i == 0)
			{
				return 0;
			}


	}

}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){
	int i;
	int k = sqrt(number*1.0);
	for (i = 2; i <= k; i++)
	{
		
		if (number%i == 0)
		{
			//printf("%d", i);

			return 0;
		}

	}

	return 1;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){



	int i;
	int k = sqrt(number*1.0);
	if (number % 2 == 0)
		return 0;

		for (int i = 3; i <=k;i+=2)
		{
			if (!(number%i))
				return 0;
		}
return 1;
}


