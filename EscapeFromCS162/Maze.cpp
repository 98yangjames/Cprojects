#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "./Maze.h"
#include "./Wall.h"
#include "./OpenSpace.h"
#include "./MazeLocation.h"
#include "./IntrepidStudent.h"
#include "./Ta.h"

using namespace std;
/*********************************************************************
** Function: Maze
** Description: Construct the maze
** Parameters: takes in the maze_height, maze_width, levels
** Pre-Conditions: int, int, int
** Post-Conditions: n/a
*********************************************************************/ 
Maze::Maze(int Amaze_height, int Amaze_width, int alevels) {  
	current_level = 0;
	loadHeight = 0;
	loadWidth = 0;
	character;
	levels = alevels;
	maze_height = Amaze_height;
	maze_width = Amaze_width;
	personX1 = 0;
	personY1 = 0;
	personX2 = 0;
	personY2 = 0;
	personX3 = 0;
	personY3 = 0;
	endX1 = 0;
	endY1 = 0;
	endX2 = 0;
	endY2 = 0;
	endX3 = 0;
	endY3 = 0;
	taX1 = 0;
	taY1 = 0;
	taX2 = 0;
	taY2 = 0;
	startX1 = 0;
	startY1 = 0;
	startX2 = 0;
	startY2 = 0;
	startX3 = 0;
	startY3 = 0;
	skillX1 = 0;
	skillY1 = 0;
	skillX2 = 0;
	skillY2 = 0;
	skillX3 = 0;
	skillY3 = 0;
	counter = 10;
	caught = false;
	caught2 = false;
	caught3 = false;
	locations.resize(maze_height*levels);
	for(int i = 0; i < maze_height*levels; i++) {
		locations[i].resize(maze_width);
		//locations.push_back(vector<MazeLocation*>(maze_width));
	}
	

}

