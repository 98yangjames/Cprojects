#ifndef PITS_H
#define PITS_H
#include "./event.h"
#include <string>

using namespace std;
class Pits : public Event {

private:

public:
	Pits();
	string get_event_name();
	void percept();
	void encounter();

};






#endif