/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"
void generate_array(int **input_array, int rows, int columns, int seq)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			input_array[i][j] = (k++)*seq;
}
struct student
{
	char letter;
	struct student *first;
	struct student *second;
	struct student *third;
};
struct student * new_node_spec_p5(char letter){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	temp->letter = letter;
	temp->first = NULL;
	temp->second = NULL;
	temp->third = NULL;
	return temp;
}
struct student * constructFormation_spec(char *students){
	struct student *root = NULL;
	struct student *nodes[2005];
	int i = 0;
	while (students[i] != '\0'){
		nodes[i] = new_node_spec_p5(students[i]);
		i++;
	}

	char invalidLetter = 'X';
	int mid = (i / 3);
	for (int i = 0; i < mid; i++){
		struct student *curnode = nodes[i];
		struct student *firstnode = nodes[(i * 3) + 1];
		struct student *secondnode = nodes[(i * 3) + 2];
		struct student *thirdnode = nodes[(i * 3) + 3];
		if (curnode->letter != invalidLetter){
			if (firstnode->letter != invalidLetter){
				curnode->first = firstnode;
			}
			if (secondnode->letter != invalidLetter){
				curnode->second = secondnode;
			}
			if (thirdnode->letter != invalidLetter){
				curnode->third = thirdnode;
			}
		}
	}
	root = nodes[0];
	return root;
}
int main(){

	////Pillars
	//int nopath = 0;
	//const int m = 1000, n = 1000;

	//int **blocks = (int **)malloc((sizeof(int *))*m);
	//blocks[0] = (int *)malloc(sizeof(int) * m * n);
	//for (int i = 0; i < m; i++)
	//	blocks[i] = (*blocks + n * i);
	//for (int i = 0; i < m; i++){
	//	for (int j = 0; j < n; j++){
	//		blocks[i][j] = 1;
	//	}
	//}
	//const int jc_exp = 0;
	//int maxpath_exp[jc_exp + 1] = { 1 };

	/*for (int i = 0; i < m; i++)
	{
		printf("\n");

		for (int j = 0; j < n; j++)
			printf("%d\t", blocks[i][j]);


	}*/
	/*printf("\n");
	
	int count = 0;
	pillars_max_jumps(&blocks[0][0], m,n , &count);
	printf("count = %d", count);*/
	//Check NSnipers
	/*int n =8 ;
	int board[8][8];
	int i = 0, j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}


	int result = solve_nsnipers(&board[0][0], n);
*/
	/*int n = 4;
	int board[4][4];
	int i = 0, j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}
	int result = 1;
	result = solve_nsnipers(&board[0][0], n);
	printf("result = %d\n", result);*/

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code
	/*int rows = 5, columns = 5;
	int **input_array = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
		input_array[i] = (int *)malloc(columns * sizeof(int));

	generate_array((int**)input_array, rows, columns, 2);

	int *output_array = spiral(rows, columns, (int**)input_array);
*/

	//Check Maze Sample Code

	/*int maze[3][5] = {
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	int m = 3, n = 5;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 4;
	/*int maze[1][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	int m = 1, n = 20;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 8;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/


//minBallandMaxballdistance
	char students[100] = "ABXXCXXXXXXXX";
	int expectedMinBallDistance = 1;
	int expectedMaxBallDistance = 3;
	struct student * leaderStudent = constructFormation_spec(students);
	static int actualMaxBallDistance = 0;
	static int actualMinBallDistance = 0;
	findBallDistance(leaderStudent, &actualMinBallDistance, &actualMaxBallDistance);

	printf("min=%d\n", actualMinBallDistance);
	printf("max=%d", actualMaxBallDistance);










	return 0;

}
