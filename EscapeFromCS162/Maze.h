#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <tuple>
#include "./Ta.h"
#include "./instructor.h"
#include "./IntrepidStudent.h"
#include "./MazeLocation.h"
using namespace std;

class Maze {

private:
	vector<vector<MazeLocation*> > locations;
	int personX1, personY1;
	int personX2, personY2;
	int personX3, personY3;
	int endX1, endX2, endX3;
	int endY1, endY2, endY3;
	int taX1, taX2;
	int taY1, taY2;
	int levels, height, width;
	int maze_height;
	int maze_width;
	int loadLevels, loadHeight, loadWidth;
	char character;
	int current_level;
	TA ta1, ta2;
	IntrepidStudent p1;
	Instructor instructor;
	int startX1,startY1;
	int startX2,startY2;
	int startX3,startY3;
	int skillX1, skillY1;
	int skillX2, skillY2;
	int skillX3, skillY3;
	int counter;
	bool caught, caught2, caught3;




public:
	Maze(int Amaze_height, int Amaze_width, int alevels);
	void display_maze(int level);
	void set_location_maze(int x, int y, char aChar, int level);
	int get_player_location_x(int level);
	int get_player_location_y(int level);
	int get_ta_location_x(int ta);
	int get_ta_location_y(int ta);
	bool check_valid(int x, int y);
	bool check_valid_ta(int x, int y);
	void set_new_player_location(int x, int y);
	void set_old_player_location(int x, int y);
	bool check_level(int level);
	void set_old_TA_location1(int x, int y);
	void set_old_TA_location2(int x, int y);
	void set_new_TA_location1(int x, int y);
	void set_new_TA_location2(int x, int y);
	void set_location_maze_ta1(int alevel);
	void set_location_maze_ta2(int alevel);
	void set_location_programming_skill1(int alevel);
	void set_location_programming_skill2(int alevel);
	void set_location_programming_skill3(int alevel);
	void construct_maze(int level);
	void player_move(int level);
	void ta_move1();
	void ta_move2();
	bool check_caught();
	bool complete_level_1();
	void check_skill();
	void appease();
	void count_appease();
	bool getlevelbeat(int level);
	void set_level1beat(bool);
	void set_level2beat(bool);
	void set_level3beat(bool);
	void reset_maze(int level);
	int get_programming_skill();
	~Maze();
};


#endif
