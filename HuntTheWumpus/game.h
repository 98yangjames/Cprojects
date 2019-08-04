#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "./room.h"
#include "./event.h"
using namespace std;

class Game {
	
private:
	vector <Room*> rooms;
	bool wumpus_killed;
	bool gold_picked;
	bool game_over;
	int playerX;
	int playerY;
	int arrowX;
	int arrowY;
	int playerIndex;
	int playerArrows;
	int user_position;
public:
	Game(int n);
	void print_map(int n);
	void assign_player(int n);
	void assign_event(int n, Event* event);
	bool check_valid_movement(int n);
	bool check_fire(int n,char direction, int distance);
	void fire(int n);
	void movement(string input, int n);
	void check_next_to(int n);
	void event_movements(int n, int playerX, int playerY); 
	bool check_game_over(int n);
	bool check_hit_wumpus(char char_direction, int n);
	int check_distance(char char_direction, int n);
	bool check_gold(int n);
	~Game();
};

#endif