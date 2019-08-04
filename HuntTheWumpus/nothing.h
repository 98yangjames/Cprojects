#ifndef NOTHING_H
#define Nothing_H
#include "./event.h"
#include <string>

using namespace std;
class Nothing : public Event {

private:

public:
	Nothing();
	string get_event_name();
	void percept();
	void encounter();

};






#endif