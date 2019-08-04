#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "./zoo.h"

using namespace std;
/*********************************************************************
** Function: zoo
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: initializes a lot of values
*********************************************************************/ 
zoo::zoo() {
	n_baby_monkeys = 0;
	n_baby_sea_otters = 0;
	n_monkeys = 0;
	n_sea_otters = 0;
	n_sloths = 0;
	n_baby_sloths = 0;
	money = 100000;
	feed_cost_MONKEY = 50;
	feed_cost_SEA = 50;
	feed_cost_SLOTH = 50;
	monkeys = NULL;
	sea_otters = NULL;
	sloths = NULL;
	game_over = false;
}
/*********************************************************************
** Function: userinput
** Description: takes in user input and returns the value
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns user input
*********************************************************************/ 
int zoo::userinput() {
	int input, number;
	bool flag = false;
	while(flag == false) {
		cout << "[1]. Monkey ($15,000)\n"
				"[2]. Sea Otter($5,000)\n"
				"[3]. Sloth($2,000)\n" 
				"[4]. You don't have enough money" << endl;
		cout << "input: ";
		cin >> input;

		if(input == 1 && get_money() > 15000) {
			flag = true;
		}
		if(input == 2 && get_money() > 5000) {
			flag = true;
		}
		if(input == 3 && get_money() > 2000) {
			flag = true;
		}
		if(get_money() < 2000) {
			cout << "You don't have enough money so no purchasing!" << endl;
			input = 0;
			flag = true;
		}
	}
	return input;
	
}
/*********************************************************************
** Function: howMany
** Description: asks the user how many monkeys they would like
** Parameters: int input
** Pre-Conditions: int input
** Post-Conditions: deducts x amount of money after purchasing
*********************************************************************/ 
void zoo::howMany(int input) {
	int number;
	bool flag = false;

	if(input == 1) {
		while(flag == false) {
		cout << "How many Monkeys would you like?" << endl;
		cin >> number;
			if(number <= 2 && number > 0 && get_money() > (number*15000)) {
				cout << "Great you've added " << number << " monkeys" << endl;
				add_monkey(number); //THIS IS WHERE IM TRYING TO ADD A MONKEY 
				flag = true;
				int deduction = number*15000;
				money = money-deduction;
				set_money(money);
				cout << "Your bank is now: " << get_money() << endl;
			}
			else {
				cout << "You can't buy that many..." << endl;
			}
			
		}
	}
	if(input == 2) {
		while(flag == false) {
		cout << "How many Sea Otters would you like?" << endl;
		cin >> number;
			if(number <= 2 && number > 0) {
				cout << "Great you've added " << number << " Sea Otters" << endl;
				add_sea_otters(number);
				flag = true;
				int deduction = number*5000;
				set_money(money-deduction);
				cout << "Your bank is now: " << get_money() << endl;
			}
			else {
				cout << "You can't buy that many..." << endl;
			}
			
		}
	}
	if(input == 3) {
		while(flag == false) {
		cout << "How many sloths would you like?" << endl;
		cin >> number;
			if(number <= 2 && number > 0) {
				cout << "Great you've added " << number << " sloths" << endl;
				add_sloths(number);
				flag = true;
				int deduction = number*2000;
				set_money(money-deduction);
				cout << "Your bank is now: " << get_money() << endl;
			}
			else {
				cout << "You can't buy that many..." << endl;
			}
			
		}
	}
	else{
		return;
	}
	
}
/*********************************************************************
** Function: set_money
** Description: sets the money
** Parameters: int Amoney
** Pre-Conditions: int
** Post-Conditions: sets the parameter money as the money
*********************************************************************/ 
void zoo::set_money(int Amoney) {
	money = Amoney;
}
/*********************************************************************
** Function: get_money
** Description: returns the money
** Parameters: n/a
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo:: get_money() {
	return money;
}
/*********************************************************************
** Function: add_monkey
** Description: adds a monkey 
** Parameters: int number
** Pre-Conditions: int number
** Post-Conditions: adds the number to the number of monkeys
*********************************************************************/ 
void zoo::add_monkey(int number) {
	n_monkeys = n_monkeys + number;
	monkey* temp = new monkey[n_monkeys];
	if(number != -1) { //ADDS NORMAL ADULTS
		for(int i = 0; i < n_monkeys-number; i++) {
			temp[i] = monkeys[i];
		}

		for(int i = n_monkeys-number; i < n_monkeys; i++) {
			temp[i].set_age(1095);
		}
	}
	if(number == -1) { //IF YOU ADD BABY DO -1
		n_monkeys = n_monkeys + 1;
		for(int i = 0; i < n_monkeys-number; i++) {
			temp[i] = monkeys[i];
		}

		for(int i = n_monkeys - 1; i< n_monkeys; i++) {
			temp[i].set_age(0);
			n_baby_monkeys = n_baby_monkeys + 1;
		}
		cout << "You now have: " << n_baby_monkeys << " baby monkeys" << endl;
	}

delete [] monkeys;
monkeys = temp;
}
/*********************************************************************
** Function: add_sea_otters
** Description: adds a sea otter
** Parameters: int number
** Pre-Conditions: int number
** Post-Conditions: adds the number to the number of sea otters
*********************************************************************/ 
void zoo::add_sea_otters(int number) {
	n_sea_otters = n_sea_otters + number;
	sea_otter* temp = new sea_otter[n_sea_otters];
	if(number != -1) {	
		for(int i = 0; i < n_sea_otters-number; i++) {
			temp[i] = sea_otters[i];
		}
		
		for(int i = n_sea_otters-number; i < n_sea_otters; i++) {
			temp[i].set_age(1095);
		}
	}
	if(number == -1) { //IF YOU ADD BABY DO -1
		n_sea_otters = n_sea_otters + 2;
		for(int i = 0; i < n_sea_otters-number; i++) {
			temp[i] = sea_otters[i];
		}
	
		for(int i = n_sea_otters - 1; i< n_sea_otters; i++) {
			temp[i].set_age(0);
			n_baby_sea_otters = n_baby_sea_otters + 1;
		}
		cout << "You now have: " << n_baby_sea_otters << " baby sea otters" << endl;
	}
delete [] sea_otters;
sea_otters = temp;
}
/*********************************************************************
** Function: adds_sloths
** Description: adds a sloth
** Parameters: int number
** Pre-Conditions: int number
** Post-Conditions: adds the number to the number of sea otters
*********************************************************************/ 
void zoo::add_sloths(int number) {
	n_sloths = n_sloths + number;
	sloth* temp = new sloth[n_sloths];
	if(number != -1) {
		for(int i = 0; i < n_sloths-number; i++) {
			temp[i] = sloths[i];
		}

		for(int i = n_sloths-number; i < n_sloths; i++) {
			temp[i].set_age(1095);
		}
	}
	if(number == -1) {
		n_sloths = n_sloths +3;
		for(int i = 0; i < n_sloths-number; i++) {
			temp[i] = sloths[i];
		}
		for(int i = n_sloths - 1; i < n_sloths; i++) {
			temp[i].set_age(0);
			n_baby_sloths = n_baby_sloths + 1;
		}
		cout << "You now have: " << n_baby_sloths << " baby sloths" << endl;
	}
delete [] sloths;
sloths = temp;
}
/*********************************************************************
** Function: feed_animals
** Description: feeds animal
** Parameters: int day
** Pre-Conditions: int day
** Post-Conditions: deducts from money depending on choice
*********************************************************************/ 
int zoo::feed_animals(int day) {
	string input;
	bool flag = false;
	int regular_chance = rand() % 4 + 1;
	int half_chance = rand() % 8 + 1;
	int double_chance = rand() % 2 + 1;
	double random_multiplier = (double)(rand() % 50 + 75)/100;
	int total = feed_cost_MONKEY+feed_cost_SEA+feed_cost_SLOTH;
	while(flag == false) {
		cout << "What kind of feed do you want to use?\n"
				"[1]. Regular\n"
				"[2]. Premium\n"
				"[3]. Cheap" << endl;
		cout << "Input: ";		
		cin >> input;
		if(input == "1") {
			cout << "You have " << n_monkeys << " Monkeys, " << n_sea_otters << " sea otters, and " << n_sloths << " sloths" << endl;
			feed_cost_MONKEY = (random_multiplier*feed_cost_MONKEY*n_monkeys);
			feed_cost_SEA = (random_multiplier*feed_cost_SEA*n_sea_otters);
			feed_cost_SLOTH = ((random_multiplier*feed_cost_SLOTH*n_monkeys));
			total = feed_cost_MONKEY+feed_cost_SEA+feed_cost_SLOTH;
			cout <<"Your food cost is: " << total << endl;
			money = money - total;
			if(money < 0) {
				cout << "You have no more money! good game." << endl;
				game_over = true;
			}
			cout <<"Your current balance is now: " << money << endl;
			flag = true;
			return regular_chance;
		}
		if(input == "2") {
			cout << "You have " << n_monkeys << " Monkeys, " << n_sea_otters << " sea otters, and " << n_sloths << " sloths" << endl;
			feed_cost_MONKEY = (2*random_multiplier*feed_cost_MONKEY*n_monkeys);
			feed_cost_SEA = (2*random_multiplier*feed_cost_SEA*n_sea_otters);
			feed_cost_SLOTH = ((2*random_multiplier*feed_cost_SLOTH*n_monkeys));
			total = feed_cost_MONKEY+feed_cost_SEA+feed_cost_SLOTH;
			cout <<"Your food cost is: " << total << endl;
			money = money - total;
			//cout << "THIS IS DA MONEY" << money << endl;
			if(money < 0) {
				cout << "You have no more money! good game." << endl;
				game_over = true;
			}
			cout <<"Your current balance is now: " << money << endl;
			flag = true;
			if(half_chance == 1 || half_chance == 3){
				return 2;
			}
			if(half_chance == 5 || half_chance == 7) {
				return 3;
			}
			if(half_chance == 2 || half_chance == 4 || half_chance == 6 || half_chance == 8) {
				return 4;
			}
			
		}
		if(input == "3") {
			cout << "You have " << n_monkeys << " Monkeys, " << n_sea_otters << " sea otters, and " << n_sloths << " sloths" << endl;
			double random_multiplier = (double)(rand() % 50 + 75)/100;
			feed_cost_MONKEY = ((random_multiplier*feed_cost_MONKEY*n_monkeys)/2);
			feed_cost_SEA = ((random_multiplier*feed_cost_SEA*n_sea_otters)/2);
			feed_cost_SLOTH = ((random_multiplier*feed_cost_SLOTH*n_monkeys)/2);
			total = feed_cost_MONKEY+feed_cost_SEA+feed_cost_SLOTH;
			cout <<"Your food cost is: " << total << endl;
			money = money - total;
			if(money < 0) {
				cout << "You have no more money! good game." << endl;
				game_over = true;
			}
			cout <<"Your current balance is now: " << money << endl;
			flag = true;
			if(double_chance == 1) {
				return 4;
			}
			if(double_chance == 2) {
				return 1;
			}
		}
		else {
			cout << "You didn't enter an option" << endl;
		}
		
	}
}
/*********************************************************************
** Function: random_occurance
** Description: chooses one of the random occurances using a randomizer number from the feed animal function
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: deducts from money depending on the random occurance
*********************************************************************/ 
void zoo::random_occurance(int randomizer) {
	bool flag = false;
	cout << "Now you have to deal with a random occurance..." << endl;
	int randNum = rand()% 3 + 1;
	if(randomizer == 1) {
		cout << "One randomly chosen animal gets sick! If you have enough money, you have to pay for it. If you don't, then it dies" << endl;
		while(flag == false) {
			randNum = rand() % 3 + 1;
			if(randNum == 1) {
			 	if(n_monkeys != 0 && get_money() >= 7500) {
			 		money = money - 7500;
			 		cout << "Oh no, one of your monkeys got sick. You must now pay $7500" << endl;
			 		cout <<"Your current balance is now: " << money << endl;
			 		flag = true;
			 	}
				if(n_monkeys != 0 && get_money() < 7500) {
					n_monkeys--;
					flag = true;
				}
				if(n_monkeys != 0 && get_money() <= 0) {
					cout << "You have no more money! good game." << endl;
					flag = true;
					game_over = true;
				}
			}
			if(randNum == 2) {
				if(n_sea_otters != 0) {
			 		money = money - 2500;
			 		cout << "Oh no, one of your sea otters got sick. You must now pay $2500" << endl;
			 		cout <<"Your current balance is now: " << money << endl;
			 		flag = true;
			 	}
			 	if(n_sea_otters != 0 && get_money() < 2500) {
					n_sea_otters--;
					flag = true;
				}
				if(n_sea_otters != 0 && get_money() <= 0) {
					cout << "You have no more money! good game." << endl;
					flag = true;
					game_over = true;
				}
			}
			if(randNum == 3) {
				if(n_sloths != 0) {
					money = money-1000;
					cout << "Oh no, one of your sloths got sick. You must now pay $1000" << endl;
					cout << "Your current balance is now: " << money << endl;
					flag = true;
				}
				if(n_sloths != 0 && get_money() < 1000) {
					n_sloths--;
					flag = true;
				}
				if(n_sloths != 0 && get_money() <= 0) {
					cout << "You have no more money! good game." << endl;
					flag = true;
					game_over = true;
				}
			}
		}
	}

	if(randomizer == 2) {
		cout << "One of your random adult animals gives birth!!" << endl;
		bool is_animal = false;
		while(is_animal == false) {
			//randNum = rand()%3 + 1;
			randNum = 1;
			if(randNum == 1 && check_adult_monkeys() == true) {
				cout << "boom, monkey baby!" << endl;
				add_monkey(-1);
				is_animal = true;
			}
			if(randNum == 2 && check_adult_sea_otters() == true) {
				cout << "boom, sea otter baby!" << endl;
				add_sea_otters(-1);
				is_animal = true;
			}
			if(randNum == 3 && check_adult_sloths() == true) {
				cout << "boom, sloth baby!" << endl;
				add_sloths(-1);
				is_animal = true;
			}
			else if(check_adult_monkeys() == false && check_adult_sea_otters() == false && check_adult_sloths() == false) {
				cout << "You have no adult monkeys, sea otters, or sloths..." << endl;
			}
		}
	}

	if(randomizer == 3) {
		cout << "A boom in zoo attendance, your monkeys will now generate you some money!" << endl;
		double random_revenue = 0;
		double total_revenue = 0;
		if(n_monkeys != 0) {
			for(int i = 0; i < n_monkeys; i++) {
				random_revenue = (double)(rand() % 250 + 251);
				money = money + random_revenue;
				cout << "1 monkey gave you " << random_revenue << endl;
				total_revenue = random_revenue + total_revenue;
			}
			cout << "Your monkeys gave you " << total_revenue << " dollars, and your total now is: " << money << " dollars" << endl;
		}


	}

	if(randomizer == 4) {
		cout << "No special event occured!" << endl;
	}
}
/*********************************************************************
** Function: check_adult_monkeys
** Description: checks to see if adult monkeys are in the array
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: returns true or false
*********************************************************************/ 
bool zoo::check_adult_monkeys() {

	for(int i = 0; i < n_monkeys; i++) {
		if(monkeys[i].get_age() >= 30) {
			return true;
		}
	}
	return false;
}
/*********************************************************************
** Function: check_adult_sea_otters
** Description: checks to see if there are adult sea otters in the array
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: returns true or false 
*********************************************************************/ 
bool zoo::check_adult_sea_otters() {

	for(int i = 0; i < n_sea_otters; i++) {
		if(sea_otters[i].get_age() >= 30) {
			return true;
		}
	}
	return false;
}
/*********************************************************************
** Function: check_adult_sloths
** Description: checks to see if there are adult sloths in the array
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: returns true or false
*********************************************************************/ 
bool zoo::check_adult_sloths() {

	for(int i = 0; i < n_sloths; i++) {
		if(sloths[i].get_age() >= 30) {
			return true;
		}
	}
	return false;
}
/*********************************************************************
** Function: number_adult_monkeys
** Description: checks to see how many adult monkeys are in the array
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo::number_adult_monkeys() {
	int counter = 0;
	for(int i = 0; i < n_monkeys; i++) {
		if(monkeys[i].get_age() >= 30) {
			counter++;
		}
	}
	return counter;
}
/*********************************************************************
** Function: number_baby_monkeys
** Description: checks to see how many baby monkeys are in the array
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo::number_baby_monkeys() {

	int counter = 0;
	for(int i = 0; i < n_monkeys; i++) {
		if(monkeys[i].get_age() < 30) {
			counter++;
		}
	}
	return counter;

}
/*********************************************************************
** Function: number_adult_sea_otters
** Description: checks to see how many adult sea otters are in the array
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo::number_adult_sea_otters() {
	
	int counter = 0;
	for(int i = 0; i < n_sea_otters; i++) {
		if(sea_otters[i].get_age() >= 30) {
			counter++;
		}
	}
	return counter;

}
/*********************************************************************
** Function: number_baby_sea_otters
** Description: checks to see how many baby sea otters are in the array
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo::number_baby_sea_otters() {

	int counter = 0;
	for(int i = 0; i < n_sea_otters; i++) {
		if(sea_otters[i].get_age() < 30) {
			counter++;
		}
	}
	return counter;

}
/*********************************************************************
** Function: number_adult_sloths
** Description: checks to see how many adult sloths are in the array
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo::number_adult_sloths() {

	int counter = 0;
	for(int i = 0; i < n_sloths; i++) {
		if(sloths[i].get_age() >= 30) {
			counter++;
		}
	}
	return counter;

}
/*********************************************************************
** Function: number_baby_sloths
** Description: checks to see how many baby sloths are in the array
** Parameters: int
** Pre-Conditions: int 
** Post-Conditions: returns int
*********************************************************************/ 
int zoo::number_baby_sloths() {

	int counter = 0;
	for(int i = 0; i < n_baby_sloths; i++) {
		if(sloths[i].get_age() < 30) {
			counter++;
		}
	}
	return counter;

}
/*********************************************************************
** Function: increment_age
** Description: increments the age
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: increments animal age
*********************************************************************/ 
void zoo::increment_age() {
	int original_monkeys_age = 0;
	int original_sea_otters_age = 0;
	int original_sloths_age = 0;
	cout << "--------Your monkey's ages:-----------" << endl;
	for(int i = 0; i < n_monkeys; i++) {
		original_monkeys_age = monkeys[i].get_age()+1; 
		monkeys[i].set_age(original_monkeys_age);
		cout << i+1 << " Monkey Age: " << monkeys[i].get_age() << " days \n";
	}
	cout << "\n--------Your sea_otters' ages:-----------" << endl;
	for(int i = 0; i < n_sea_otters; i++) {
		original_sea_otters_age = sea_otters[i].get_age() + 1;
		sea_otters[i].set_age(original_sea_otters_age);
		cout << i+1 << " Sea Otters Age: " << sea_otters[i].get_age() << " days \n";
	}
	cout << "\n--------Your sloths' ages:-----------" << endl;
	for(int i = 0; i < n_sloths; i++) { 
		original_sloths_age = sloths[i].get_age() + 1;
		sloths[i].set_age(original_sloths_age);
		cout << i+1 << " Sloths' Age: " << sloths[i].get_age() << " days \n";
	}	
	cout << endl;
}
/*********************************************************************
** Function: check_game_over
** Description: checks to see if the game is over
** Parameters: bool
** Pre-Conditions: int turn
** Post-Conditions: returns true or false
*********************************************************************/ 
bool zoo::check_game_over(int turn) {

	if(game_over == true) {
		cout << "YOU LASTED " << turn << " DAYS! Good Game! " << endl;
		return true;
	}
	return false;

}
/*********************************************************************
** Function: revenue
** Description: increases users money
** Parameters: void
** Pre-Conditions: void 
** Post-Conditions: increases user money
*********************************************************************/ 
void zoo::revenue() {
	monkey monkeys;
	int add_baby_monkey_revenue = number_baby_monkeys()*(3000);
	int number_monkeys = number_adult_monkeys();
	int add_monkey_revenue = number_monkeys*(1500);
	int number_sea_otters = number_adult_sea_otters();
	int add_sea_otter_revenue = number_sea_otters*(250);
	cout << "Time for revenue!" << endl;
	cout << "You have " << n_monkeys << " Total Monkeys, " << n_sea_otters << " Total sea otters, and " << n_sloths << " Total sloths (including babies)" << endl;
	cout << "You have " << n_baby_monkeys << " Baby Monkeys, " << n_baby_sea_otters << " baby sea otters, and " << n_baby_sloths << " baby sloths " << endl;
	cout << "Your Adult Monkeys made you: " << add_monkey_revenue << endl;
	money = number_monkeys*(1500) + money;
	cout << "Your Baby Monkeys made you: " << add_baby_monkey_revenue << endl;
	money = number_baby_monkeys()*3000 + money;
	cout << "Your Adult Sea Otters made you: " << add_sea_otter_revenue << endl;
	money = money + add_sea_otter_revenue;
	cout << "Your Baby Sea Otters made you: " << number_baby_sea_otters() * (500) << endl;
	money = money + (number_baby_sea_otters()*500);
	cout << "Your Adult Sloths made you: " << number_adult_sloths() *(100) << endl;
	money = money + number_adult_sloths() *100;
	cout << "Your Baby Sloths made you: " << number_baby_sloths() *(200) << endl;
	money = money + (number_baby_sloths()*(200));
	cout << "Your current balance is now: " << money << endl;
}
/*********************************************************************
** Function: ~zoo
** Description: deconstructs animal arrays
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: deletes arrays
*********************************************************************/ 
zoo::~zoo() {

	delete [] monkeys;
	delete [] sea_otters;
	delete [] sloths;

}