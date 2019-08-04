#include <iostream>
#include "./instructor.h"

using namespace std;
/*********************************************************************
** Function: Instructor
** Description: constructs the instructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Instructor::Instructor() {

	int x = 0;
	int y = 0;


}
/*********************************************************************
** Function: get_move
** Description: gets the move
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
char Instructor::get_move() {


}
/*********************************************************************
** Function: set_location
** Description: sets the location
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void Instructor::set_location(int ax, int ay) {

	x = ax;
	y = ay;

}
/*********************************************************************
** Function: get_row
** Description: returns the row
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns x
*********************************************************************/ 
int Instructor::get_row() {

	return x;

}
/*********************************************************************
** Function: get_col
** Description: returns the col
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns y
*********************************************************************/ 
int Instructor::get_col() {
	return y;
}