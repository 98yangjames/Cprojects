#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm> 
#include "./card.h"

using namespace std;
/*********************************************************************
** Function: Card
** Description: sets Card values to 0
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns 0
*********************************************************************/ 
Card::Card() {
	rank = 0;
	suit = 0;
}
/*********************************************************************
** Function: Card
** Description: takes in the rank and suit
** Parameters: int rank, int suit
** Pre-Conditions: int rank and int suit
** Post-Conditions: returns this rank and this suit
*********************************************************************/ 
Card::Card(int rank, int suit) {

	this->rank = rank;
	this->suit = suit;
}
/*********************************************************************
** Function: get_rank
** Description: gets the rank
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: returns rank
*********************************************************************/ 
int Card::get_rank() {
	return rank;
}
/*********************************************************************
** Function: get_suit
** Description: gets the suit
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: returns suit
*********************************************************************/ 
int Card::get_suit() {
	return suit;
}
/*********************************************************************
** Function: set_rank
** Description: sets the rank
** Parameters: void
** Pre-Conditions: int num
** Post-Conditions: sets the rank
*********************************************************************/ 
void Card::set_rank(int num) {
	rank = num;

}
/*********************************************************************
** Function: set_suit
** Description: sets the suit
** Parameters: void
** Pre-Conditions: int bum
** Post-Conditions: changes the suit
*********************************************************************/ 
void Card::set_suit(int bum) {
	 suit = bum;
	 
}
/*********************************************************************
** Function: print_cards
** Description: prints the cards
** Parameters: void
** Pre-Conditions: Card value
** Post-Conditions: prints the cards
*********************************************************************/ 
void Card::print_cards(Card value) {
	cout << value.get_rank() << " ";
}

Card::~Card() {

	
}
