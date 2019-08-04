#ifndef SEAOTTER_H
#define SEAOTTER_H

#include "./animal.h"
class sea_otter : public animal {

private:
	
public:
	sea_otter();
	int add_sea_otter_revenue(int player_money, int number_sea_otters);
	int add_baby_sea_otter_revenue(int player_money, int number_sea_otters);

};

#endif