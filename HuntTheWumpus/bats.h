#ifndef BATS_H
#define BATS_H
#include "./event.h"
class Bats : public Event{

private:

public:
	Bats();
	string get_event_name();
	void percept();
	void encounter();
};



#endif