#ifndef WALL_H
#define WALL_H
#include <iostream>
#include "./MazeLocation.h"

using namespace std;

class Wall : public MazeLocation {

private:



public:
	Wall();
	bool is_occupiable();
	char get_display_character();
	void set_has_explorer(bool);
	bool has_explorer();
	void set_has_ta(bool);
	void set_has_programming_skill(bool);
	bool get_has_programming_skill();
	char display_programming();
	void set_display_character(char);
};

#endif