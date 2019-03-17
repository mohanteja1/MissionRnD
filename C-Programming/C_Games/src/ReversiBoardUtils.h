#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ReversiGame {
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	// do allocate memory for '\0' as it is character array.
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;


void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);

/*

Create a new ReversiGame By allocating memory from Heap , Let it be game;
Create a 2D Array from Heap(Dynamically) with specified number of rows and cols
and copy its reference to game->board;

Note : Return NULL for Invalid Inputs
Note : Copy Rows into newlyCreatedBoard->rows , and vice versa for cols ,
Also copy player1name,player2name.
*/

ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {
	
	if (rows <= 2 || cols <= 2 || player1 == NULL || player2 == NULL || rows != cols)
		return NULL;
	//create board
	ReversiGame *NewGame = (struct ReversiGame *)malloc(sizeof(struct ReversiGame)*1);
	
	NewGame->board = (char **)malloc(sizeof(char*)*(rows));
	for (int i = 0; i < rows; i++)
	{
		NewGame->board[i] = (char *)malloc(sizeof(char)*(cols + 1));
		NewGame->board[i][cols]=0;
	}
	//copy player names
	NewGame->player1name = player1;
	NewGame->player2name = player2;
	//copy rows and cols
	NewGame->rows = rows;
	NewGame->cols = cols;

	return NewGame;
}


/*
Copy the tobeCopied Array into game->board .
Learn how to Copy a 2D array when address of first row is given.
Note this function is called in the following way

Also Initialize the turn variable, whiteCount with no of white coins and same for black.

Do Nothing for Invalid Inputs
*/

void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {
	
	if (game == NULL || tobeCopiedBoard == NULL || rows <= 2 || cols <= 2 || rows != cols)
	{
		game = NULL;
		return;

	}
	int whiteCount = 0, blackCount = 0;

	for (int i = 0; i < rows; i++){
	

		for (int j = 0; j < cols; j++)
		{

			game->board[i][j] = tobeCopiedBoard[i*(cols + 1) + (j%rows)];

			if (game->board[i][j] == 'w')
				whiteCount++;
			else if (game->board[i][j] == 'b')
				blackCount++;
		}
		game->board[i][rows+1] = 0;

	}

	game->turn = turn;
	if (!hasMove(game))
		 modifyTurn(game);
	
	if (!hasMove(game))
		   game->state=1;

	game->blackCount = blackCount;
	game->whiteCount = whiteCount;
	game->NumberofMoves = 0;
	return;
}

/*
Check if the Current board is in End Position . Return 0 if the game is Ended, 1 if not .
Win Condition : Either all the squares are filled or a stalemate position (No one can Move)

*/

int checkReversiGameOver(ReversiGame *game){
	if (!hasMove(game))
	{
		modifyTurn(game);
		if (!hasMove(game))
		{
			game->state = 0;
			endGame(game);
			return 0;
		}
		else
		{	
			return 1;
		}
	}
	else
	return 1;
}

void printMoves(ReversiGame *game){
	/*
	Sample output :
	Whites Count : 5
	Black Count : 4
	Move Count : 9
	*/
	printf("Whites count :%d\n",game->whiteCount);
	printf("Blacks count :%d\n",game->blackCount);
	printf("Moves count  :%d\n", game->NumberofMoves);


	return;
}

/*
Print the Board in a Good Way.Make sure Each Number is properly formatted and Seperated, and Row lines too .
Print Empty Space when you encounter 0.Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking / UI Skills .
See the link we shared for sample screenshots for inspiration.
*/

void drawBoardOnScreen(ReversiGame *game) {
	printf("\t\t\t\tREVERSI\n");
	printf("\t\t %s(white) | vs | %s(black)\n", game->player1name, game->player2name);
	
	if (game->turn == 1)
		printf("\t\t\t**** WHITES TURN ****\n");
	else
		printf("\t\t\t**** BLACKS TURN ****\n");
	
	printf("\n\t\t   ");
	for (int r = 1; r <=game->cols; r++)
		printf("  %d ",r);
	printf("\n");
	for (int i = 0; i < game->rows; i++)
	{
		printf("\n\t\t   ");
		for (int r = 0; r < game->cols; r++)
			printf(" ---");

		printf("\n\t\t%d  ",i+1);

		for (int j = 0; j < game->cols; j++){

			if (game->board[i][j] == 'w')
				printf("| %c ", 254);
			else if (game->board[i][j] == 'b')
				printf("| %c ", 79);
			else
				printf("| %c ", game->board[i][j]);

		}
		printf("|");
	}
	printf("\n\t\t   ");
	for (int r = 0; r < game->cols; r++)
		printf(" ---");


	
	printf("\n\t game turn:%d\n", game->turn);




	return;
}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/

void clearScreen(ReversiGame *game){
	system("cls");

	/*for (int i = 0; i < 30; i++)
		printf("\n");*/

}

/*
Clear the Screen and ReDraw the Board ,Call above two functions
*/

void clearAndRedrawScreen(ReversiGame *game){
	clearScreen(game);
	drawBoardOnScreen(game);
}



