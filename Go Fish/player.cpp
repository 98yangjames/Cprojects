#include <iostream>
#include <time.h>
#include "./player.h"

using namespace std;
/*********************************************************************
** Function: player
** Description: constructor for books
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: initializes
*********************************************************************/ 
Player::Player() {
	n_books = 0;
	books = new int[256];

}
/*********************************************************************
** Function: set_hand
** Description: sets the value of the hand
** Parameters: Card
** Pre-Conditions: requires the value from the previous function and places in hand
** Post-Conditions: puts the card in the hand
*********************************************************************/ 
Card Player::set_hand(Card Value) {
	    
  	hand.setHand(Value);
 	
}
/*********************************************************************
** Function: check_books
** Description: checks if the books are there
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: returns the number of books
*********************************************************************/ 

int Player::check_books() {
	int counter = 0;
	int books_score = 0;
	int temp = 0;
	int* tempbooks = hand.handCheck_books();
	for(int i = n_books; i < n_books+4; i++) {
		temp = books[i];
		books[i] = tempbooks[i];
		cout << books[i];
	}
	replaceBook_Card(temp);
	cout << " Books" << endl;
	delete [] tempbooks;
}
/*********************************************************************
** Function: replaceBook_Card
** Description: should replace the cards that have books with -1
** Parameters: void
** Pre-Conditions: takes in the temp from the check_books function
** Post-Conditions:turns the players hand's cards into -1
*********************************************************************/ 
void Player::replaceBook_Card(int temp) {

	Card* cards = hand.get_cards();
	for(int i = 0; i < hand.get_in_hand(); i++) {
		if(cards[i].get_rank() == temp) {
			cards[i].set_rank(-1);
		}
	}

}
/*********************************************************************
** Function: computerMove2
** Description: chooses random card in the computers hand
** Parameters: int
** Pre-Conditions: takes the cards array
** Post-Conditions: returns the index in the hand
*********************************************************************/ 
int Player::computerMove2() {

	int computernumber, index = 0;
	Card* cards = hand.get_cards();
	int in_hand = hand.get_in_hand();
	in_hand = in_hand - hand.random_in_hand();
	//cout << "In_hand: " << in_hand << endl;
	computernumber = rand() % in_hand + 1;
	index = cards[computernumber].get_rank();
	//cout << "Flag" << computernumber << endl;
	return index;
}
/*********************************************************************
** Function: pass_value
** Description: passes the value through these functions
** Parameters: bool
** Pre-Conditions: needs the wantedValue and the hand array
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Player::pass_value(int wantedValue) {
	bool flag = false;
 //running through hand
	Card* cards = hand.get_cards();
	for(int i = 0; i < hand.get_in_hand(); i++) {
		//cout << "this is your hand: " << cards[i].get_rank() << endl;
		if(cards[i].get_rank() == wantedValue) {
			//cout << "dope you have the card you asked for" << endl;
			flag = true;
			return true;
		}
	}

	return false;
}
/*********************************************************************
** Function: replaceCard2
** Description: replaces the computers cards
** Parameters: void
** Pre-Conditions: needs the computers wanted Card and the number of cards its replacing
** Post-Conditions: sets the hand
*********************************************************************/ 
void Player::replaceCard2(int wantedCard, int number_of_cards) {
	Card* cards = hand.get_cards();
	for(int i = 0; i < hand.get_in_hand(); i++) {
		if(cards[i].get_rank() == wantedCard) {
			cards[i].set_rank(-1);

		}
	}
	hand.set_in_hand(hand.get_in_hand() - number_of_cards);


}
/*********************************************************************
** Function: inputCard
** Description: puts ards into hand
** Parameters: void
** Pre-Conditions: takes wantedCard and number of cards that your putting into hand
** Post-Conditions: sets the hand in that specific player's array
*********************************************************************/ 
void Player::inputCard(int wantedCard, int number_of_cards) {
	//cout << "Flag" <<number_of_cards << endl;
	Card* cards = hand.get_cards(); 
	int total = hand.get_in_hand() + number_of_cards; //get_in_hand is how many you have in your hand
	for(int i = hand.get_in_hand(); i < total; i++) {
		cards[i].set_rank(wantedCard);
	}
	/*cout << "These are your new cards: " << endl;
	for(int i = 0; i < total; i++) {
		cout << " " << cards[i].get_rank();
		cout << "flag"  <<i << endl;
	} */
	hand.set_in_hand(total);

}
/*********************************************************************
** Function: inputCard2
** Description: it is inputCard but without the cout statement.
** Parameters: void
** Pre-Conditions: takes wantedCard and number of cards that your putting in the array
** Post-Conditions: sets the hand in that specific player's array
*********************************************************************/ 
void Player::inputCard2(int wantedCard, int number_of_cards) { //just inputCard without the cout statement for computer

	Card* cards = hand.get_cards(); 
	int total = hand.get_in_hand() + number_of_cards; //get_in_hand is how many you have in your hand
	for(int i = hand.get_in_hand(); i < total; i++) {
		cards[i].set_rank(wantedCard);
	}

}
/*********************************************************************
** Function: display_hand
** Description: function that displays hand
** Parameters: void
** Pre-Conditions: n/a
** Post-Conditions: displays hand
*********************************************************************/ 
void Player::display_hand() {
	Card* cards = hand.get_cards(); 
	for(int i = 0; i < hand.get_in_hand(); i++) {
		if(cards[i].get_rank() != -1) {
			cout << "rank: ";
			if(cards[i].get_rank() == 10) {
			cout << "J (10)";
			}
			else if(cards[i].get_rank() == 11) {
				cout << "Q (11)";
			}
			else if(cards[i].get_rank() == 12) {
				cout << "K (12)";
			}
			else if(cards[i].get_rank() == 0) {
				cout << "A (0)";
			}
			
			else {
				cout << cards[i].get_rank();
			}
			cout << " Suit-";
			if(cards[i].get_suit() == 0) {
				cout << "S";
			}
			else if(cards[i].get_suit() == 1) {
				cout << "D";
			}
			else if(cards[i].get_suit() == 2) {
				cout << "C";
			}
			else if(cards[i].get_suit() == 3) {
				cout << "H";
			}
		}
		cout << endl;
	}
}

/*********************************************************************
** Function: how_many_cards2
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int Player::how_many_cards2(int wantedCard) {
	int counter = 0;
	Card* cards = hand.get_cards();
	for(int i = 0; i < hand.get_in_hand(); i++) {
		if(cards[i].get_rank() == wantedCard) {
			counter++;
		}
	}
	return counter;

}

/*void Player::print_hand1(Card value) {

	hand.printHand(value);
}
*/
/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Player::~Player() {

	delete [] books;
	
}