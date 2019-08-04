#include <iostream>
#include "./game.h"
#include "./event.h"
#include "./room.h"
#include "./wumpus.h"
#include "./bats.h"
#include "./gold.h"
#include "./pits.h"
#include "./nothing.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*********************************************************************
** Function: Game
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/
Game::Game(int n) {
	game_over = false;
	gold_picked = false;
	wumpus_killed = false;
	playerX = 0;
	playerY = 0;
	arrowX = 0;
	arrowY = 0;
	playerIndex = 0;
	playerArrows = 3;
	user_position = 0;

	for(int i = 0; i < n*n; i++) {
		rooms.push_back(new Room);
	}
	assign_event(n, new Wumpus);
	assign_event(n, new Bats);
	assign_event(n, new Bats);
	assign_event(n, new Pits);
	assign_event(n, new Pits);
	assign_event(n, new Gold);
	for(int i = 0; i < (n*n) - 6; i++) {
		assign_event(n, new Nothing);
	}


}
/*********************************************************************
** Function: print_map
** Description: prints the map
** Parameters: takes in the users n
** Pre-Conditions: int n
** Post-Conditions: a map
*********************************************************************/ 
void Game::print_map(int n) {
	int counter = 0;
	for(int i = 0 ; i < n; i++) {
		cout << "+";
		for(int j = 0; j < n; j++) {
			cout << "---+";
		}
		cout << endl;
		for(int k = 0; k < 3; k++) {
			cout << "|";
			for(int l = 0; l < n; l++) {
				if(k == 1 && i == playerY && l == playerX){
					cout << " U |";
				}
				else{
					cout << "   |";
				}
			}
			cout << endl;
		}
	}
	cout << "+";
	for(int j = 0; j < n; j++) {
		cout << "---+";
	}
	cout << endl;
}

/*********************************************************************
** Function: assign_player
** Description: assigns the player a location
** Parameters: the size int
** Pre-Conditions: the size int
** Post-Conditions: returns the players position
*********************************************************************/ 
void Game::assign_player(int n) {
	int total = n * n;
	int random = rand() % total;
	int players_position = total - random;
	while(rooms[random]->get_event()->get_event_name() != "nothing") {
		random = rand() % total;
	}
	players_position = total - random;
	playerX = players_position % n;
	playerY = players_position / n;
	playerIndex = playerX + playerY*n;
	//cout << "This is where you are: " << playerIndex << endl;
	user_position = playerIndex;

}
/*********************************************************************
** Function: assign_event
** Description: assigns an event
** Parameters: int, event*
** Pre-Conditions: int, event*
** Post-Conditions: returns an event
*********************************************************************/ 
void Game::assign_event(int n, Event* event){
	int counter = 0;
	int total = n * n;
	int random = rand() % total;
	while (rooms[random]->get_event() != NULL) {
		random = rand() % total;
	}
	rooms[random]->set_event(event);
	//cout << "This is random: " << random << endl;
}



