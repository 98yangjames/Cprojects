#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./Ta.h"

using namespace std;
/*********************************************************************
** Function: TA
** Description: constructs the ta
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
TA::TA() {

	x = 0;
	y = 0;
	ta_appease = false;

}
/*********************************************************************
** Function: get_move
** Description: ta moves
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: char
*********************************************************************/ 
char TA::get_move() {

	int random = rand() % 4 + 1;
	if(random == 1) {
		return 'w';
	}
	if(random == 2) {
		return 'a';
	}
	if(random == 3) {
		return 's';
	}
	if(random == 4) {
		return 'd';
	}

}
/*********************************************************************
** Function: translate_move_x
** Description: translates the ta move
** Parameters: char
** Pre-Conditions: char
** Post-Conditions: int
*********************************************************************/ 
int TA::translate_move_x(char movement) {
// cout << "this is x: " << x << endl;
	if(movement == 'a') {
	
		return x;
	}
	if(movement == 'w') {
		return x-1;
	}
	if(movement == 'd') {
		return x;
	}
	if(movement == 's') {
		return x+1;
	}


}
/*********************************************************************
** Function: translate_move_y
** Description: translates the move y
** Parameters: char
** Pre-Conditions: char
** Post-Conditions: int
*********************************************************************/ 
int TA::translate_move_y(char movement) {
// cout << "this is y: " << y << endl;
	if(movement == 'a') {
		return y-1;
	}
	if(movement == 'w') {
		return y;
	}
	if(movement == 'd') {
		return y+1;
	}
	if(movement == 's') {
		return y;
	}

}


/*********************************************************************
** Function: set_location
** Description: sets the location of the ta
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void TA::set_location(int ax, int ay) {

	x = ax;
	y = ay;

}
/*********************************************************************
** Function: set_appease
** Description: sets the appease
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void TA::set_appease(bool aappease) {
	ta_appease = aappease;
}
/*********************************************************************
** Function: get_appease
** Description: returns the appease
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int TA::get_appease() {

	return ta_appease;

}
/*********************************************************************
** Function: get_row
** Description: returns the row
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int TA::get_row() {

	return x;
}
/*********************************************************************
** Function: get_col
** Description: returns the col
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int TA::get_col() {

	return y;
}