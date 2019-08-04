#ifndef MONKEY_H
#define MONKEY_H

#include "./animal.h"

class monkey : public animal {

private:

public:
	monkey();
	int add_monkey_revenue(int player_money, int number_monkeys);
	int add_baby_monkey_revenue(int player_money, int number_monkeys);

};

#endif