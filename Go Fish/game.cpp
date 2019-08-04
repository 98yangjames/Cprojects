#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm> 
#include "./game.h"

using namespace std;
/*********************************************************************
** Function: Game
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: initializes coutner, wantedCard, number_of_cards = 0
*********************************************************************/ 
Game::Game() {
	int counter = 0;
    //cards.print_deck();
 	int wantedCard = 0;
 	int number_of_cards = 0;
 
}
/*********************************************************************
** Function: display_hand2
** Description: displays the hands of each player
** Parameters: void
** Pre-Conditions: player must have hand which must have card
** Post-Conditions: displays hand
*********************************************************************/ 
void Game::display_hand2() {

	players[0].display_hand();
	cout << endl;
	//players[1].display_hand(); //comment this out when u actually turn in the assignment

}
/*********************************************************************
** Function: drawplayer1
** Description: draws a card for player 1
** Parameters: void
** Pre-Conditions: you need player which must have hand which must have card
** Post-Conditions: draws a card in the players hand array
*********************************************************************/ 
void Game::drawplayer1(Card value) {

	players[0].set_hand(value);	
}

/*********************************************************************
** Function: drawplayer2
** Description: draws a card for player 2
** Parameters: void
** Pre-Conditions: you need player which must have hand which must have card
** Post-Conditions: draws a card in the players hand array
*********************************************************************/ 
void Game::drawplayer2(Card value) {

	players[1].set_hand(value);
	
}
/*********************************************************************
** Function: deal_card
** Description: gets the value of card for draw card
** Parameters: Card
** Pre-Conditions: Card
** Post-Conditions: returns the object Card
*********************************************************************/ 
Card Game::deal_card(Card value) {

	value = cards.deal_card1();
	//cout <<"THIS IS THE DEAL CARD VALUE: "<< value.get_rank() << endl;
	return value;
	
}
/*********************************************************************
** Function: addCard
** Description: adds a card to the hand array
** Parameters: void
** Pre-Conditions: requires players hand which requires card
** Post-Conditions: puts a new value into the hand array
*********************************************************************/ 
void Game::addCard(int drawnCard) {

	players[0].inputCard(drawnCard, 1);

}
/*********************************************************************
** Function: replaceCard
** Description: replaces the card that the user input
** Parameters: void
** Pre-Conditions: must have players hand which requires card
** Post-Conditions: replaces the card in the players hand array with what the user wanted
*********************************************************************/ 
void Game::replaceCard(int wantedCard, int number_of_cards) {
	players[1].replaceCard2(wantedCard, number_of_cards);
	players[0].inputCard(wantedCard, number_of_cards); /////////////////////
	
}
/*********************************************************************
** Function: replaceCard
** Description: replaces the card that the computer wanted
** Parameters: void
** Pre-Conditions: must have players hand which requires card
** Post-Conditions: replaces the card in the computers hand with the players
*********************************************************************/ 
void Game::replaceCard2(int wantedCard, int number_of_cards) {

	players[0].replaceCard2(wantedCard, number_of_cards);
	players[1].inputCard(wantedCard, number_of_cards);

}
/*********************************************************************
** Function: check_books1
** Description: checks if player1 has books
** Parameters: void
** Pre-Conditions: takes in players which has hand which has cards
** Post-Conditions: displays if they had books or not
*********************************************************************/ 
void Game::check_books1() {
	cout << "\nThis is the books for player 1: " << endl;
	players[0].check_books();
	cout << endl;
}
/*********************************************************************
** Function: check_books2
** Description: checks if player2 has books
** Parameters: void
** Pre-Conditions: takes in players which has hand which has cards
** Post-Conditions: displays if they had books or not
*********************************************************************/ 
void Game::check_books2() {
	cout << "\nThis is the books for player 2: " << endl;
	players[1].check_books();
	cout << endl;
}
/*********************************************************************
** Function: game_over
** Description: adds up the number of books to see if the game is over
** Parameters: bool
** Pre-Conditions: takes in check_books of both players and adds to 13
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Game::game_over() {
	if(players[0].check_books() + players[1].check_books() == 13) {
		if(players[0].check_books() > players[1].check_books()) {
			cout << "You Win!" << endl;
			return true;
		}
		if(players[1].check_books() > players[1].check_books()) {
			cout << "Computer wins!" << endl;
			return true;
		}
		
	}
	return false;
}
/*********************************************************************
** Function: check_if_have_card
** Description: checks if the player has the card
** Parameters: bool
** Pre-Conditions: has players which has hand which has card
** Post-Conditions: returns true or false
*********************************************************************/
bool Game::check_if_have_card(int wantedCard) {
	players[0].pass_value(wantedCard);
	//
}
/*********************************************************************
** Function: check_if_have_card2
** Description: checks if the computer has the card
** Parameters: bool
** Pre-Conditions: has players which has hand which has card
** Post-Conditions: returns true or false
*********************************************************************/
bool Game::check_if_have_card2(int wantedCard) {
	players[1].pass_value(wantedCard);
}
/*********************************************************************
** Function: how_many_cards
** Description: checks how many cards the player has
** Parameters: int
** Pre-Conditions: players which has hands which has cards
** Post-Conditions: returns int
*********************************************************************/
int Game::how_many_cards(int wantedCard) {

	players[1].how_many_cards2(wantedCard);

}
/*********************************************************************
** Function: how_many_cards2
** Description: checks how many cards the player has
** Parameters: int
** Pre-Conditions: players which has hands which has cards
** Post-Conditions: returns int
*********************************************************************/
int Game::how_many_cards2(int wantedCard) {

	players[0].how_many_cards2(wantedCard);
}
/*********************************************************************
** Function: computerMove
** Description: easy A.I move that randomizes which card they want
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: gives random number in their array
*********************************************************************/
int Game::computerMove() {
	bool flag = false;
	int computernumber = 0;
	while (flag == false) {
	computernumber = players[1].computerMove2();
		if(computernumber != -1) {
			flag = true;
		}
	}
	return computernumber;
}
/*********************************************************************
** Function: display_hand1
** Description: displays the hand
** Parameters: void
** Pre-Conditions: players which has hands which has cards
** Post-Conditions: displays the cards
*********************************************************************/
void Game::display_hand1() {
	players[0].display_hand();
}
/*********************************************************************
** Function: display_hand12
** Description: displays the hand
** Parameters: void
** Pre-Conditions: players which has hands which has cards
** Post-Conditions: displays the cards
*********************************************************************/
void Game::display_hand12() {
	players[1].display_hand();

}
/*********************************************************************
** Function: ifPlayer_Card
** Description: checks if the user input has the right card and then returns whether to replace or not
** Parameters: void
** Pre-Conditions: user input, players cards, hands, card
** Post-Conditions: does what the functions do within and then moves on
*********************************************************************/

