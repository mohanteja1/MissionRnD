/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#include<stdio.h>

int isValid(int *maze, int rows, int columns, int nextX, int nextY)
{
	if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= columns) //coordinate 1 check
		return 0;
	else
		if (maze[nextX * columns + nextY] == 1)
		{
			//printf("path = %d ,%d\n", nextX, nextY);
			return 1;

		}
		else
			return 0;

}

int path_recursive(int *maze,int rows,int columns,int x1,int y1,int x2,int y2,int noback)
{
	if (x1 == x2&& y1 == y2)
	{
		//printf("got solution %d %d\n", x1, y1);
		return 1;
	}
	//toprevent backtrack loop again use noback var
	//top =1
	if (isValid(maze, rows, columns, x1 - 1, y1)&&noback!=4)
		if(path_recursive(maze, rows, columns, x1-1, y1, x2, y2,1))
			return 1;
    //right = 2
	if (isValid(maze, rows, columns, x1 , y1+1)&&noback!=3)
		if(path_recursive(maze, rows, columns, x1, y1+1, x2, y2,2))
			return 1;

	//left = 3
	if (isValid(maze, rows, columns, x1 , y1-1)&&noback!=2)
		if(path_recursive(maze, rows, columns, x1 , y1-1, x2, y2,3))
			return 1;

	//bottom = 4
	if (isValid(maze, rows, columns, x1 +1, y1)&&noback!=1)
		if(path_recursive(maze, rows, columns, x1 +1 , y1, x2, y2,4)) 
			return 1;

	return 0;

}


int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (maze == NULL || rows < 1 || columns < 0) //maze check
		return 0;
	if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= columns) //coordinate 1 check
		return 0;
	if (x2 < 0 || x2 >= rows || y2 < 0 || y2 >= columns)//coordinate 2 check
		return 0;

	int **maze1=&(maze) ;
	/*for (int i = 0; i < rows; i++)
	{
		printf("\n");

		for (int j = 0; j < columns; j++)
			 printf("%d\t", maze[i*columns + j]);


	}*/

	return path_recursive(maze, rows, columns, x1, y1, x2, y2,0);

}
