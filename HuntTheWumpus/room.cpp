#include <iostream>
#include "./room.h"
#include "./event.h"

using namespace std;
/*********************************************************************
** Function: Room
** Description: Constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
Room::Room() {
	
	event = NULL;
	event_name = "";
}
/*********************************************************************
** Function: set_event
** Description: sets the event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 

void Room::set_event(Event* event) {

	this->event = event;

}
/*********************************************************************
** Function: get_event_name
** Description: returns event name
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns string
*********************************************************************/ 
string Room::get_event_name() {

	return event_name;

}
/*********************************************************************
** Function: get_event
** Description: returns event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns event object
*********************************************************************/ 
Event* Room::get_event() {

	return event;

}

Room::~Room() {

	delete [] event;
}