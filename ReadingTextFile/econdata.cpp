/*********************************************************************
** Program Filename: econdata.cpp
** Author: James Yang
** Date: 1/16/19
** Description: Explores economic data written in a file
** Input: txt file of data in a specific format
** Output: seperated information within that file
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
#include "econdata.hpp"

using namespace std;
/*********************************************************************
** Function: check_arguments
** Description: checks if the user inputed "test_data.txt"
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: returns true or false
*********************************************************************/ 
bool check_arguments(int argc, char *argv[]) {
	
	if (argc != 2) {
		cout << "Invalid Arguments (Just enter explore_econdata test_data.txt)" << endl;
		return false;
	}

	if(strcmp(argv[1], "test_data.txt") == 0) {
		return true;
	}

	return false;
}
/*********************************************************************
** Function: check_states
** Description: checks if the number of states is valid within the amount found in the document
** Parameters: bool
** Pre-Conditions: bool
** Post-Conditions: returns true or false
*********************************************************************/ 
bool check_states(int numberStates) { //this is very useless but whatever lol
	if (numberStates > 3) {
		bool flag = false;
		while (flag == false) {
			cout << "Try again, how many states do you want to see?" << endl;
			cin >> numberStates;
			if(numberStates <= 3 && numberStates > 0) {
				flag = true;
			}
		}
	}
	return true;
}
/*********************************************************************
** Function: allocate_states
** Description: opens up the amount of states in a struct 
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: allocates memory for the number of states
*********************************************************************/ 
struct state* allocate_states(int numberStates) {
	state *sss = new state[numberStates];
	return sss;
}
/*********************************************************************
** Function: allocate_states
** Description: opens up the amount of county in a struct 
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: allocates memory for the number of counties
*********************************************************************/ 
struct county* allocate_counties(int numberCounties) {
	county *ccc = new county[numberCounties];
	return ccc;
}
/*********************************************************************
** Function: read_county_data
** Description: takes in the file and creates arrays for the data
** Parameters: struct, int, ifstream
** Pre-Conditions: struct, int, ifstream
** Post-Conditions: creates array for each individual coloumn
*********************************************************************/ 
void read_county_data(struct county* ccc, int counties, ifstream &testfile) {
	for (int i = 0; i < counties; i++) {
		testfile >> ccc[i].name;
		testfile >> ccc[i].unemployed_2007;
		testfile >> ccc[i].unemployed_2015;
		testfile >> ccc[i].med_income;
	}
}
/*********************************************************************
** Function: read_state_data
** Description: takes in the file and creates arrays for the data
** Parameters: struct, int, ifstream
** Pre-Conditions: struct, int, ifstream variable
** Post-Conditions: creates array for each individual coloumn
*********************************************************************/ 
void read_state_data(struct state* sss, int numberStates, ifstream &testfile) {
	int counties;
	
	for(int i = 0; i < numberStates; i++) {
		testfile >> sss[i].name;
		testfile >> sss[i].unemployed_2007;
		testfile >> sss[i].unemployed_2015;
		testfile >> sss[i].med_income;
		testfile >> counties;
		sss[i].n_counties = counties;
		sss[i].counties = allocate_counties(counties);
		read_county_data(sss[i].counties, counties, testfile);
	}
}
/*********************************************************************
** Function: county_unemployment_difference
** Description: subtracts the county difference in unemployment 
** Parameters: state struct
** Pre-Conditions: state struct, ifstream variable
** Post-Conditions: the value of the differences in sorted order
*********************************************************************/ 
void county_unemployment_difference (state wantedState) {
	county *counties = wantedState.counties;
	int numCounties = wantedState.n_counties;
	int temp;
	string name, name2;
	for(int i = 0; i < numCounties-1; i++) {
		for (int j = 0; j < numCounties-1; j++) {
			if((counties[j].unemployed_2015 - counties[j].unemployed_2007) > (counties[j+1].unemployed_2015- counties[j+1].unemployed_2007)) {
				struct county temp = counties[j];
				counties[j] = counties[j + 1];
				counties[j + 1] = temp;
			}			
		}
	}
	cout << "This is the order of states' unemployment from least to greatest: " << endl;
	for (int i = 0; i < numCounties; i++) {
		name = counties[i].name;
		cout << name << endl;
	}
}
/*********************************************************************
** Function: sort_county_income
** Description: sorts the counties income highest/lowest
** Parameters: state struct
** Pre-Conditions: state struct
** Post-Conditions: county highest/lowest income
*********************************************************************/ 
void sort_county_income (state wantedState) {
	county *counties = wantedState.counties;
	int numCounties = wantedState.n_counties;
	int temp;
	string name, name2;
	for(int i = 0; i < numCounties-1; i++) {
		for (int j = 0; j < numCounties-1; j++) {
			if(counties[j].med_income > counties[j+1].med_income) {
				struct county temp = counties[j];
				counties[j] = counties[j+1];
				counties[j+1] = temp;				
			}			
		}
	}
	for(int i = 0; i < numCounties; i++) {
		cout << counties[i].name << endl;
	}
	int temp2 = 0;
	cout << "This is the counties in sorted order based on median household income from least to greatest: " <<endl;
}
/*********************************************************************
** Function: county_median_income
** Description: sorts the counties with highest/lowest median income
** Parameters: state struct
** Pre-Conditions: state struct
** Post-Conditions: the counties sorted by income
*********************************************************************/ 
void county_median_income (state wantedState) {
	county *counties = wantedState.counties;
	int numCounties = wantedState.n_counties;
	string name, name2;
	int temp2 = 0;
	int temp3 = 0;
	for (int i = 0; i < numCounties; i++) {
		if(counties[i].med_income > temp3) {
			temp3 = counties[i].med_income;
			name2 = counties[i].name;
		}
	}
	cout << "This is the county in that state with the highest median household income: " << name2 << " " << temp3 << endl;

	int temp = 1000000000;
	for (int i = 0; i < numCounties; i++) {
		if(counties[i].med_income < temp) {
			temp = counties[i].med_income;
			name = counties[i].name;
		}
	}
	cout << "This is the state with the lowest median household income: " << name << " " << temp << endl;
}
/*********************************************************************
** Function: county_unemployment
** Description: sorts highest/lowest county unemployment
** Parameters: state struct
** Pre-Conditions: state struct
** Post-Conditions: sorts the counties by highest/lowest county unemployment
*********************************************************************/ 
void county_unemployment (state wantedState) {
	county *counties = wantedState.counties;
	int numCounties = wantedState.n_counties;
	string name, name2;
	float temp2 = 0;
	for (int i = 0; i < numCounties; i++) {
		if(counties[i].unemployed_2015 > temp2) {
			temp2 = counties[i].unemployed_2015;
			name = counties[i].name;
		}
	}
	cout << "This is the county with the highest unemployment rate: " << name << " " << temp2 << endl;
	float temp3 = 10;
	for (int i = 0; i < numCounties; i++) {
		if(counties[i].unemployed_2015 < temp3) {
			temp3 = counties[i].unemployed_2015;
			name2 = counties[i].name;
		}
	}
	cout << "This is the county with the lowest unemploment rate: " << name2 << " " << temp3 << endl;
}
/*********************************************************************
** Function: sort_median_income
** Description: takes in the amount of states and state struct and sorts by highest/lowest median income
** Parameters: state struct, int numberStates
** Pre-Conditions: struct state, int numberStates
** Post-Conditions: sorts the value by states
*********************************************************************/ 
void sort_median_income (struct state* sss, int numberStates) {
	int temp;
	string name, name2;
	for(int i = 0; i < numberStates-1; i++) {
		for (int j = 0; j < numberStates-1; j++) {
			if(sss[j].med_income > sss[j+1].med_income) {
				struct state temp = sss[j];
				sss[j] = sss[j + 1];
				sss[j + 1] = temp;
			}			
		}
	}

	int temp2 = 0;
	cout << "This is the states in sorted order based on median household income from least to greatest: " << endl;
	for (int k = 0; k < numberStates; k++) {
		cout << sss[k].name << endl;
		if(sss[k].med_income > temp2) {
			temp2 = sss[k].med_income;
			name = sss[k].name;
		}
	}
	cout << "This is the state with the highest median household income: " << name << " " << temp2 << endl;
	
	int temp3 = 1000000000;
	for (int i = 0; i < numberStates; i++) {
		if(sss[i].med_income < temp3) {
			temp3 = sss[i].med_income;
			name2 = sss[i].name;
		}
	}
	cout << "This is the state with the lowest median household income: " << name2 << " " << temp3 << endl;
}
/*********************************************************************
** Function: sort_employment_rate
** Description: sorts the states by employment rate
** Parameters: struct state, int numberStates
** Pre-Conditions: struct state, int numberStates
** Post-Conditions: sorts the median income
*********************************************************************/ 
void sort_employment_rate(struct state* sss, int numberStates) {
	float temp;
	string name, name2, name3;
	for(int i = 0; i < numberStates-1; i++) {
		for (int j = 0; j < numberStates-1; j++) {
			if(sss[j].unemployed_2015 > sss[j+1].unemployed_2015) {
				struct state temp = sss[j];
				sss[j] = sss[j + 1];
				sss[j + 1] = temp;
			}			
		}
	}
	float temp2 = 0;
	for (int i = 0; i < numberStates; i++) {
		if(sss[i].unemployed_2015 > temp2) {
			temp2 = sss[i].unemployed_2015;
			name = sss[i].name;
		}
	}
	cout << "This is the state with the highest unemployment rate: " << name << " " << temp2 << endl;
	float temp3 = 10;
	for (int i = 0; i < numberStates; i++) {
		if(sss[i].unemployed_2015 < temp3) {
			temp3 = sss[i].unemployed_2015;
			name2 = sss[i].name;
		}
	}

	cout << "This is the state with the lowest unemploment rate: " << temp3 << endl;
	float temp4[numberStates];  //THIS PART ISNT FINISHED YET


	for(int i = 0; i < numberStates-1; i++) {
		for (int j = 0; j < numberStates-1; j++) {
			if((sss[j].unemployed_2015 - sss[j].unemployed_2007) > (sss[j+1].unemployed_2015- sss[j+1].unemployed_2007)) {
				struct state temp4 = sss[j];
				sss[j] = sss[j + 1];
				sss[j + 1] = temp4;
			}			
		}
	}
	cout << "This is the order of states' unemployment from least to greatest: " << endl;
	for (int i = 0; i < numberStates; i++) {
		name3 = sss[i].name;
		cout << name3 << endl;
	}
}
/*********************************************************************
** Function: instructions
** Description: asks the user which state they want and then goes through the file and determines where the sort functions should start
** Parameters: struct state, int numberStates
** Pre-Conditions: struct state, int numberStates
** Post-Conditions: sorting functions start/end where the state is specified
*********************************************************************/ 
state instructions(struct state* sss, int numberStates) {
	bool foundState = false;
	state wantedState;
	cout << "Here is a list of states you can choose: " << endl;
	for (int i = 0; i < numberStates; i++) {
		cout << sss[i].name << endl;
	}
	string choice;
	while (foundState == false) {
	cout << "Enter state: ";
	cin >> choice;
		for(int i = 0; i < numberStates; i++) {
			if(strcmp(&choice[0], &sss[i].name[0]) == 0) {
				wantedState = sss[i];
				foundState = true;
			}
		}
	}
	return wantedState;
}
/*********************************************************************
** Function: display
** Description: displays instructions
** Parameters: nothing
** Pre-Conditions: nothing
** Post-Conditions: couts the statement below
*********************************************************************/ 
void display() {
			cout << "[1]. Print the county in that state with the highest/lowest median household income.\n"
			"[2]. Print the county in that state with the highest/lowest unemployment in 2015.\n"
			"[3]. Print the counties in that state in sorted order by change in unemployment from 2007 to 2015 (i.e. start with the largest decrease in unemployment and end with the largest increase in unemployment)\n"
			"[4]. Print the counties in that state in sorted order based on median household income.\n" 
			"[5]. Exit the program" << endl;
}
/*********************************************************************
** Function: free_state_data
** Description: frees the arrays
** Parameters: struct state, int numberstates
** Pre-Conditions: struct state, int numberstates
** Post-Conditions: deletes the arrays so no lost memory
*********************************************************************/ 
void free_state_data(struct state* sss, int numberStates) {
	for(int i = 0; i < numberStates; i++) {
		delete [] sss[i].counties;
	}
	delete[] sss;
	sss = NULL;
}
