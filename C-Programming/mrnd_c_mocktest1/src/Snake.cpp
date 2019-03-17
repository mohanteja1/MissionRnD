#include <stdio.h>
#include <stdlib.h>

/*
	Problem Code : Snake

	Srinivas is a snake lover. He recently started coding. He came across the snake game in his phone and he
	wanted to simulate it with his own coding knowledge. He divided the task into some modules and he asked
	your help for one of the modules. The module he asked is predicting the initial position of snake.

	The snake moves in the fashion shown below.

        1   ->   2  ->   3       ->      4        -> 5  
                 1       2               3           4 1
                         1               2 1         3 2       
	                                                                                                                                        
	Here 1 is the head of the snake.

	So initially the length of the snake is known.
	Now your job is to initialise the 2D matrix of 3x100 size with the position of the snake as shown above
	and leave the other positions as 0.
	
	Movement : Go down till end,Go right 1 step, Go Up till end,Go right 1 step, Repeat.
	
	Input : Length of the snake
	Output : Position of the snake based on its length.
	
	Ex:

	1)	Input =		1		
		Output = 	1


	2)	Input =		7
		Output = 	17   12  11  6  5
			    	16   13  10  7  4  1
                    15   14   9  8  3  2

	Return NULL for invalid cases.

*/
void fillCol(int **snakeBoard,int col, int max,int upDirection)
{
	if (upDirection==1)
	{
		snakeBoard[0][col] = max -2;
		snakeBoard[1][col] = max - 1;
		snakeBoard[2][col] = max ;
	}
	else
	{
		snakeBoard[0][col] = max;
		snakeBoard[1][col] = max - 1;
		snakeBoard[2][col] = max - 2;
	}


}




int** initialSnakePosition(int len){
	


	//create snakeBoardHere
	int** snakeBoard = (int **)calloc(3, sizeof(int*));
	snakeBoard[0] = (int*)calloc(100, sizeof(int));
	snakeBoard[1] = (int*)calloc(100, sizeof(int));
	snakeBoard[2] = (int*)calloc(100, sizeof(int));

	if (len == 0)
		return snakeBoard;
       
	//You can write any helper functions here, You need to fill the above created board
	
	int i = len / 3;
	int k = len%3;
	int j = 0;
	int direction=-1;
	while (j<i)
	{
		fillCol(snakeBoard, j, len,direction);
		direction *= -1;
		len -= 3;
		j++;
	}

	if (direction == 1)
	{
		int h = 2;
	       while (k > 0)
	     {
		
			snakeBoard[h--][j] =k-- ;
			
		}
	}
	else
	{
		int h = 0;
		while (k <2)
		{

			snakeBoard[h++][j] = k--;

		}
	}



	
	return snakeBoard;
}