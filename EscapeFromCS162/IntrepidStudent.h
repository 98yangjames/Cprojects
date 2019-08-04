#ifndef INTREPIDSTUDENT_H
#define INTREPIDSTUDENT_H

#include <iostream>
#include <string>
#include "./MazePerson.h"

using namespace std;

class IntrepidStudent : public MazePerson {

private:
	int programming_skills;
	int x;
	int y;
	string movement;

public:
	IntrepidStudent();
	char get_move();
	void set_location(int, int);
	int translate_move_x(char movement);
	int translate_move_y(char movement);
	int get_row();
	int get_col();
	bool check_caught(int ta_x, int ta_y);
	void set_programming_skill(int number);
	void add_programming_skill(int number);
	int get_programming_skill();


};
#endif