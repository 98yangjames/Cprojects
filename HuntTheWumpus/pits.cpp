#include <iostream>
#include "./pits.h"

using namespace std;

/*********************************************************************
** Function: Pits
** Description: Constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Pits::Pits() {

	

}

string Pits::get_event_name() {

	return "pits";

}
/*********************************************************************
** Function: percept
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Pits::percept() {
	
	cout << "You feel a breeze." << endl;
	
}
/*********************************************************************
** Function: encounter
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Pits::encounter() {

	cout << "You fell into a pit, good game!" << endl;

}