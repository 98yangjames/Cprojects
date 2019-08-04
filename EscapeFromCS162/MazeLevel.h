#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <vector>
#include <tuple>
#include "./MazeLocation.h"
using namespace std;

class MazeLevel {

private:
	vector<vector<MazeLocation*> > locations;
	int maze_locationX;
	int maze_locationY;
	int levels, height, width;
	int maze_height;
	int maze_width;

public:
	MazeLevel(int AMazeLevel_height, int AMazeLevel_width);
	void display_maze(int level);
	void set_location_maze(int x, int y, char aChar);
	~MazeLevel();
	
};


#endif
