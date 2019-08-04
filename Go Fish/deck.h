#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm> 
#include "./card.h"



class Deck {
  private:
    Card cards[52];
    int n_cards; // Number of cards remaining in the deck.
    int counter;
  public:
  	Deck(); //shuffles deck
  	//int deal_rank(); //picks out a single card, returns value
  	//int deal_suit();
    Card deal_card1();
  	void print_deck(); //prints deck (testing)
    ~Deck();
  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif