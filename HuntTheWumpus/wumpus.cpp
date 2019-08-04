#include <iostream>
#include "./wumpus.h"

using namespace std;
/*********************************************************************
** Function: Wumpus
** Description: Constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Wumpus::Wumpus() {


}

string Wumpus::get_event_name() {

	return "wumpus";

}
/*********************************************************************
** Function: percept
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Wumpus::percept() {
	
	cout << "You smell a terrible stench" << endl;
	
}
/*********************************************************************
** Function: encounter
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Wumpus::encounter() {

	cout << "You encountered the wumpus" << endl;
}