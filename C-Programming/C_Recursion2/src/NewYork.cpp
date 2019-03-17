/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2
 
(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>

int checkInvalidBoundary(int x,int y,int row,int col)
{
	if (x > row ||x<0 || y > col||y<0)
		return 0;
	else
		return 1;
}

int newyork_recur(int n, int m, int x, int y, int K, int dir) {
	
//printf("(%d,%d),dir=%d,k=%d\n", x, y, dir, K);


	if (x == n && y == m )
	{
		if (!K){
			return 1;
		}
		else   return 0;
	}

	if (K < 0)
		return 0;




//if (x == n && y == m && K == 0){
//	 

//	return 1;
//}
//	if (K <0)
//		return 0;
//







	int count1 = 0, count2 = 0,count3=0,count4=0;
	
	//dir!=n if turning back is not allowed


	if (/*dir!=3 &&*/ checkInvalidBoundary(x + 1, y, n, m))
	{
		count1 = newyork_recur(n, m, x + 1, y, (dir == 1) ? K : K - 1, 1);
	}

	if (/*dir != 4 &&*/ checkInvalidBoundary(x, y + 1, n, m))
	{
		count2 = newyork_recur(n, m, x , y+1, (dir == 2) ? K : K - 1, 2);
	}

	if (/*dir != 1 && */checkInvalidBoundary(x - 1, y, n, m))
	{
		count3 = newyork_recur(n, m, x-1, y, (dir == 3) ? K : K - 1, 3);
	}

	if (/*dir != 2 &&*/ checkInvalidBoundary(x, y - 1, n, m))
	{
		count4 = newyork_recur(n, m, x, y - 1, (dir == 4) ? K : K - 1, 4);
	}


	return count1+count2+count3+count4;
}

int NewYork(int n, int m, int k){

	
//invalids
	if (n <= 0 && m <= 0 || k <= 0)
		return 0;




	
	

	
	return newyork_recur(n-1, m-1, 0, 0, k +1, 0);

     
}