#ifndef MAZEPERSON_H
#define MAZEPERSON_H
#include <iostream>

using namespace std;

class MazePerson {

public:

	virtual char get_move() = 0;
	virtual void set_location(int, int) = 0;
	virtual int get_row() = 0;
	virtual int get_col() = 0;

};
#endif