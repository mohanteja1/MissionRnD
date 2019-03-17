/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/

#include <malloc.h>
#include<stdio.h>
#include <string.h>

struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};


//tools for printing------------------------------
void printBool(bool *matrix, int m, int n)
{
	printf("\n%d,%d,%d\n",m,n,matrix);

	for (int i = 0; i < m; i++)
	{
		printf("\n");

		for (int j = 0; j < n; j++)
			printf(matrix[i*(n) + j] ? "true\t" : "false\t");
	}

	printf("\n");
}

void printPixel(char *pixels, int m, int n)
{
	printf("\n");

	for (int i = 0; i < m; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%c\t", pixels[i*(n) + j]);
	}
	printf("\n");
}















int ispointValid(int x, int y, int m, int n, struct Point pivot, char *pixel,result res)
{
	
	if (x >= m || x<0 || y>=n || y < 0 || pixel[x*(n) + y] != pixel[pivot.x*(n) + pivot.y] || res.visited[x*(n) + y] != false)
		return 0;
	else
        return 1;
}

void select(char *pixels, int m, int n, struct Point pivot, result &res, struct Point current,int dir) {
	
	//increment size and set true in visited
	  res.visited[current.x*n+current.y] = 1;
	
	  res.size += 1;
	

	  //4 directions

	    if (dir!=2&&ispointValid(current.x, current.y - 1, m, n, pivot, pixels, res))
	    {
			current.y += -1;
			
		
		select(pixels, m, n, pivot, res, current,3);
		current.y += 1;
	    }	
	 
	    if (dir!=1&&ispointValid(current.x + 1, current.y, m, n, pivot, pixels, res))
		{

			current.x +=1;
		
			select(pixels, m, n, pivot, res, current,4);
			current.x += -1;
		}
		if (dir!=4&&ispointValid(current.x - 1, current.y, m, n, pivot, pixels, res))
		{
			current.x += -1;
		
			select(pixels, m, n, pivot, res, current,2);
			current.x += 1;
		}
		if (dir!=3&&ispointValid(current.x, current.y + 1, m, n, pivot, pixels, res))
		{
			current.y += 1;
			select(pixels, m, n, pivot, res, current,2);
			current.y += -1;
		}

}


struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {

	if (pivot.x<0 || pivot.y<0 || pivot.x>m || pivot.y>n||pixels==NULL)
	{ 
		result invalid;
		invalid.size = 0;
		invalid.selected = {};
		invalid.visited = {};
		return invalid;
	}

	m = m + 1;
	n = n + 1;


    result res;
	res.size = 0;

	//printPixel(pixels, m, n);

	//create bool matrix

	//bool method--------------failed
	/*bool **val = (bool**)malloc(m *sizeof(bool*));
	for (int i = 0; i < m; i++){
		val[i] = (bool*)malloc(n* sizeof(bool));
		memset(val[i], 0, (n-1)*sizeof(val[0]));
		
	}*/

	//method 2---failed
	/*for (int i = 0; i < m;i++)
	for (int j = 0; j < n; j++){

		val[i][j] = 0;
		printf(val[i][j] ? "true\t" : "false\t");
	}*/





	//bool method 3--------------single array

	bool *val = (bool*)calloc(m*n, sizeof(bool));
	
	res.visited = val;

  //     printBool(res.visited, m, n);


	//call function
	select(pixels, m, n, pivot, res, pivot,0);


//create coordinate array
	res.selected = (Point*)malloc(sizeof(Point)*res.size);
	int k = 0;




	//print 
//	printBool(res.visited, m, n);






	//set pointcoordinates in the array 
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (res.visited[i*(n)+j]){
				res.selected[k].x = i;
				res.selected[k++].y = j;
			}
		}


	
	return res;
}
