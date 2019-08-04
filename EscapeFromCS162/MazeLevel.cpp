#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "./Maze.h"
#include "./Wall.h"
#include "./OpenSpace.h"
#include "./MazeLocation.h"	
#include "./MazeLevel.h"

// MazeLevel::MazeLevel(int AMazeLevel_height, int AMazeLevel_width) {  //I want to change array to &ifstream nameoffile 
// 	char character;
// 	MazeLevel_height = AMazeLevel_height;
// 	MazeLevel_width = AMazeLevel_width;
// 	MazeLevel_locationX = 0;
// 	MazeLevel_locationY = 0;
// 	locations.resize(MazeLevel_height);
// 	for(int i = 0; i < MazeLevel_height; i++) {
// 		locations[i].resize(MazeLevel_width);
// 		//locations.push_back(vector<MazeLevelLocation*>(MazeLevel_width));
// 	}
	

// }

// void MazeLevel::set_location_MazeLevel(int x, int y, char aChar) {
// 	cout << "X: " << x << "Y: " << y << endl;
// 	cout << "char " << aChar << endl;

// 	if(aChar == '#') {
// 		locations[x][y] = new Wall();
// 	}

// 	if(aChar == '@') {
// 		OpenSpace* start = new OpenSpace;
// 		start->set_is_start(true);
// 		locations[x][y] = start;
// 	}
// 	if(aChar == '^') {
// 		OpenSpace* end = new OpenSpace;
// 		end->set_is_end(true);
// 		locations[x][y] = end;
// 	}
// 	if(aChar == ' ') {
// 		locations[x][y] = new OpenSpace();
// 	}

	

// }

// void MazeLevel::display_MazeLevel(int level) {

// 	cout << "THiS IS MazeLevel_HEIGHT " << MazeLevel_height << endl;
// 	cout << "THIS IS MazeLevel_WIDTH " << MazeLevel_width << endl;
// 	if(level == 1) {
// 		for(int i = 0; i < MazeLevel_height; i++) {
// 		//cout << "i: " << i << endl;
// 		for(int j = 0; j < MazeLevel_width; j++) {
			
// 			//cout << "j: " << j << endl;
// 			cout << locations[i][j]->get_display_character();
// 		}
// 		cout << endl;
// 		}
// 	}
	
// }


