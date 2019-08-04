#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm> 
#include "./card.h"
#include "./deck.h"

using namespace std;
/*********************************************************************
** Function: deck
** Description: initializes deck class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns a shuffled deck
*********************************************************************/ 
Deck::Deck() {
	counter = 0;
	n_cards = 52;
	int suitCount = 0;
	int rankCount = 0;
	for(int i=0; i<52; i++){
		if(rankCount==13){
			rankCount = 0;
			suitCount++;
		}
		cards[i] = Card(rankCount, suitCount);
		rankCount++;
	}

	random_shuffle(cards, cards+52);
}


/*********************************************************************
** Function: deal_card1
** Description: returns a decremented deck
** Parameters: Card
** Pre-Conditions: n/a
** Post-Conditions: returns a decremented deck
*********************************************************************/ 
Card Deck::deal_card1() {
	n_cards--;
	return cards[n_cards];
}
/*********************************************************************
** Function: print_deck
** Description: prints the deck
** Parameters: void
** Pre-Conditions: n/a
** Post-Conditions: returns a printed deck
*********************************************************************/ 
void Deck::print_deck() {

	for(int i = 0; i < 52; i++) {
		cout <<"Card " << i << ": Rank-";
		if(cards[i].get_rank() == 10) {
			cout << "J";
		}
		if(cards[i].get_rank() == 11) {
			cout << "Q";
		}
		if(cards[i].get_rank() == 12) {
			cout << "K12";
		}
		else {
			cout << cards[i].get_rank();
		}
		cout << " Suit-";
		if(cards[i].get_suit() == 0) {
			cout << "S";
		}
		if(cards[i].get_suit() == 1) {
			cout << "D";
		}
		if(cards[i].get_suit() == 2) {
			cout << "C";
		}
		if(cards[i].get_suit() == 3) {
			cout << "H";
		}
		cout << endl;
	}
}

Deck::~Deck() {

	
}