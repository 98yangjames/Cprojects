#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>


using namespace std;

struct county {
  string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
};
struct state {
  string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  struct county* counties;
  int n_counties;
};
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
struct state* allocate_states(int numberStates) {
	state *sss = new state[numberStates];
	return sss;
}
struct county* allocate_counties(int numberCounties) {
	county *ccc = new county[numberCounties];
	return ccc;
}
void read_county_data(struct county* ccc, int counties, ifstream &testfile) {
	for (int i = 0; i < counties; i++) {
		testfile >> ccc[i].name;
		testfile >> ccc[i].unemployed_2007;
		testfile >> ccc[i].unemployed_2015;
		testfile >> ccc[i].med_income;
	}
}
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
void display() {
			cout << "[1]. Print the county in that state with the highest/lowest median household income.\n"
			"[2]. Print the county in that state with the highest/lowest unemployment in 2015.\n"
			"[3]. Print the counties in that state in sorted order by change in unemployment from 2007 to 2015 (i.e. start with the largest decrease in unemployment and end with the largest increase in unemployment)\n"
			"[4]. Print the counties in that state in sorted order based on median household income.\n" 
			"[5]. Exit the program" << endl;
}
void free_state_data(struct state* sss, int numberStates) {
	for(int i = 0; i < numberStates; i++) {
		delete [] sss[i].counties;
	}
	delete[] sss;
	sss = NULL;
}
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
