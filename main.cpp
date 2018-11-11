#include <iostream>
#include <string>
#include "distcalc.h"
using namespace std;

int main(){
	string w1,w2;
	cout << "-----Edit Distance Calculator-----" << endl;
	cout << "Enter first word: ";
	cin >> w1;
	cout << "Enter second word: ";
	cin >> w2;

	eDistance(w1, w2);
	return 0;
}
