#ifndef TA_H
#define TA_H
#include <iostream>
#include "./MazePerson.h"

using namespace std;

class TA : public MazePerson {

private:

	int x;
	int y;
	bool ta_appease;

public:
	TA();
	char get_move();
	void set_location(int, int);
	void set_appease(bool aappease);
	int get_appease();
	int get_row();
	int get_col();
	int translate_move_x(char movement);
	int translate_move_y(char movement);

};
#endif