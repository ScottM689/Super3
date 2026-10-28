typedef struct sBoard{
    int board[9];
	int won;
} sBoard;

//board
int oneAway(sBoard board[9], int player);
void printBoard(sBoard board[9]);
int checkMove(sBoard Board[9], int roll, int box);
int* getValidMoves(sBoard board[9], int r);
int checkIfContains(int target, int list[9]);
void changePin();
int checkCanWin(sBoard Board[9], int player, int box, int roll);
void fillBox(sBoard board[9], int box, int player);
int hasWon(sBoard board[9], int player);

//main
int rollDice();

//player
int chooseBox();
void takeTurn(sBoard board[9]);
void doMove(sBoard Board[9], int player, int roll, int box);

//computer
void computerMove(sBoard board[9]);