/*********************************************************************
** Function: check_valid
** Description: checks if the movement is valid
** Parameters: int x, int y
** Pre-Conditions: int, int
** Post-Conditions: returns bool
*********************************************************************/ 
bool Maze::check_valid(int x, int y) {

	if(locations[x][y]->get_display_character() != '#') {
		return true;
	}
	return false;
}
/*********************************************************************
** Function: check_valid_ta
** Description: checks if the ta movement is valid
** Parameters: int x, int y
** Pre-Conditions: int, int
** Post-Conditions: returns bool
*********************************************************************/ 
bool Maze::check_valid_ta(int x, int y) {

	if(locations[x][y]->get_display_character() != '#' && locations[x][y]->get_display_character() != 'T') {
		return true;
	}
	return false;
}
/*********************************************************************
** Function: set_location_maze
** Description: sets the location of the maze to the character
** Parameters: int, int, char, int
** Pre-Conditions: int, int, char, int
** Post-Conditions: returns a char in the location
*********************************************************************/ 
void Maze::set_location_maze(int x, int y, char aChar, int level) {

	// cout << "THIS CHARACTER: " << aChar << endl;

	if(aChar == '#') {
		locations[x][y] = new Wall();
	}

	if(aChar == '@') {
		OpenSpace* start = new OpenSpace;
		start->set_is_start(true);
		if(level == 1) {
			startX1 = x;
			startY1 = y;
			personX1 = x;
			personY1 = y;
			// cout << "THIS IS PERSONX " << personX1 << endl;
			// cout << "THIS IS PERSONY " << personY1 << endl;
			locations[x][y] = start;
		}
		if(level == 2) {
			startX2 = x;
			startY2 = y;
			personX1 = startX2;
			personY1 = startY2;
			// cout << "THIS IS PERSONX " << personX2 << endl;
			// cout << "THIS IS PERSONY " << personY2 << endl;
			locations[x][y] = start;
		}
		if(level == 3) {
			startX3 = x;
			startY3 = y;
			personX1 = startX3;
			personY1 = startY3;
			// cout << "THIS IS PERSONX " << personX3 << endl;
			// cout << "THIS IS PERSONY " << personY3 << endl;
			locations[x][y] = start;
		}
		//delete start;

	}
	if(aChar == '^') {
		OpenSpace* end = new OpenSpace;
		
		end->set_is_end(true);
		locations[x][y] = end;

		if(level == 1) {
			endX1 = x;
			endY1 = y;
			// cout << "endX1: " << endX1 << endl;
			// cout << "endY1: " << endY1 << endl;
			
			locations[x][y] = end;
			
		}
		if(level == 2) {
			endX2 = x;
			endY2 = y;
			// cout << "endX2: " << endX2 << endl;
			// cout << "endY2: " << endY2 << endl;
			
			locations[x][y] = end;
			
		}
		//delete end;

	}
	if(aChar == '%') {
		OpenSpace* instructor = new OpenSpace;
		instructor->set_is_instructor(true);
		endX3 = x;
		endY3 = y;
		// cout << "endX3: " << endX3 << endl;
		// cout << "endY3: " << endY3 << endl;
		locations[x][y] = instructor;
		delete instructor;

	}

	if(aChar == ' ') {
		locations[x][y] = new OpenSpace();

	}
	
}
/*********************************************************************
** Function: set_location_maze_ta1
** Description: sets the location of the maze ta1
** Parameters: int level
** Pre-Conditions: int
** Post-Conditions: location of the ta
*********************************************************************/ 
void Maze::set_location_maze_ta1(int alevel) {

	srand(time(NULL));
	int level;
	level = alevel -1;
	int random_x;
	int random_y;
	bool check = false;
	for(int i = 0; i < maze_height*level; i++) {
		for(int j = 0; j < maze_width; j++) {
			if(locations[i][j]->get_display_character() == 'T') {
				locations[i][j]->set_display_character(' ');
			}
		}
	}
	while(check == false) {
		random_x = rand() % maze_height + maze_height*level;
		random_y = rand() % maze_width;
		if(locations[random_x][random_y]->get_display_character() == ' ') {
			OpenSpace* ta = new OpenSpace;
			
			ta->set_has_ta(true);
			taX1 = random_x;
			taY1 = random_y;
			check = true;
			cout << "taX1 in function: " << taX1 << endl;
			cout << "taY1 in function: " << taY1 << endl;
			delete ta;
		}
		
	}


	
}
/*********************************************************************
** Function: set_location_maze_ta2
** Description: sets the location of the second ta
** Parameters: int alevel
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_location_maze_ta2(int alevel) {
	srand(time(NULL));
	int level;
	level = alevel -1;
	int random_x;
	int random_y;
	bool check = false;

	

	while(check == false) {
		random_x = rand() % maze_height + maze_height*level;
		random_y = rand() % maze_width;

		if(locations[random_x][random_y]->get_display_character() == ' ') {
			OpenSpace* ta2 = new OpenSpace;
			
			ta2->set_has_ta(true);
			taX2 = random_x;
			taY2 = random_y;
			check = true;
			if(taX1 == taX2 || taY1 == taY2) {
				check = false;
			}
			// cout << "taX2 in function: " << taX2 << endl;
			// cout << "taY2 in function: " << taY2 << endl;
			delete ta2;
		}
	}


	
}
/*********************************************************************
** Function: set_location_programming_skill1
** Description: sets the location of the first programming skill
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_location_programming_skill1(int alevel) {
	int level;
	level = alevel -1;
	bool check = false;
	int random_x;
	int random_y;
	while(check == false) {
		random_x = rand() % maze_height + maze_height*level;
		random_y = rand() % maze_width;
		if(locations[random_x][random_y]->get_display_character() == ' ') {
			OpenSpace* skill = new OpenSpace;
			skill->set_has_programming_skill(true);
			skillX1 = random_x;
			skillY1 = random_y;	
			// cout << "skillX1: " << skillX1 << endl;
			// cout << "skillY1: " << skillY1 << endl;
			check = true;
			delete skill;
		}
	}
	
	


}
/*********************************************************************
** Function: set_location_programming_skill2
** Description: sets the location of the programming skill
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_location_programming_skill2(int alevel) {
	int level;
	level = alevel -1;
	bool check = false;
	int random_x;
	int random_y;
	while(check == false) {
		random_x = rand() % maze_height + maze_height*level;
		random_y = rand() % maze_width;
		if(locations[random_x][random_y]->get_display_character() == ' ') {
			OpenSpace* skill2 = new OpenSpace;
			
			skill2->set_has_programming_skill(true);
			skillX2 = random_x;
			skillY2 = random_y;	
			// cout << "skillX2: " << skillX2 << endl;
			// cout << "skillY2: " << skillY2 << endl;
			check = true;
			delete skill2;
		}
	}
	


}
/*********************************************************************
** Function: set_location_programming_skill3
** Description: sets the location of the programming skill
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_location_programming_skill3(int alevel) {
	int level;
	level = alevel -1;
	bool check = false;
	int random_x;
	int random_y;
	while(check == false) {
		random_x = rand() % maze_height + maze_height*level;
		random_y = rand() % maze_width;
		if(locations[random_x][random_y]->get_display_character() == ' ') {
			OpenSpace* skill3 = new OpenSpace;
			
			skill3->set_has_programming_skill(true);
			skillX3 = random_x;
			skillY3 = random_y;
			// cout << "skillX3: " << skillX3 << endl;
			// cout << "skillY3: " << skillY3 << endl;
			check = true;
			delete skill3;
		}
	}
	


}
/*********************************************************************
** Function: set_new_player_location
** Description: sets the location of the new players location
** Parameters: int x, int y
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_new_player_location(int x, int y) {

	locations[x][y]->set_has_explorer(true);
	personX1 = x;
	personY1 = y;
}
/*********************************************************************
** Function: set_old_player_location
** Description: sets the old player location to false
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_old_player_location(int x, int y) {

	locations[x][y]->set_has_explorer(false);
	
}

/*********************************************************************
** Function: set_old_TA_location1
** Description: sets the old ta location to false
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: sets the ta previous location to false
*********************************************************************/ 

