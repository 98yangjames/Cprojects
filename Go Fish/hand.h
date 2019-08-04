#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./deck.h"
#include "./card.h"


class Hand {
  private:
  	Card* cards;
    Card value;
    int n_cards;	// Number of cards in the hand.
    int in_hand;  	// Number of cards currently in hand. I guess these are the same thing lol
    int in_hand2;
    int hand;
    int the_rank;
  public:
  	Hand();
  	Card setHand(Card);
  	void printHand(Card);
  	int* handCheck_books();
    int get_in_hand();
    int get_the_rank();
    void set_in_hand(int);
    Card* get_cards();
    int random_in_hand();
    ~Hand();
  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif