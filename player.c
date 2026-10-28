#include <stdio.h>
#include "main.h"

int customRoll(){ //allows for custom roll choice
	int valid = 0;
	int r;
	while (valid == 0 ) {
		printf("please enter your chosen pin: ");
    if (scanf("%d", &r) != 1) {
        
        while (getchar() != '\n'){;} // clears bad input
		
		printf("invalid \n");
    }
	else{
		if (r >=3 && r <= 11){
		valid = 1;
		return r -2;}
		printf("invalid \n");
	}
    
}
return r -2;
	
}

void takeTurn(sBoard board[9]){
	printf("players turn \n ");
	char in;
	int valid = 0;
	printf("press r to roll: ");
	scanf("%s", &in);
	if (in == 'r'){
		valid = 1;
	}
	while (valid == 0){
		printf("Invalid -- press r to roll: ");
		scanf("%s", &in);
		if (in == 'r'){
			valid = 1;
		}	
	}
	valid =0;
	int player =1;
	int r;
	int boxChoice;
	
	r = rollDice();
	int two = 0;
	printf(" your roll is: %d \n", r+2);
	
	//check if role is valid for available pins

	
	if (r ==10){ //checks if player rolled a 12
		
		r = customRoll();
		
	}
	else if( r ==0){ //checks if player rolled a 2
	two = 1;
	player = 0;
	r = customRoll(); //sets custom pin choice
	}
	
	r -=1;
	for(int a = 0; a < 9; a++){ //checks if board has any available slots for roll
		if(board[a].board[r] !=0){ //if slot isnt available
			if(a ==8){	//if checked all possible slots
				printf("full board for current roll"); 
				return;
			}
		}
		else{a += 8;} //if finds an available pin then exit loop
	
	}
	
	
	while (valid == 0 ) {
		printf("Please enter a digit between 3 and 11 to choose a box: ");
    if (scanf("%d", &boxChoice) != 1) {
        
        while (getchar() != '\n'); // removes incorrect input
    }
	else{
		 if(boxChoice >= 3 && boxChoice <=11){ //checks if boxchoice is valid
			 
				valid = checkMove(board, r, boxChoice -3);  
				if (two == 1 && board[boxChoice -3].won ==0){ //if rolled a 2 and box hasnt been won then choice is valid
					valid = 1;
			 }
		}
	}
    
}
	boxChoice -=3; 
	
	doMove(board, player, r , boxChoice); 
	
	if(checkCanWin(board, player, boxChoice, r) ==1 && two == 0){ //checks if player can win a box
		fillBox( board, boxChoice, player);
	}
	
	
}