void Maze::set_old_TA_location1(int x, int y) {
	locations[x][y]->set_has_ta(false);


}
/*********************************************************************
** Function: set_old_ta_location2
** Description: sets the old ta location 2 to false
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_old_TA_location2(int x, int y) {
	locations[x][y]->set_has_ta(false);


}
/*********************************************************************
** Function:set_new_ta_location1
** Description: sets the new location
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_new_TA_location1(int x, int y) {
	locations[x][y]->set_has_ta(true);
	taX1 = x;
	taY1 = y;
}
/*********************************************************************
** Function: set_new_ta_location2
** Description: sets the new location of the ta
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_new_TA_location2(int x, int y) {
	locations[x][y]->set_has_ta(true);
	taX2 = x;
	taY2 = y;
}
/*********************************************************************
** Function: get_ta_location_x
** Description: gets the ta location for some reason
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns the ta location
*********************************************************************/ 
int Maze::get_ta_location_x(int ta) {
	if(ta == 1) {
		return taX1;
	}
	if(ta == 2) {
		return taX2;
	}

}
/*********************************************************************
** Function: get_ta_location_y
** Description: gets the y location of the ta
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: returns the value
*********************************************************************/ 
int Maze::get_ta_location_y(int ta) {
	if(ta == 1) {
		return taY1;
	}
	if(ta == 2) {
		return taY2;
	}

}
/*********************************************************************
** Function: get_player_location_x
** Description: gets the players x
** Parameters: int level
** Pre-Conditions: int
** Post-Conditions: returns value
*********************************************************************/ 

