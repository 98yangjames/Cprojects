#ifndef ROOM_H
#define ROOM_H
#include "./event.h"
#include <iostream>
#include <string>
using namespace std;

class Room {
private:
	Event* event;
	string event_name;


public:
	void set_event(Event* event);
	Event* get_event();
	string get_event_name();
	Room();
	~Room();
};

#endif