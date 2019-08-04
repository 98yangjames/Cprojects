#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
#include "econdata.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	string line, target;
	state wantedState;
	int numberStates, input;
	state *sss;
	county *ccc;
	cout << "this is what u entered: " << argv[1] << endl;
	if(check_arguments(argc, argv) == false) {
		cout << "Try again, enter " << endl;
		exit(0);
	}
	else {
		ifstream testfile ("test_data.txt");
		if (testfile.is_open() == true) {
			cout << "The file has opened" << endl;
		}
		testfile >> numberStates;

		if (check_states(numberStates) == true) {
			sss = allocate_states(numberStates);
			read_state_data(sss, numberStates, testfile);
			read_county_data(ccc, numberStates, testfile);
			sort_median_income(sss, numberStates);
			sort_employment_rate(sss, numberStates);
			wantedState = instructions(sss, numberStates);
			display();
			bool flag = false;
			do {
				cout << " What do you want to know? " << endl;
				cin >> input;
				if(input == 1) {
					county_median_income(wantedState);
				}
				if(input == 2) {
					county_unemployment(wantedState);
				}
				if(input == 3) {
					county_unemployment_difference(wantedState);
				}
				if(input == 4) {
					sort_county_income(wantedState);
				}
				if(input == 5) {
					cout << "Program ended" << endl;
					flag = true;
				}

			}
			while(flag == false);
		}
		free_state_data(sss, numberStates);
	}
}
