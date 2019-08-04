#include <iostream>
#include "./nothing.h"

using namespace std;

/*********************************************************************
** Function: Nothing
** Description: Constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Nothing::Nothing() {

	

}
string Nothing::get_event_name() {

	return "nothing";

}
/*********************************************************************
** Function: percept
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Nothing::percept() {
	
	cout << "" << endl;
}
/*********************************************************************
** Function: encounter
** Description: displays from the animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void Nothing::encounter() {

	cout << " " << endl;

}