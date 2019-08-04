#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event {

private:

public:
	virtual string get_event_name() = 0;
	virtual void percept() = 0;
	virtual void encounter() = 0;


};

#endif