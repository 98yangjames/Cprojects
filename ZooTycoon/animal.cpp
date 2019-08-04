#include <iostream>
#include "./animal.h" 

using namespace std;

/*********************************************************************
** Function: animal
** Description: constructs the animal
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: initializes values
*********************************************************************/ 

animal::animal() {

	int age = 0;
	int cost = 0;
	int babies = 0;
	int food_cost = 0;
	int revenue = 0;
	int base = 0;
}
/*********************************************************************
** Function: animal(int,int)
** Description: constructs the age and cost of the animal
** Parameters: takes in age and cost
** Pre-Conditions: n/a
** Post-Conditions: sets the age and cost
*********************************************************************/ 

animal::animal(int Aage, int Acost) {

	age = Aage;
	cost = Acost;

}
/*********************************************************************
** Function: set_age
** Description: sets the age
** Parameters: int Aage
** Pre-Conditions: int
** Post-Conditions: sets the age
*********************************************************************/ 
void animal::set_age(int Aage) {

	age = Aage;

}
/*********************************************************************
** Function: set_cost
** Description: sets the cost
** Parameters: int Acost
** Pre-Conditions: int
** Post-Conditions: sets the cost
*********************************************************************/ 
void animal::set_cost(int Acost) { 

}
/*********************************************************************
** Function: set_food_cost
** Description: sets the food cost
** Parameters: int Abase
** Pre-Conditions: int
** Post-Conditions: sets the food cost
*********************************************************************/ 
void animal::set_food_cost(int Abase) {

	food_cost = Abase;

}
/*********************************************************************
** Function: get_age
** Description: gets the age of animal
** Parameters: n/a
** Pre-Conditions: int
** Post-Conditions: returns int
*********************************************************************/ 

int animal::get_age() {

	return age;
}
/*********************************************************************
** Function: get_cost
** Description: gets the cost of the animal
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: returns int
*********************************************************************/ 
int animal::get_cost() {

	return cost;

}
/*********************************************************************
** Function: set_revenue
** Description: sets the revenue
** Parameters: int arevenue
** Pre-Conditions: int
** Post-Conditions: sets the revenue
*********************************************************************/ 
void animal::set_revenue(int Arevenue) {

	revenue = Arevenue;

}
/*********************************************************************
** Function: get_revenue
** Description: gets the revenue
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: int
*********************************************************************/ 
int animal::get_revenue() {

	return revenue;

}

