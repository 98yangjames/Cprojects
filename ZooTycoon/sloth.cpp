#include <iostream>
#include "./sloth.h"

using namespace std;

/*********************************************************************
** Function: sloth
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
sloth::sloth() {

	
}


/*********************************************************************
** Function: add_sloth_revenue(int,int)
** Description: adds sloth revenue
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns int
*********************************************************************/ 
int sloth::add_sloth_revenue(int player_money, int number_sloths) {

	player_money = player_money + number_sloths*(100);
	return player_money;

}
/*********************************************************************
** Function: add_baby_sloth_revenue
** Description: adds baby sloth revenue
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns int
*********************************************************************/ 
int sloth::add_baby_sloth_revenue(int player_money, int number_sloths) {

	player_money = player_money + number_sloths*(200);
	return player_money;

}