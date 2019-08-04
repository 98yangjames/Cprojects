#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main() {
	srand(time(NULL));
	float input = rand() %50 + 75;	
	
	cout << input << endl;

}
