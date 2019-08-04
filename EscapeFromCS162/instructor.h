#include <iostream>
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include "./MazePerson.h"

using namespace std;

class Instructor : public MazePerson {

private:
	int x;
	int y;
public:
	Instructor();
	char get_move();
	void set_location(int x, int y);
	int get_row();
	int get_col();


};
#endif