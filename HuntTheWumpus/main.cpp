#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "./game.h"
#include "./event.h"
#include "./room.h"

using namespace std;

/*********************************************************************
** Program Filename: Wumpus
** Author: James Yang
** Date: 2/14/19
** Description: Plays Wumpus
** Input: user input
** Output: the game
*********************************************************************/
int main(int argc, char *argv[]) {
	srand(time(NULL));
	bool flag = false;
	int n = 0;
	if(argc != 2) {
		cout << "You have to have 2 arguments. Ex: wumpus 5" << endl;
		return 0;
	}
	if(atoi(argv[1]) < 4) {
		cout << "You must have at least size 4" << endl;
		return 0;
	}
	else{
		n = atoi(argv[1]);
	}
	string input, first;

	Game game(n);
	game.assign_player(n);
	game.check_next_to(n);
	game.print_map(n);

	//game.check_next_to(n);
	while(game.check_game_over(n) == false) {
		cout << "[1]. Move\n" 
			 << "[2]. Fire" << endl;
		cout << "Input: ";
		cin >> first;
		if(first == "1") {
			cout << "Input: (WASD)" << endl;
			cin >> input;
			game.movement(input, n);
			game.check_next_to(n);
			game.print_map(n);
		
		}
		if(first == "2") {
			game.fire(n);
		}
	}
	
	
	

}