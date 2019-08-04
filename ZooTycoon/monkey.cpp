#include <iostream>
#include "./monkey.h"

using namespace std;

/*********************************************************************
** Function: monkey
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/ 
monkey::monkey() {
	
}
/*********************************************************************
** Function: add_monkey_revenue
** Description: adds monkey revenue
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns int
*********************************************************************/ 
int monkey::add_monkey_revenue(int player_money, int number_monkeys) {

	player_money = player_money + number_monkeys*(1500);
	return player_money;

}
/*********************************************************************
** Function: add_baby_monkey_revenue
** Description: adds baby monkey revenue
** Parameters: int, int
** Pre-Conditions: int, int
** Post-Conditions: returns int
*********************************************************************/ 
int monkey::add_baby_monkey_revenue(int player_money, int number_monkeys) {

	player_money = player_money + number_monkeys*(3000);
	return player_money;

}





