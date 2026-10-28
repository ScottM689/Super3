#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void computerMove(sBoard board[9]){
	int a = 0;
	int comp = 2;
	int r = rollDice();
	int y =0;
	int valid =  0;
	while (r >= 9){
		r = rollDice();
	}
	int* x = getValidMoves(board, r);
	//check if no moves
	
	if (*x == -1){
		return;
	}
	
	//checks if one away from winning game
	int j = oneAway(board, comp);
	while (*(x +y) != -1 && j != -1){
		if(*(x + y) == j){
			valid = 1;
		}
		y++;
	}		
	
	if(valid == 1){
			if(checkCanWin(board, comp, j, r) == 1){
				printf("Computer went to box %d , pin %d \n", j +3 , r + 3);
				fillBox(board, j, comp);
			}
			doMove(board, comp,r, j); 
			printf("Computer went to box %d , pin %d \n", j+3, r + 3);
			return;
	}
	
	
	int b = 0;
	//check if can win a box
	while (*(x+a) != -1){
	b = *(x + a);
	if(checkCanWin(board, comp, b, r) == 1){
		printf("Computer went to box %d , pin %d \n", b +3 , r + 3);
		fillBox(board, *(x +a), comp);
		a = 0;
		return;
	}
	a++;

	}
	a = 0;
	//check if centre
	if(board[4].board[r] ==0){
		printf("Computer went to box %d , pin %d \n", 7, r +3);

		doMove(board, comp, r, 4);
		return;
	}
	
	//check corners
	while (*(x+a) != -1 ){
		if (*(x+a) ==0){
		printf("Computer went to box %d , pin %d \n", 3, r + 3);
			
			doMove(board, comp, r, 0);
			return;
		}
		else if (*(x+a) ==2){
		printf("Computer went to box %d , pin %d \n", 5, r + 3);
			
			doMove(board, comp, r, 2);
			return;
		}
		else if (*(x+a) ==6){
		printf("Computer went to box %d , pin %d \n", 9, r + 3);
			
			doMove(board, comp, r, 6);
			return;
		}
		else if (*(x+a) ==8){
		printf("Computer went to box %d , pin %d \n", 11, r + 3);
			
			doMove(board, comp, r, 8);
			return;
		}
		a++;
		
	}

	doMove(board, comp, r, *x);
		printf("Computer went to box %d , pin %d \n", *x +3 , r + 3);
	
	return;
	
}
