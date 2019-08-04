#include <iostream>
#include "./Wall.h"

using namespace std;
/*********************************************************************
** Function:Wall
** Description: constructs wall
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Wall::Wall() {

	

}
/*********************************************************************
** Function: is_occupiable
** Description: chekcs if the wall is occupiable
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bool
*********************************************************************/ 
bool Wall::is_occupiable() {

	return false;

}
/*********************************************************************
** Function: get_display_character
** Description: returns wall
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: char
*********************************************************************/ 
char Wall::get_display_character() {

	return '#';
	
}
/*********************************************************************
** Function:set_has_explorer
** Description: virtual function w no function
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void Wall::set_has_explorer(bool) {

}
/*********************************************************************
** Function: set_has_ta
** Description: 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Wall::set_has_ta(bool) {


}
/*********************************************************************
** Function:has_explorer
** Description: virtual function w no function
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bool
*********************************************************************/ 
bool Wall::has_explorer() {

	return false;

}
/*********************************************************************
** Function: set_has_programming_skill
** Description: virtual function w no function
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Wall::set_has_programming_skill(bool) {


}
/*********************************************************************
** Function:get_has_programming_skill
** Description: virtual function w no function
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
bool Wall::get_has_programming_skill() {


}
/*********************************************************************
** Function:display_programming
** Description: virtual function w no function
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/  
char Wall::display_programming() {

	
	
}
/*********************************************************************
** Function:set_display_character
** Description: virtual function w no function
** Parameters: char
** Pre-Conditions: char
** Post-Conditions: n/a
*********************************************************************/ 
void Wall::set_display_character(char character) {

}