#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./deck.h"
#include "./card.h"
#include "./player.h"

#define NUM_CARDS 52

using namespace std;

class Game {
  private:
    Deck cards;
    Card value;
    int wantedCard;
    Player players[2];

  public:
    Game();
    void drawplayer1(Card);
    void drawplayer2(Card);
    void display_hand1();
    void display_hand12();
    void check_books1();
    void check_books2();
    Card deal_card(Card);
    bool check_if_have_card(int);
    bool check_if_have_card2(int);
    bool game_over();
    int userinput();
    void display_hand2();
    void ifPlayer_Card(int);
    void ifPlayer_Card2(int);
    void addCard(int);
    void replaceCard(int, int);
    void replaceCard2(int, int);
    int how_many_cards(int);
    int how_many_cards2(int);
    int computerMove();
    ~Game();



  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif