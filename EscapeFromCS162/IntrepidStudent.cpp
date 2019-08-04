#include <iostream>
#include <string>
#include "./IntrepidStudent.h"


using namespace std;
/*********************************************************************
** Function: IntrepidStudent
** Description: initializes the student
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
IntrepidStudent::IntrepidStudent() {
	programming_skills = 0;
	x = 0;
	y = 0;


}
/*********************************************************************
** Function: get_move
** Description: gets the move of the student
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns char
*********************************************************************/ 
char IntrepidStudent::get_move() {
	bool flag = false;
	while(flag == false) {
		cout << "What move do you want? (wasd)" << endl;
		cin >> movement;
		if(movement == "w") {
			flag = true;
			return 'w';
		}
		if(movement == "a") {
			flag = true;
			return 'a';
		}
		if(movement == "s") {
			flag = true;
			return 's';
		}
		if(movement == "d") {
			flag = true;
			return 'd';
		}
	}
	
}
/*********************************************************************
** Function: check_caught
** Description: checks if the user is caught
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns bool
*********************************************************************/ 
bool IntrepidStudent::check_caught(int ta_x, int ta_y) {
	if(x == ta_x && y == ta_y) {
		cout << "You got caught and now you have no programming skills" << endl;
		programming_skills = 0;
		return true;
	}
}
/*********************************************************************
** Function: translate_move_x
** Description: translates the x coordinate
** Parameters: char movement
** Pre-Conditions: char
** Post-Conditions: int
*********************************************************************/ 
int IntrepidStudent::translate_move_x(char movement) {
	
	if(movement == 'a') {
		return x;
	}
	if(movement == 'w') {
		return x-1;
	}
	if(movement == 'd') {
		return x;
	}
	if(movement == 's') {
		return x+1;
	}


}

/*********************************************************************
** Function: translate_move_y
** Description: translates the move on the y
** Parameters: char
** Pre-Conditions: char
** Post-Conditions: int
*********************************************************************/ 
int IntrepidStudent::translate_move_y(char movement) {

	if(movement == 'a') {
		return y-1;
	}
	if(movement == 'w') {
		return y;
	}
	if(movement == 'd') {
		return y+1;
	}
	if(movement == 's') {
		return y;
	}

}
/*********************************************************************
** Function: set_location
** Description: sets the location of the student
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: n/a
*********************************************************************/ 
void IntrepidStudent::set_location(int ax, int ay) {

	x = ax;
	y= ay;
	// cout << "Y in student: " << x << endl;
	// cout << "X in student: " << y << endl;

}
/*********************************************************************
** Function: get_row
** Description: gets the row
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int IntrepidStudent::get_row() {

	return x;

}
/*********************************************************************
** Function: get_col
** Description: gets the col
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/
int IntrepidStudent::get_col() {

	return y;

}
/*********************************************************************
** Function: set_programming_skill
** Description: sets the program skill
** Parameters: int number
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void IntrepidStudent::set_programming_skill(int number) {

	programming_skills = number;

}
/*********************************************************************
** Function: add_programming_skill
** Description: adds the program skill
** Parameters: int number
** Pre-Conditions: int
** Post-Conditions: n/a
*********************************************************************/ 
void IntrepidStudent::add_programming_skill(int number) {
	programming_skills = number + programming_skills;
}
/*********************************************************************
** Function: get_programming_skill
** Description: gets the programming skill
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int IntrepidStudent::get_programming_skill() {

	return programming_skills;
}