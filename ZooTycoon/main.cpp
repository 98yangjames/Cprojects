/*********************************************************************
** Program Filename: zootycoon
** Author: James Yang
** Date: 2/14/19
** Description: Plays Zoo Tycoon
** Input: user input
** Output: the game
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./zoo.h"
#include "./animal.h"

using namespace std;


int main() {
	srand(time(NULL));
	zoo zoo;
	int turn = 0;
	int food_chance = 0;
	//initialization functions
	cout << "+++++++++++++++++++++++Day: " << turn << "+++++++++++++++++++++++" <<endl;
	cout << "Welcome to Zootycoon, your starting balance is $100,000. What animal would you like to buy?" << endl;
	
	while (zoo.check_game_over(turn) == false) {
		zoo.howMany(zoo.userinput()); //USE THESE EVERYTIME U WANNA BUY
		cout << "Now you have to feed your animals..." << endl;
		food_chance = zoo.feed_animals(turn);
		zoo.random_occurance(food_chance);
		zoo.increment_age();
		zoo.revenue();
		turn++;
		cout << "+++++++++++++++++++++++Day: " << turn << "+++++++++++++++++++++++" <<endl;
	}
}