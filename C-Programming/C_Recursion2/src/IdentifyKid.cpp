/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
#include<math.h>


//thue - morse sequences

int identifyKidRecurs(int N, int K)
{

	if (N == 1)
		return 0;
	if (K / 3 == 0 && K % 3 == 0)
		return 0;


	//printf("level =%d ,parent=%d,kid_offset=%d\n",N-1, K / 3, K % 3);

	return identifyKidRecurs(N - 1, K / 3) + K % 3;

}


char identifyKid(int N, int K) {
	
	if (N <= (log(K*1.0) / log(3 * 1.0)))
		return 0;
	
         int kid =identifyKidRecurs(N, K - 1)%3;
		 
		 //printf("%d", kid);
		 switch (kid){
		 case 2 :
			 return 'C';
		 case 1 :
			 return 'B';
		 case 0:
			 return 'A';
		 }
		

	          return 0;

}