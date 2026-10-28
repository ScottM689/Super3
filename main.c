// to save game i think a good way would be to save whose turn it is into a file and the current board as well 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>


int main(){ //prints rules
printf("Super3");
printf("_____________________\n");
printf("Objective:\n ");
printf(" The aim of the game is to get three boxes in a row. A box is won when three pins are in a row.\n");
printf("How to play:\n");
printf(" first you roll the dice to decide who goes first. The highest roll goes first. Then you roll for the normal game, once you roll again, you will get a number between 2 and 12. the games board works as follows for numbered boxes/pins");
printf(" \n(3 4 5)\n");
printf(" (6 7 8)\n");
printf(" (9 10 11)\n");
printf(" so if you want to go to the top left, you select box number 3\n");
printf("Rules:\n");
printf(" if you roll a 2, you can remove one pin from the board. if you roll a 12 you can place the pin in any available box and pin.\n");
printf("in order to start playing, please input anything: ");
char* d = malloc(5); 
scanf("%5s", d); //checks if player inputs anything and runs game if so
int finished = 0;
int b = 0;

srand(time(NULL)); //ensures random is random

sBoard Board[9] = {0};

for (int a  = 0; a < 9; a ++){//intialises board won values
	Board[a].won = 0;
}
	system("cls");




while (finished == 0){ //main 
	
	takeTurn(Board);
	system("cls");
	computerMove(Board);
	printBoard(Board);
	if(hasWon(Board, 1) || hasWon(Board, 2)){ //checks for a win
		printf("game over.");
		finished = 1;
	}
	for(b = 0; b <9; b ++){ //checks for a draw
		if(Board[b].won != 0){
			if(b == 8){
				printf("game over: draw");
				finished =1;
				}
			}
			
		else{
		b = 9;
		}
	
	}
	
	

}

return 0;
}
int rollDice(){
	int roll = (rand() % 11);
	return roll;
}