/*********************************************************************
** Function: check_valid_movement
** Description: checks if your movement is valid
** Parameters: int n
** Pre-Conditions: int n
** Post-Conditions: returns bool
*********************************************************************/ 
bool Game::check_valid_movement(int n) {
	//cout << "playerX " << playerX << endl;
	if(playerX < n && playerY < n && playerX >= 0 && playerY >=0) {
		return true;
	}
	return false;	

}
/*********************************************************************
** Function: check_fire
** Description: checks if your fire input is valid
** Parameters: int, char, int
** Pre-Conditions: int, char, int
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Game::check_fire(int n,char direction, int distance) {

	if(direction == 'w') {
		if(playerY - distance > -1) {
			return true;
		}
		return false;
	}

	if(direction == 'a') {
		if(playerX - distance > -1) {
		
			return true;
		}
		return false;
	}
	if(direction == 's') {
		if(playerY + distance < n) {
			return true;
		}
		return false;
	}
	if(direction == 'd') {
		if(playerX + distance < n) {
			return true;
		}
		return false;
	}

}
/*********************************************************************
** Function:check_distance
** Description: checks the distance your fire can go
** Parameters: char, int
** Pre-Conditions: char, int
** Post-Conditions: returns a distance
*********************************************************************/ 
int Game::check_distance(char char_direction, int n) {
	int distance = 3;
	if(char_direction == 'w') {
		while(distance > 0) {
			if(playerY - distance < 0) {
				distance--;
			}
			else {
				break;
			}
		}
	}
	if(char_direction == 'a') {
		while(distance > 0) {
			if(playerX - distance < 0) {
				distance--;
			}
			else {
				break;
			}
		}
	}
	if(char_direction == 's') {
		while(distance > 0) {
			if(playerY + distance >= n) {
				distance--;
			}
			else {
				break;
			}
		}
	}
	if(char_direction == 'd') {
		while(distance > 0) {
			if(playerX + distance >= n) {
				distance--;
			}
			else {
				break;
			}
		}
	}



	return distance;

}
/*********************************************************************
** Function: check_hit_wumpus
** Description: checks if your fire has hit the wumpus
** Parameters: char, int
** Pre-Conditions: char, int
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Game::check_hit_wumpus(char char_direction, int n) {
	int distance = 0;
	int temp_playerY = 0;
	int temp_playerX = 0;
	if(char_direction == 'w') {
		distance = check_distance(char_direction, n);
		// cout << "THIS IS DISTANCE " << distance << endl; 
		while(distance != 0) {
			temp_playerY = playerY - distance;
			// cout << "temp_playerY " << temp_playerY << endl;
			if(rooms[temp_playerY*n + playerX]->get_event()->get_event_name() == "wumpus") {
				cout << "You hit the wumpus" << endl;
				wumpus_killed = true;
				rooms[temp_playerY*n + playerX]->set_event(new Nothing);
				return true;
			}
			distance--;
		}
		return false;
	}

	if(char_direction == 'a') {
			distance = check_distance(char_direction, n); 
			// cout << "THIS IS DISTANCE " << distance << endl;
			while(distance != 0) {
				temp_playerX = playerX - distance;
				// cout << "TEMP_PLAYERX " << temp_playerX << endl;
				if(rooms[playerY*n + temp_playerX]->get_event()->get_event_name() == "wumpus") {
					cout << "You hit the wumpus" << endl;
					rooms[playerY*n + temp_playerX]->set_event(new Nothing);
					return true;
				}
				distance--;
			}
			return false;
	}
	if(char_direction == 's') {
		distance = check_distance(char_direction, n);
		// cout << "THIS IS DISTANCE " << distance << endl; 
		while(distance != 0) {
			temp_playerY = playerY + distance;
			//cout << "temp_playerY (aka where its supposed to shoot)" << temp_playerY << endl;
			if(rooms[temp_playerY*n + playerX]->get_event()->get_event_name() == "wumpus") {
				cout << "You hit the wumpus" << endl;
				wumpus_killed = true;
				rooms[temp_playerY*n + playerX]->set_event(new Nothing);
				return true;
			}
			distance--;
		}
		return false;
	}
	if(char_direction == 'd') {
			distance = check_distance(char_direction, n); 
			// cout << "THIS IS DISTANCE " << distance << endl;
			while(distance != 0) {
				temp_playerX = playerX + distance;
				//cout << "TEMP_PLAYERX " << temp_playerX << endl;
				if(rooms[playerY*n + temp_playerX]->get_event()->get_event_name() == "wumpus") {
					cout << "You hit the wumpus" << endl;
					rooms[playerY*n + temp_playerX]->set_event(new Nothing);
					return true;
				}
				distance--;
			}
			return false;
	}

}
/*********************************************************************
** Function: fire
** Description: fires the shot
** Parameters: char, int
** Pre-Conditions: char, int
** Post-Conditions: returns true or false
*********************************************************************/ 
void Game::fire(int n) {
	bool flag = false;
	char char_direction;
	string direction;
	while(flag == false) {
		cout << "Which direction? (wasd)" << endl;
		cin >> direction;
		if(direction == "w")  {
			char_direction = 'w';
			flag = true;
		}
		if(direction == "a") {
			char_direction = 'a';
			flag = true;
		}
		if(direction == "s") {
			char_direction = 's';
			flag = true;
		}
		if(direction == "d") {
			char_direction = 'd';
			flag = true;
		}
	}
	if(check_hit_wumpus(char_direction, n) == false) {
		if(playerArrows != 0) {
			cout << "You missed the wumpus!" << endl;
			playerArrows--;
			cout << "You now have: " << playerArrows << " arrows" << endl;
			int random = rand() % 4 + 1;
			if(random == 1) {
				cout << "You woke the wumpus, he's now moving to another random location" << endl;
			}
			if(random != 1) {
				cout << "The wumpus didn't wake up... you got lucky" << endl;
			}
		}
	}
	if(playerArrows == 0 && wumpus_killed == true) {
		cout << "You don't need to shoot anymore!" << endl;
	}
}
/*********************************************************************
** Function: check_gold
** Description: checks if you have the gold
** Parameters: int n
** Pre-Conditions: int n
** Post-Conditions: returns nothing
*********************************************************************/ 
bool Game::check_gold(int n) {

	if(rooms[playerY*n + playerX]->get_event()->get_event_name() == "gold") {
		gold_picked = true;
		rooms[playerY*n + playerX]->set_event(new Nothing);
		return true;
	}
	return false;

}

