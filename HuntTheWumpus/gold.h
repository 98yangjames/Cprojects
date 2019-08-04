#ifndef GOLD_H
#define GOLD_H
#include <iostream>
#include <string>
#include "./event.h"
using namespace std;

class Gold : public Event{
private:

public:
	Gold();
	string get_event_name();
	void percept();
	void encounter();
};




#endif