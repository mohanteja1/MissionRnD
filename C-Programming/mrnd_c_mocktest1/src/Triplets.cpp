/*
Problem Code : TRIPLETS

You are given an Array of integers and length. You need to find the Number of triplets
that satisfy the given conditions.
 
if a triplet is of the form (A[i],A[j],A[k]),
then for following conditions hold.

 --> i < j < k 
 --> A[k]%A[j] == 0 and A[j]%A[i] == 0

For Example : 
	input  : [1, 2, 4, 6]
	output : 2
	
	//and those 2 are --> {1,2,4} , {1,2,6}

	input  : [2, 1, 4, 3, 6]
	output : 1

	//The only possible --> {1,3,6}

	input  : [1, 1, 1, 1]
	output : 4

	//the triplet (1,1,1) can be formed in 4 ways.

Constraints :
	3 <= len  <= 1000000 
	1 <= A[i] <= 10000 

Note : 
	Return -1 for all invalid cases
	The answer always fits in 64 bit integer (long long) 
	O(N^3) passes only 10% of the test cases
*/


long long findTriplets(int *A, int len) {
      long long res = 0;
	   
	  if (len > 1000000 || len < 3)
		  return -1;

	  for (int i = 0; i < len - 2; i++)
		  for (int j = i + 1; j < len - 1; j)
			  for (int k = j + 1; k < len; k++)
				  if (A[i] % A[j] == 0 && A[j] % A[k] == 0)
					  res++;


	return res;
}