void Game::ifPlayer_Card(int wantedCard) {
	//int previous = 0; 
	int flag_number = 0;
	bool flag = false;
	while(flag == false) {
		if(check_if_have_card(wantedCard) && check_if_have_card2(wantedCard) == true) {
			//this is where you give and delete
			cout << "YOU BOTH HAVE THIS CARD: " << endl;
			replaceCard(wantedCard, how_many_cards(wantedCard));
			display_hand1();
			cout << "\nEnter a card value that you want to steal from the opponent again!" << endl;
			cin >> wantedCard;

		}
		if(check_if_have_card(wantedCard) == true && check_if_have_card2(wantedCard) == false) {
			string input;
			cout << "go fish! (says the computer)" << endl;
			cout << "[1]. Draw a card" << endl;
			cout << "Your input: ";
			cin >> input;
			if(input == "1") {
				if(input == "1") {
					cout << "You picked up a: ";
					drawplayer1(deal_card(value));
					cout << endl;
					flag_number++;
					flag = true;
				}
			}
		}
		if(check_if_have_card(wantedCard) == false) {
			cout << "You don't have that card... try again: " << endl;
			cin >> wantedCard;
		}

	}
	if(flag_number >=1 ) {
		check_books1();
		players[0].display_hand();
	}

}
/*********************************************************************
** Function: ifPlayer_Card2
** Description: checks for the computers card input verifications
** Parameters: void
** Pre-Conditions: needs wantedCard, players cards, and card
** Post-Conditions: returns the function inputs
*********************************************************************/
void Game::ifPlayer_Card2(int wantedCard) {
	bool flag2 = false;
	int flag_number2 = 0;
	while(flag2 == false) {
		if(check_if_have_card2(wantedCard) == true && check_if_have_card(wantedCard) == false) {
			cout << "Computer asked for: " << wantedCard << endl;
			cout << "Uh-oh, go fish! (you say virtually)" << endl;
			flag2 = true;
			flag_number2 = 0;
			check_books1();
		}

		if(check_if_have_card(wantedCard) && check_if_have_card2(wantedCard) == true) {
				cout << "Computer asked for: " << wantedCard << "\n" <<endl;
				
				
				cout << "\n Unfortunately, you have this card so you'll have to give it up" << endl;
				replaceCard2(wantedCard, how_many_cards2(wantedCard));
				flag2 = true;
				flag_number2 += 1;
		}

		if(flag_number2 >= 1) {
			players[1].display_hand();
			check_books2();
		}
	}

}/*********************************************************************
** Function: userinput
** Description: gets wantedCard
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: returns int
*********************************************************************/
int Game::userinput() {

	int wantedCard;
	cout << "Enter a card value that you want to steal from the opponent" << endl;
	cin >> wantedCard;
	return wantedCard;

}

Game::~Game() {

	//doesn't need to delete anything

}
