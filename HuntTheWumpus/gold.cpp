#include <iostream>
#include "./gold.h"

using namespace std;
/*********************************************************************
** Function: Gold
** Description: Constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Gold::Gold() {

	

}

string Gold::get_event_name() {

	return "gold";

}
/*********************************************************************
** Function: percept
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Gold::percept() {
	
	cout << "You see a glimmer nearby" << endl;
	
}
/*********************************************************************
** Function: encounter
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Gold::encounter() {

	cout << "You found gold!" << endl;

}