int Maze::get_player_location_x(int level) {
	if(level == 1) {
		return personX1;
	}
	if(level == 2) {
		return personX1;
	}
	if(level == 3) {
		return personX1;
	}

}
/*********************************************************************
** Function: get_player_location_y
** Description: returns the player y
** Parameters: int level
** Pre-Conditions: int
** Post-Conditions: int
*********************************************************************/ 
int Maze::get_player_location_y(int level) {
	if(level == 1) {
		return personY1;
	}
	if(level == 2) {
		return personY1;
	}
	if(level == 3) {
		return personY1;
	}
}
/*********************************************************************
** Function: check_level
** Description: checks if the level is complete
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: bool
*********************************************************************/ 
bool Maze::check_level(int level) {

	if(level == 1) {
		if(personX1 == endX1 && personY1 == endY1) {
			return true;
		}
		return false;
	}
	if(level == 2) {
		if(personX1 == endX2 && personY1 == endY2) {

			return true;
		}
		return false;
	}
	if(level == 3) {
		if(personX1 == endX3 && personY1 == endY3 && p1.get_programming_skill() >= 3) {
			cout << "You beat the game! Congratulations!" << endl;
			return true;
		}
		if(personX1 == endX3 && personY1 == endY3 && p1.get_programming_skill() < 3) {
			cout << "You didn't get enough programming skills. Start over at the beginning!" << endl;
			p1.set_programming_skill(0);
			return true;

		}
		return false;
	}

}
/*********************************************************************
** Function: getlevelbeat
** Description: returns if the user is caught
** Parameters: int 
** Pre-Conditions: int
** Post-Conditions: returns bool
*********************************************************************/ 
bool Maze::getlevelbeat(int level) {
	if(level == 1) {
		return caught;
	}
	if(level == 2) {
		return caught2;
	}
	if(level == 3) {
		return caught3;
	}
	
}
/*********************************************************************
** Function: set_level1beat
** Description: sets if the user is caught
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_level1beat(bool set) {

	caught = set;
}
/*********************************************************************
** Function: set_level2beat
** Description: sets if the user is caught
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_level2beat(bool set) {
	caught2 = set;
}
/*********************************************************************
** Function: set_level3beat
** Description: sets if level 3 is beat
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::set_level3beat(bool set) {
	caught3 = set;
}
/*********************************************************************
** Function: display_maze
** Description: displays the maze
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::display_maze(int level) {

	if(level == 1) {

		for(int i = 0; i < maze_height; i++) {
			//cout << "i: " << i << endl;
			for(int j = 0; j < maze_width; j++) {
				
				//cout << "j: " << j << endl;
				cout << locations[i][j]->get_display_character();

			}
			cout << endl;
		}
	}	
	if(level == 2) {

		for(int i = maze_height*(level-1); i < maze_height*level; i++) {
			for(int j = 0; j < maze_width; j++) {
				cout << locations[i][j]->get_display_character();
			}
			cout << endl;
		}
	}
	if(level == 3) {

		for(int i = maze_height*(level-1); i < maze_height*level; i++) {
			for(int j = 0; j < maze_width; j++) {
				cout << locations[i][j]->get_display_character();
			}
			cout << endl;
		}
	}
}
/*********************************************************************
** Function: construct_maze
** Description: constructs the maze
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::construct_maze(int level) {

	
	if(level == 1) {
		p1.set_location(startX1, startY1);
	}
	if(level == 2) {
		p1.set_location(startX2, startY2);
	}
	if(level == 3) {
		p1.set_location(startX3, startY3);
	}
	set_location_maze_ta1(level);
	set_location_maze_ta2(level); // SETS THE TA'S LOCATION
	// cout << "taX1: " << taX1 << endl;
	// cout << "taY1: " << taY1 << endl;
	// cout << "taX2: " << taX2 << endl;
	// cout << "taY2: " << taY2 << endl;
	set_location_programming_skill1(level);
	set_location_programming_skill2(level);
	set_location_programming_skill3(level);

	ta1.set_location(get_ta_location_x(1), get_ta_location_y(1));
	ta2.set_location(get_ta_location_x(2), get_ta_location_y(2));
	set_new_TA_location1(get_ta_location_x(1), get_ta_location_y(1));
	set_new_TA_location2(get_ta_location_x(2), get_ta_location_y(2));
	// cout << "TA SET LOCATION: " << get_ta_location_x(1) << endl;
	// cout << "TA SET LOCATION: " << get_ta_location_y(1) << endl;
	// cout << "TA SET LOCATION: " << get_ta_location_x(2) << endl;
	// cout << "TA SET LOCATION: " << get_ta_location_y(2) << endl;
	display_maze(level);



}
/*********************************************************************
** Function: appease
** Description: checks if the user wants to appease
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::appease() {
	string input;
	if(p1.get_programming_skill() > 0 && (ta1.get_appease() == false)) {
		cout << "[p] Do you want to appease the TAs? (press anything else for no) " << endl;
		cin >> input;
			if(input == "p") {
				p1.add_programming_skill(-1);
				ta1.set_appease(true);
				ta2.set_appease(true);
			}
				
	}
	
}
/*********************************************************************
** Function: count_appease
** Description: counts if the tas are appeased and counts the value at which they are at
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::count_appease() {

	if(ta1.get_appease() == true || ta2.get_appease() == true) {
		counter--;
		cout << "The TAs are appeased for: " << counter << " more turns" << endl;
	}
	if(counter == 0) {
		cout << "The TAs are no longer appeased!" << endl;
		ta1.set_appease(false);
		ta2.set_appease(false);
		counter = 10;
	}

}
/*********************************************************************
** Function: player_move
** Description: checks if the player moves
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::player_move(int level) {
	int x;
	int y;
	int temp_x, temp_y;
	char movement;
	bool check = false;
	while(check == false) {
		x = get_player_location_x(level);
		y = get_player_location_y(level);
		// cout << "OLD PLAYER: X " << x << endl;
		// cout << "OLD PLAYER: Y " << y << endl;
		movement = p1.get_move();

		set_old_player_location(x, y);
		temp_x = p1.translate_move_x(movement);
		temp_y = p1.translate_move_y(movement);
		if(check_valid(temp_x, temp_y) == true) {
			x = p1.translate_move_x(movement);
			y = p1.translate_move_y(movement);
			// cout << "NEW PLAYER: X " << x << endl;
			// cout << "NEW PLAYER: Y " << y << endl;
			check = true;
		}
		p1.set_location(x,y);
		set_new_player_location(x,y);
	

		// cout << "X: " << x << " Y: " << y << endl;
		
	}
	
	
			
}
/*********************************************************************
** Function: ta_move1
** Description: the ta moves
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::ta_move1() {
	// cout << "--------TA MOVE 1 ------------" << endl;
	int ta_x, ta_y, ta_temp_x, ta_temp_y;
	char ta_movement;
	bool check = false;
	while(check == false) {
		ta_x = get_ta_location_x(1);
		ta_y = get_ta_location_y(1);
		ta_movement = ta1.get_move(); //NOW TA HAS TO MOVE
		// cout << "THIS IS TA MOVEMENT " << ta_movement << endl;
		set_old_TA_location1(ta_x, ta_y);
		ta_temp_x = ta1.translate_move_x(ta_movement);
		ta_temp_y = ta1.translate_move_y(ta_movement);
		// cout << "TA_TEMP_X: " << ta_temp_x << endl;
		// cout << "TA_TEMP_Y: " << ta_temp_y << endl;
		if(check_valid_ta(ta_temp_x, ta_temp_y) == true) {
			// cout << "VALID TA_TEMP_X: " << ta_temp_x << endl;
			// cout << "VALID TA_TEMP_Y: " << ta_temp_y << endl;
			ta_x = ta1.translate_move_x(ta_movement);
			ta_y = ta1.translate_move_y(ta_movement);
			check = true;
		}
		ta1.set_location(ta_x, ta_y);
		set_new_TA_location1(ta_x, ta_y);
	}
}
/*********************************************************************
** Function: ta_move2
** Description: the second ta moves
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::ta_move2() {
	// cout << "--------TA MOVE 2 ------------" << endl;
	int ta_x, ta_y, ta_temp_x, ta_temp_y;
	char ta_movement;
	bool check = false;
	while(check == false) {
		ta_x = get_ta_location_x(2);
		ta_y = get_ta_location_y(2);
		ta_movement = ta2.get_move(); //NOW TA HAS TO MOVE
		// cout << "THIS IS TA MOVEMENT " << ta_movement << endl;
		set_old_TA_location2(ta_x, ta_y);
		ta_temp_x = ta2.translate_move_x(ta_movement);
		ta_temp_y = ta2.translate_move_y(ta_movement);
		// cout << "TA_TEMP_X: " << ta_temp_x << endl;
		// cout << "TA_TEMP_Y: " << ta_temp_y << endl;
		if(check_valid(ta_temp_x, ta_temp_y) == true) {
			// cout << "VALID TA_TEMP_X: " << ta_temp_x << endl;
			// cout << "VALID TA_TEMP_Y: " << ta_temp_y << endl;
			ta_x = ta2.translate_move_x(ta_movement);
			ta_y = ta2.translate_move_y(ta_movement);
			check = true;
		}
		ta2.set_location(ta_x, ta_y);
		set_new_TA_location2(ta_x, ta_y);
	}
}
/*********************************************************************
** Function: check_caught
** Description: checks if the user is caught
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns bool
*********************************************************************/ 
bool Maze::check_caught() {
	// cout << "TA X1: " << taX1 << endl;
	// cout << "TA Y1: " << taY1 << endl;
	// cout << "TA X2: " << taX2 << endl;
	// cout << "TA Y2: " << taY2 << endl;
	// cout << "person X: " << personX1 << endl;
	// cout << "person Y: " << personY1 << endl;
	if(ta1.get_appease() == false || ta2.get_appease() == false) {
		if((personX1 - 1 == taX1 && personY1 == taY1 || personX1 + 1 == taX1 && personY1 == taY1) && p1.get_programming_skill() <= 0) {
				cout << "You got caught" << endl;
				p1.set_programming_skill(0);
				return true;
			}
		if(((personX1 == taX1 && personY1 - 1 == taY1) || personX1 == taX1 && personY1 + 1 == taY1) && p1.get_programming_skill() <= 0) {
			cout << "You got caught" << endl;
			p1.set_programming_skill(0);
			return true;

		}
		if((personX1 - 1 == taX2 && personY1 == taY2 || personX1 + 1 == taX2 && personY1 == taY2) && p1.get_programming_skill() <= 0) {
			cout << "You got caught" << endl;
			p1.set_programming_skill(0);
			return true;
		}
		if(((personX1 == taX2 && personY1 - 1 == taY2) || personX1 == taX2 && personY1 + 1 == taY2) && p1.get_programming_skill() <= 0) {
			cout << "You got caught" << endl;
			p1.set_programming_skill(0);
			return true;
		}
		if((personX1 == taX1 && personY1 == taY1) || personX1 == taX2 && personY1 == taY2) {
			cout << "You got caught" << endl;
			p1.set_programming_skill(0);
			return true;
		}

	}
	
	return false;

}
/*********************************************************************
** Function: check_skill
** Description: checks if the skill is picked up
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::check_skill() {

	if(personX1 == skillX1 && personY1 == skillY1 /*&& locations[personX1][personY1]->get_has_programming_skill() == true*/) {
		cout << "------------------You picked up a skill!---------------------" << endl;
		p1.add_programming_skill(1);
		locations[personX1][personY1]->set_has_programming_skill(false);
	}
	if(personX1 == skillX2 && personY1 == skillY2 /*&& locations[personX1][personY1]->get_has_programming_skill() == true*/) {
		cout << "------------------You picked up a skill!---------------------" << endl;
		cout << "You picked up a skill!" << endl;
		p1.add_programming_skill(1);
		locations[personX1][personY1]->set_has_programming_skill(false);
	}
	if(personX1 == skillX3 && personY1 == skillY3 /*&& locations[personX1][personY1]->get_has_programming_skill() == true*/) {
		cout << "------------------You picked up a skill!---------------------" << endl;
		cout << "You picked up a skill!" << endl;
		p1.add_programming_skill(1);
		locations[personX1][personY1]->set_has_programming_skill(false);
	}
	cout << "YOUR NUMBER OF PROGRAMMING SKILLS: " << p1.get_programming_skill() << endl;
}
/*********************************************************************
** Function: reset_maze
** Description: resets the maze
** Parameters: int level
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void Maze::reset_maze(int level) {
	for(int i = 0; i < locations.size(); i++) {
		for(int j = 0; j < locations[i].size(); j++) {
			//locations[i][j]
		}
	}
}
/*********************************************************************
** Function: get_programming_skill
** Description: gets the programming skill
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int Maze::get_programming_skill() {

	int number = p1.get_programming_skill();
	return number;
}
/*********************************************************************
** Function: ~Maze
** Description: deconstructs the maze
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Maze::~Maze() {

	for(int i = 0; i < locations.size(); i++) {
		for(int j = 0; j < locations[i].size(); j++) {
			if(locations[i][j]->get_display_character() == ' ') {
				delete locations[i][j];
			}
			
		}
	}


}

