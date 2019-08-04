#ifndef WUMPUS_H
#define WUMPUS_H
#include "./event.h"

#include <iostream>
#include <string>


using namespace std;

class Wumpus : public Event {
private:

public:
	Wumpus();
	string get_event_name();
	void percept();
	void encounter();

};

#endif