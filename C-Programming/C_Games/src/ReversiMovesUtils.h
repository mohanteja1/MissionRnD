/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

int isvalidCoordinate(ReversiGame *game, int x, int y);
/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove *newMove = (struct ReversiMove *)malloc(sizeof(struct ReversiMove) * 1);
	newMove->x = x;
	newMove->y = y;
	return newMove;
}

/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	int x=0, y=0;
	do{
		printf("enter valid co-ordinates (x,y): \n");
		scanf_s("%d", &x);
		scanf_s("%d", &y);

	} while (!isvalidCoordinate(game, x, y));

	return createMove(x, y);
}


/*
	To check the validity of coordinate on the board 
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {

	if (x < 0 || x >= game->rows || y < 0 || y >= game->rows)
		return 0;

	if (game->board[x - 1][y - 1] == 32)
		return 1;
	else
	    return 0;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int count1Direction(int x,int y,ReversiGame *game,int XIncrDecr,int YincrDecr,int changeflag)
{

	char currentColor, opponentColor;

	if (game->turn == 1){
		currentColor = 'w';
		opponentColor = 'b';
	}
	else
	{
		currentColor = 'b';
		opponentColor = 'w';
	}

	//next coin in the direction
	int tempx, tempy;
   if (changeflag)
	{
		tempx = x;
		tempy = y;
		game->board[x][y] = currentColor;
	}


	x = x + XIncrDecr;
	y = y + YincrDecr;
	

	int count=0;
	int flag = 0;
	while ( x >= 0 && y >= 0 && y<game->cols && x<game->rows && game->board[x][y] == opponentColor)
		{
			count++;
			x += XIncrDecr;
			y += YincrDecr;
			if (x < 0 && y < 0 && y >= game->cols && x >= game->rows)
			{
				return 0;
			}
			flag = 1;
		}

	
	if (flag){
		if (x >= 0 && y >= 0 && y<game->cols && x<game->rows && game->board[x][y] == currentColor)
		{
			
			if (changeflag)
			{ 
				while (x != tempx || y != tempy)
				{
					tempx += XIncrDecr;
					tempy += YincrDecr;
					game->board[tempx][tempy] = currentColor;
				}
			}
			return count;
		}
		else
			return 0;
	}
	return 0;
}


int isValidMove(ReversiGame *game, ReversiMove *move) {
	 
	int x = move->x - 1;
	int y = move->y - 1;
	
	if (x < 0 || x >= game->rows || y < 0 || y >= game->rows)
		return 0;


	//boundarys
	if (count1Direction(x, y, game, -1,-1,0))
		return 1;

	if (count1Direction(x, y, game, -1, 0,0))
	    return 1;
	
	if (count1Direction(x, y, game, -1, 1,0))
		return 1;

	if (count1Direction(x, y, game, 0, -1,0))
		return 1;
	
	if (count1Direction(x, y, game, 0, 1,0))
		return 1;
	
	if (count1Direction(x, y, game, 1, -1,0))
		return 1;
	
	if (count1Direction(x, y, game, 1, 0,0))
		return 1;
	
	if (count1Direction(x, y, game, 1, 1,0))
		return 1;


	//printf("\n invalid move\n");
	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	//printf("\nhasmove\n");
	ReversiMove *move = (struct ReversiMove *)malloc(sizeof(struct ReversiMove) * 1);
	
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			if (game->board[i][j] == 32)
			{
				move->x = i+1;
				move->y = j + 1;
				if (isValidMove(game, move))
					return 1;
			}
		}

	}
	
	return 0;

}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {

	game->NumberofMoves++;

	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/

void modifyTurn(ReversiGame *game) {
	game->turn *= -1;
	//printf("game turn :%d\n", game->turn);
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	game->state = 1;

	if (game->blackCount > game->whiteCount)
		game->winner = -1;
	else if (game->blackCount < game->whiteCount)
		game->winner = 1;
	else
		game->winner = 0;

	return;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {
	int x = move->x - 1;
	int y = move->y - 1;
	int count=0;
	if (isValidMove(game, move))
	{
		
		count += count1Direction(x, y, game, -1, -1, 1);
		count += count1Direction(x, y, game, -1, 0, 1);
		count += count1Direction(x, y, game, -1, 1, 1);
		count += count1Direction(x, y, game,0, -1, 1);
		count += count1Direction(x, y, game, 0, 1, 1);
		count += count1Direction(x, y, game, 1, -1, 1);
		count += count1Direction(x, y, game, 1, 0, 1);
		count += count1Direction(x, y, game, 1, 1, 1);
		if (game->turn == 1)
		{
			game->whiteCount += (count + 1);
			game->blackCount -= count;
		}
		else
		{
			game->whiteCount -= count;
			game->blackCount += (count+1);
		}
		modify(game);
		return true;

	}
	return false;
}


void printWinner(ReversiGame *game) {
	
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/

	if (game->winner == 1)
		printf("%s has won", game->player1name);
	else
		if (game->winner == -1)
			printf("%s has won", game->player2name);
		else
			printf("Game is Drawn");

}