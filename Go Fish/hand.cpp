#include <iostream>
#include "./card.h"
#include "./hand.h"

using namespace std;

Hand::Hand() {
	hand = 0;
	in_hand = 0; //how many cards the player has
	in_hand2 = 0;
	n_cards = 52;
	cards = new Card[n_cards]; //cards = the players Hand
	the_rank = 0;
}

Card Hand::setHand(Card value) {
	cards[in_hand] = value;
	//cards[in_hand].print_cards(value);
	 cards[8].set_rank(1); //this is for my testing of books (works)
	 cards[9].set_rank(1);
	 cards[10].set_rank(1);
	 cards[11].set_rank(1);
	in_hand++;
}

void Hand::set_in_hand(int value) {

	in_hand = value;

}

Card* Hand::get_cards() {
	return this->cards;
}


int* Hand::handCheck_books() {

	int* tempbook;
	tempbook = new int[4];
	int c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13 = 0;
	for(int i = 0; i < in_hand; i++) {
		if(cards[i].get_rank() == 0) {
			c0++;
		}
		if(cards[i].get_rank() == 1) {

			c1++;
		}
		if(cards[i].get_rank() == 2) {
			c2++;
		}
		if(cards[i].get_rank() == 3) {
			c3++;
		}
		if(cards[i].get_rank() == 4) {
			c4++;
		}
		if(cards[i].get_rank() == 5) {
			c5++;
		}
		if(cards[i].get_rank() == 6) {
			c6++;
		}
		if(cards[i].get_rank() == 7) {
			c7++;
		}
		if(cards[i].get_rank() == 8) {
			c8++;
		}
		if(cards[i].get_rank() == 9) {
			c9++;
		}
		if(cards[i].get_rank() == 10) {
			c10++;
		}
		if(cards[i].get_rank() == 11) {
			c11++;
		}
		if(cards[i].get_rank() == 12) {
			c12++;
		}
		if(cards[i].get_rank() == 13) {
			c13++;
		}
	}
	if(c0 == 4) {
		for(int j= 0; j< 4; j++) {
			tempbook[j] = 0;
			cout << "FLAG" << endl;
		}
	}
	if(c1 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 1;
			cout << "FLAG" << endl;
		}
	}
	if(c2 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 2;
			cout << "FLAG" << endl;
		}
	}
	if(c3 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 3;
			cout << "FLAG" << endl;
		}
	}
	if(c4 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 4;
			cout << "FLAG" << endl;
		}
	}
	if(c5 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 5;
			cout << "FLAG" << endl;
		}
	}
	if(c6 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 6;
			cout << "FLAG" << endl;
		}
	}
	if(c7 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 7;
			cout << "FLAG" << endl;
		}
	}
	if(c8 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 8;
			cout << "FLAG" << endl;
		}
	}
	if(c9 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 9;
			cout << "FLAG" << endl;
		}
	}
	if(c10 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 10;
			cout << "FLAG" << endl;
		}
	}
	if(c11== 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 11;
			cout << "FLAG" << endl;
		}
	}
	if(c12 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 12;
			cout << "FLAG" << endl;
		}
	}
	if(c13 == 4) {
		for(int j = 0; j < 4; j++) {
			tempbook[j] = 13;
			cout << "FLAG" << endl;
		}
	}

	return tempbook;
}

void Hand::printHand(Card value) {

	cout << value.get_rank() << endl;
}

int Hand::get_in_hand() {

	hand = in_hand;
	return hand;
}

int Hand::random_in_hand() {

	int counter = 0;
	for(int i = 0; i < 52; i++) {
		if(cards[i].get_rank() == -1) {
			counter++;
		}
	}
	return counter;
}

int Hand::get_the_rank() {
	the_rank = cards[in_hand].get_rank(); 
}

Hand::~Hand() {

	delete [] cards;
}