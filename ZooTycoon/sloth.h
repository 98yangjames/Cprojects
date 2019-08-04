#ifndef SLOTH_H
#define SLOTH_H

#include "./animal.h"
class sloth : public animal {

private:
	
public:
	sloth();
	int add_sloth_revenue(int player_money, int number_sea_otters);
	int add_baby_sloth_revenue(int player_money, int number_sea_otters);


};

#endif