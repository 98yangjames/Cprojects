#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class animal {

private:
	int age;
	int cost;
	int babies;
	int food_cost;
	int revenue;

public:

	animal();
	animal(int Aage, int Acost);
	void set_age(int);
	void set_cost(int);
	void set_food_cost(int);
	int get_age();
	int get_cost();
	void set_revenue(int);
	int get_revenue();
};

#endif