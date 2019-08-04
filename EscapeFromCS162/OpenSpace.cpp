#include <iostream>
#include "./OpenSpace.h"

using namespace std;
/*********************************************************************
** Function: OpenSpace
** Description: constructs the openspace
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
OpenSpace::OpenSpace() {
	programming_skill = false;
	ta_location = false;
	explorer_location = false;
	start_location = false;
	end_location = false;
	
}
/*********************************************************************
** Function: is_occupiable
** Description: is_occupiable
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns bool
*********************************************************************/ 
bool OpenSpace::is_occupiable() {

	return true;

}
/*********************************************************************
** Function: get_display_character
** Description: gets the display character of the open space
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: char
*********************************************************************/ 
char OpenSpace::get_display_character() {

	if(explorer_location == true) {
		return 'U';
	}
	if(start_location == true) {
		return '@';
	}
	if(end_location == true) {
		return '^';
	}
	if(programming_skill == true) {
		return '$';
	}
	if(ta_location == true) {
		return 'T';
	}
	if(instructor_location == true) {
		return '%';
	}
	else {
		return ' ';
	}
	
}
/*********************************************************************
** Function: set_is_instructor
** Description: sets if it has a instructor
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_is_instructor(bool ainstructor) {

	instructor_location = ainstructor;


}
/*********************************************************************
** Function: set_has_explorer
** Description: sets if it has a explorer
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_has_explorer(bool explorer_location) {
	
	this->explorer_location = explorer_location;

}
/*********************************************************************
** Function: set_has_ta
** Description: sets if it has a ta
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_has_ta(bool ata_location) {
	ta_location = ata_location;
}
/*********************************************************************
** Function: has_explorer
** Description: returns if it has the explorer
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bool
*********************************************************************/ 
bool OpenSpace::has_explorer() {

	return explorer_location;
}
/*********************************************************************
** Function: set_is_start
** Description: sets if it has start
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_is_start(bool start_location) {

	this->start_location = start_location;
}
/*********************************************************************
** Function: is_start
** Description: sets start
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bool
*********************************************************************/ 
bool OpenSpace::is_start() {

	return start_location;
}
/*********************************************************************
** Function: set_is_end
** Description: sets the end location
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_is_end(bool end_location) {

	this->end_location = end_location;

}
/*********************************************************************
** Function: is_end
** Description: checks if it is the end
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bool
*********************************************************************/ 
bool OpenSpace::is_end() {
	return end_location;
}
/*********************************************************************
** Function: set_has_programming_skill
** Description: sets the programming skill
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_has_programming_skill(bool aprogramming_skill) {

	programming_skill = aprogramming_skill;

}

/*********************************************************************
** Function: get_has_programming_skill
** Description: if it has a programming skill
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bool
*********************************************************************/ 
bool OpenSpace::get_has_programming_skill() {

	return programming_skill;
}
/*********************************************************************
** Function: display_programming
** Description: display programming
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: char
*********************************************************************/ 
char OpenSpace::display_programming() {
	return '$';
}
/*********************************************************************
** Function: set_display_character
** Description: displays the character
** Parameters: char
** Pre-Conditions: char
** Post-Conditions: n/a
*********************************************************************/ 
void OpenSpace::set_display_character(char acharacter) {
	character = acharacter;
	

}