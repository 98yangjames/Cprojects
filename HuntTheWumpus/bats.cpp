#include <iostream>
#include "./bats.h"

using namespace std;

/*********************************************************************
** Function: Bats
** Description: Constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Bats::Bats() {
}
/*********************************************************************
** Function: get_event_name
** Description: returns a statement
** Parameters: string
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
string Bats::get_event_name() {

	return "bats";

}
/*********************************************************************
** Function: percept
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Bats::percept() {
	
	cout << "You hear wings flapping." << endl;
	
}
/*********************************************************************
** Function: encounter
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Bats::encounter() {

	cout << "Bats are now taking you to some random location on the map" << endl;

}