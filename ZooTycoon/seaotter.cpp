#include <iostream>
#include "./seaotter.h"

using namespace std;

/*********************************************************************
** Function: sea_otter
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
sea_otter::sea_otter() {

}
/*********************************************************************
** Function: add_sea_otter_revenue(int, int)
** Description: sets revenue
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns int
*********************************************************************/ 
int sea_otter::add_sea_otter_revenue(int player_money, int number_sea_otters) {

	player_money = player_money + number_sea_otters*(250);
	return player_money;

}
/*********************************************************************
** Function: add_baby_sea_otter_revenue(int,int)
** Description: adds baby sea otter revenue
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns int
*********************************************************************/ 
int sea_otter::add_baby_sea_otter_revenue(int player_money, int number_sea_otters) {

	player_money = player_money + number_sea_otters*(500);
	return player_money;

}
