/*********************************************************************
** Program Filename: maze
** Author: James Yang
** Date: 3/19
** Description: plays maze
** Input: file maze.txt
** Output: game
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include "./Maze.h"
#include "./IntrepidStudent.h"
#include "./Ta.h"
#include "./MazeLevel.h"
#include "./Wall.h"
#include "./OpenSpace.h"



using namespace std;

int main(int argc, char* argv[]) {
	char character;
	bool check_valid = false;
	bool ta_move = false;
	int current_level = 1;
	int levels, height, width;
	bool level1 = false;
	bool level2 = false;
	bool level = false;
	bool over = false;
	bool over2 = false;
	bool over3 = false;
	bool game_complete = false;
	srand(time(NULL));

	
	if(argc != 2) {
		cout << "Invalid Arguments (Just enter program name and maze.txt)" << endl;
		return 0;
	}
	if(strcmp(argv[1], "maze.txt") == 0) {
		ifstream testfile("maze.txt");
		if(testfile.is_open() == true) {

			testfile >> levels >> height >> width;
			testfile.get();
			Maze maze(height, width, levels);
			IntrepidStudent p1;
			TA ta1, ta2, ta3;
			for(int i = 0; i < height*levels; i++) {

				if(i % height == 0 && i != 0) {
					current_level++;
				}
				for(int j = 0; j < width; j++) {
					character = testfile.get();
					maze.set_location_maze(i, j, character, current_level);

				}
				testfile.get();
			}
		while(game_complete == false) {
			maze.set_level1beat(false);
			maze.set_level2beat(false);
			maze.set_level3beat(false);
			over = false;
			over2 = false;
			over3 = false;
			while(maze.getlevelbeat(1) == false) {

				cout << "--------LEVEL 1--------" << endl;
				over = false;
				maze.construct_maze(1);
				while(over == false) {
					maze.player_move(1);
					maze.check_skill();
					
					maze.ta_move1();
					maze.ta_move2();

					maze.count_appease();
					maze.appease();
					maze.display_maze(1);
					if(maze.check_level(1)== true) {
						cout << "you beat level 1" << endl;
						over = true;
						maze.set_level1beat(true);
					}
					if(maze.check_caught() == true) {
						cout << "you lose" << endl;
						over = true;
						maze.set_level1beat(false);
					}
				
				}
				
			}
				while(maze.getlevelbeat(2) == false) {
					over2 = false;
					cout << "--------LEVEL 2--------" << endl;
					maze.construct_maze(2);
					
					while(over2 == false) {
						
						maze.player_move(2);
						maze.check_skill();
						
						maze.ta_move1();
						maze.ta_move2();

						maze.count_appease();
						maze.appease();
						maze.display_maze(2);
						if(maze.check_level(2)== true) {
							cout << "you win" << endl;
							over2 = true;
							level = true;
							maze.set_level2beat(true);
						}
						if(maze.check_caught() == true) {
							cout << "you lose" << endl;
							over2 = true;
							maze.set_level2beat(false);
						}
						
						
					}
				
				}
				while(maze.getlevelbeat(3) == false) {
					over3 = false;
					cout << "--------LEVEL 3--------" << endl;
					maze.construct_maze(3);
					while(over3 == false) {
						maze.player_move(3);
						maze.check_skill();
						maze.count_appease();
						
						maze.ta_move1();
						maze.ta_move2();
						maze.appease();
						maze.display_maze(3);
						if(maze.check_level(3)== true) {
							if(maze.get_programming_skill() >= 3) {
								game_complete = true;
								over3 = true;
							}
							maze.set_level3beat(true);
							over3 = true;
						}

						if(maze.check_caught() == true) {
							cout << "you lose" << endl;
							maze.set_level3beat(true);
							over3 = true;
						}
					}
				}
		}
			

		}
	}
	else {
		cout << "Enter maze maze.txt" << endl;
	}




	
}
