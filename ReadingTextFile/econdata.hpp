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
bool check_arguments(int argc, char *argv[]);
bool check_states(int numberStates);
struct state* allocate_states(int numberStates);
struct county* allocate_counties(int numberCounties);
void read_county_data(struct county* ccc, int counties, ifstream &testfile);
void read_state_data(struct state* sss, int numberStates, ifstream &testfile);
void county_unemployment_difference (state wantedState);
void sort_county_income (state wantedState);
void county_median_income (state wantedState);
void county_unemployment (state wantedState);
void sort_median_income (struct state* sss, int numberStates);
void sort_employment_rate(struct state* sss, int numberStates); 
state instructions(struct state* sss, int numberStates); 
void display();
void free_state_data(struct state* sss, int numberStates); 

