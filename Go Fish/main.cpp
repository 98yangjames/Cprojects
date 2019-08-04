/*********************************************************************
** Program Filename: gofish
** Author: James Yang
** Date: 2/3/19
** Description: Plays Gofish
** Input: n/a
** Output: game
*********************************************************************/

#include "./game.h"
#include <stdlib.h>
using namespace std;


int main() {
	string input;
	bool input_loop = false;
	int x, wantedCard, wantedComputerCard = 0;
	int turn = 1; 
	srand(time(NULL));
	Game game;
	Card value;
	cout << "\nThis is your hand: \n" << endl;
	for(int i = 0; i < 7; i++) { //initializing the hand for each player
		game.drawplayer1(game.deal_card(value));
	}
	cout << endl;
	for(int i = 0; i < 7; i++) {
		game.drawplayer2(game.deal_card(value));
	}
	game.display_hand2();
	while (game.game_over() == false) {
		
		cout << '\n' <<"Turn: " << turn << endl;
		//game.drawplayer1(game.deal_card(value));
		cout << endl;
		wantedCard = game.userinput();
		game.ifPlayer_Card(wantedCard); //this is the player check function
		//game.display_hand1();
		//game.check_books1(); //checks if player1 got books
		cout << "\nYour turn ended... It's the computer's turn!" << endl;
		wantedComputerCard = game.computerMove();
		game.ifPlayer_Card2(wantedComputerCard);
			//game.display_hand12();
				//game.check_books2(); //checks if player2 got books
		turn++;

	}



	 //check books for player1
	// //check books for player2
	//user input
	



	

}