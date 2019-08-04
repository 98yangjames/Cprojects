#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "./animal.h"
#include "./monkey.h"
#include "./seaotter.h"
#include "./sloth.h"
class zoo {
private:
	double money;
	double feed_cost_MONKEY;
	double feed_cost_SEA;
	double feed_cost_SLOTH; // how much the base cost of feeding an animal is
	int n_monkeys;
	int n_baby_monkeys;
	int n_sea_otters;
	int n_baby_sea_otters;
	int n_sloths;
	int n_baby_sloths;
	monkey* monkeys;
	sea_otter* sea_otters;
	sloth* sloths;
	bool game_over;

public:
	zoo();
	void add_monkey(int);
	void add_sea_otters(int);
	void add_sloths(int);
	void howMany(int);
	int userinput();
	int player_money();
	void set_money(int);
	int get_money();
	int feed_animals(int);
	bool check_adult_monkeys();
	bool check_adult_sea_otters();
	bool check_adult_sloths();
	int number_adult_monkeys();
	int number_baby_monkeys();
	int number_adult_sea_otters();
	int number_baby_sea_otters();
	int number_adult_sloths();
	int number_baby_sloths();
	void random_occurance(int);
	void increment_age();
	bool check_game_over(int);
	void revenue();
	~zoo();

};

#endif