/*********************************************************************
** Function: movement
** Description: moves your person
** Parameters: string input, int n
** Pre-Conditions: string input, int n
** Post-Conditions: returns nothing
*********************************************************************/ 
void Game::movement(string input, int n) {
	bool flag = false;
	int temp_playerX = playerX;
	int distance = 0;
	int temp_playerY = playerY;
	while(flag == false) {
		if(input == "w" || input == "W") {
			playerY = playerY - 1;
			if(check_gold(n) == true) {
				cout << "You picked up the gold!" << endl;
			}	
		}
		if(input == "a" || input == "A") {
			playerX = playerX - 1;
			if(check_gold(n) == true) {
				cout << "You picked up the gold!" << endl;
			}
		}
		if(input == "d" || input == "D") {
			playerX = playerX + 1;
			if(check_gold(n) == true) {
				cout << "You picked up the gold!" << endl;
			}
		}
		if(input == "s" || input == "S"){
			playerY = playerY + 1;
			if(check_gold(n) == true) {
				cout << "You picked up the gold!" << endl;
			}
		}
		if(check_valid_movement(n) == false) {
			playerY = temp_playerY;
			playerX = temp_playerX;
			cout << "You can't do that... try again" << endl;
			cin >> input;	
		}
		else {
			flag = true;
		}
	}
	event_movements(n, playerX, playerY);
	

	

}
/*********************************************************************
** Function: check_next_to
** Description: checks whats next to the user
** Parameters: int n
** Pre-Conditions: int n
** Post-Conditions: returns nothing
*********************************************************************/ 
void Game::check_next_to(int n) {
	int aboveY= playerY + 1;
	int belowY = playerY -1;
	int aboveX = playerX + 1;
	int belowX = playerX - 1;
	Gold gold;
	Wumpus wumpus;
	Pits pits;

	if((playerY + 1) >= n) {
		aboveY = playerY;
	}
	if((playerY - 1) < 0) {
		belowY = playerY;
	}
	if((playerX + 1) >= n) {
		aboveX = playerX;
	}
	if((playerX - 1) < 0) {
		belowX = playerX;
	}

	// cout << "aboveY: " << aboveY << endl;
	if(rooms[aboveY*n + playerX]->get_event()->get_event_name() == "gold" || rooms[belowY*n + playerX]->get_event()->get_event_name() == "gold") {
		gold.percept();
	}
	if(rooms[playerY*n + aboveX]->get_event()->get_event_name() == "gold" || rooms[playerY*n + belowX]->get_event()->get_event_name() == "gold") {
		gold.percept();
	}
	if((rooms[aboveY*n + playerX])->get_event()->get_event_name() == "wumpus" || rooms[belowY*n + playerX]->get_event()->get_event_name() == "wumpus") {
		wumpus.percept();
	}
	if((rooms[playerY*n + aboveX])->get_event()->get_event_name() == "wumpus" || rooms[playerY*n + belowX]->get_event()->get_event_name() == "wumpus") {
		wumpus.percept();
	}
	if((rooms[aboveY*n + playerX])->get_event()->get_event_name() == "pits" || rooms[belowY*n + playerX]->get_event()->get_event_name() == "pits") {
		pits.percept();
	}
	if((rooms[playerY*n + aboveX])->get_event()->get_event_name() == "pits" || rooms[playerY*n + belowX]->get_event()->get_event_name() == "pits") {
		pits.percept();
	}

}

	
/*********************************************************************
** Function: event_movements
** Description: plays the movement 
** Parameters: int, int, int
** Pre-Conditions: int, int, int
** Post-Conditions: returns nothing
*********************************************************************/ 
void Game::event_movements(int n, int playerX, int playerY) {
	Bats bats;
	Pits pits;
	Gold gold;
	Wumpus wumpus;
	//cout << "EVENT NAME:" <<rooms[playerY*n + playerX]->get_event()->get_event_name() << endl;

	if(rooms[playerY*n + playerX]->get_event()->get_event_name() == "pits") {
		pits.encounter();
		game_over = true;
	}
	if(rooms[playerY*n + playerX]->get_event()->get_event_name() == "bats") {

		bats.encounter();
		assign_player(n);
	}
	if(rooms[playerY*n + playerX]->get_event()->get_event_name() == "wumpus") {
		wumpus.encounter();
		cout << "You're now dead" << endl;
		game_over = true;
	}
	if(rooms[playerY*n + playerX]->get_event()->get_event_name() == "gold") {
		cout << "ITS IN HERE:" << endl;
		gold.encounter();
	}
	if(rooms[playerY*n + playerX]->get_event()->get_event_name() == "nothing") {
		
	}


}
/*********************************************************************
** Function: check_game_over
** Description: checks if the game is over
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Game::check_game_over(int n) {

	if(game_over == true) {
		return true;
	}
	if(wumpus_killed == true && gold_picked == true) {
		cout << "player's index " << playerY*n + playerX << endl;
		cout << "To win, get to your location! " << user_position << endl;
		if(user_position == playerY*n + playerX) {
			cout << "YOU WIN!!" << endl;
			return true;
		}
		
	}
	if(playerArrows == 0 && wumpus_killed == false) {
		cout << "You didn't kill the Wumpus in time" << endl;
		return true;
	}

	return false;

}
/*********************************************************************
** Function: ~Game()
** Description: deconstruct
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: deconstructs
*********************************************************************/ 
Game::~Game() {

	for(auto &room : rooms) {
		delete room;
	}

}