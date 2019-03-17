/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiralRecursive(int **input_array ,int *arr,int len,int row, int col,int index,int currentRow,int currentCol,int direction)
{
	//termination
	if (index>=len)
		return;
	
		switch (direction){
	case 1:
		for (int i = currentCol; i <= currentCol + col; i++)
		{
			arr[index++] = input_array[currentRow][i];
		}
		spiralRecursive(input_array, arr,len, row - 1, col, index, currentRow + 1, currentCol + col, 2);
		break;

	case 2:
		for (int i = currentRow; i <= currentRow + row; i++)
		{
			arr[index++] = input_array[i][currentCol];
		}
		spiralRecursive(input_array, arr,len, row , col-1, index, currentRow + row, currentCol - 1, 3);
		break;


	case 3:
		for (int i = currentCol; i >= currentCol - col; i--)
		{
			arr[index++] = input_array[currentRow][i];
		}
		spiralRecursive(input_array, arr,len, row - 1, col, index, currentRow - 1, currentCol - col,4 );
		break;

	case 4:
		for (int i = currentRow; i >= currentRow -row; i--)
		{
			arr[index++] = input_array[i][currentCol];
		}
		spiralRecursive(input_array, arr,len, row , col - 1, index, currentRow - row, currentCol + 1, 1);
		break;
	}

	return;

}


int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows < 1 || columns < 1)
		return NULL;

	/*for (int i = 0; i < rows; i++)
	{
		printf("\n");
		for (int j = 0; j < columns; j++)
			printf("%d\t", input_array[i][j]);
	}*/


	int noElements = rows*columns;

	int *outputArray = (int *)calloc(noElements,sizeof(int));
	
	spiralRecursive(input_array, outputArray,noElements, rows-1, columns-1,0 ,0,0, 1);
	//printf("\n\n");
	/*for (int i = 0; i < rows*columns; i++)
	   printf("out[%d] =%d\n",i, outputArray[i]);*/


	
	return outputArray;
	
}
