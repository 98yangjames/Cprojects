#ifndef OPENSPACE_H
#define OPENSPACE_H
#include <iostream>
#include "./MazeLocation.h"

using namespace std;

class OpenSpace : public MazeLocation {

private:
	bool programming_skill;
	bool explorer_location;
	bool start_location;
	bool end_location;
	bool ta_location;
	bool instructor_location;
	char character;

public:

	OpenSpace();
	bool is_occupiable();
	char get_display_character();
	char display_programming();
	void set_has_explorer(bool);
	bool has_explorer();
	void set_is_start(bool);
	bool is_start();
	void set_is_end(bool);
	bool is_end();
	void set_has_ta(bool);
	void set_has_programming_skill(bool);
	void set_is_instructor(bool);
	bool get_has_programming_skill();
	void set_display_character(char achar);


};

#endif