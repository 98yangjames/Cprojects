#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./deck.h"
#include "./card.h"
#include "./hand.h"

class Player {
  private:
    Hand hand;
    Card value;
    int* books;  // Array with ranks for which the player has books.
    int n_books;
    int wantedCard;

  public:
  	Player();
  	Card set_hand(Card);
  	int check_books();
    Card deal_card2();
    bool pass_value(int);
    void replaceCard2(int, int);
    void inputCard(int, int);
    void inputCard2(int, int);
    int how_many_cards2(int);
    int computerMove2();
    void display_hand();
    void replaceBook_Card(int);

    ~Player();
    //void pass_value(int);
  	//void print_hand1(Card);
  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif