#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdlib.h>
#include <time.h>



class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public:
  	Card();
  	Card(int,int);
  	int get_rank(); //treturning value functions (accessors)
  	int get_suit();
  	void set_rank(int);
  	void set_suit(int); // changing functions (mutators)
  	void print_cards(Card);
    ~Card();
  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif
