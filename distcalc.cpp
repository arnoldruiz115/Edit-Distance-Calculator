#include "distcalc.h"
#include <iomanip>

void eDistance(string w1, string w2){
	//get row and column size for matrix
	int rows = w1.size() + 1;
	int cols = w2.size() + 1;
	
	//dynamically allocate matrix
	int** eMatrix = new int*[rows];
	for (int i = 0; i < rows; ++i){
		eMatrix[i] = new int[cols];
	}
	
	//Fill in base values
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			eMatrix[i][j] = -1;
		}
	}
	eMatrix[0][0] = 0;
	for (int i = 1; i < rows; ++i){
		eMatrix[i][0] = i;
	}
	for (int i = 1; i < cols; ++i){
		eMatrix[0][i] = i;
	}
	
	//Display the matrix
	cout << "Matrix: \n";
	string temp1 = "-" + w1;
	string temp2 = " -" + w2;
	for(int i = 0; i < cols+1; ++i){
			cout << setw(3) << left << temp2[i] << " | ";
		}
	for(int i = 0; i < rows; ++i){
		cout << endl;
		cout << setw(3) << left << temp1[i] << " | ";
		for(int j = 0; j < cols; ++j)
			cout << setw(3) << left << eMatrix[i][j] << " | ";
	}
	cout << endl;
	
	cout << "\nEdit distance is: " << eMatrix[rows-1][cols-1];
	cout << "\nAlignment is: " << endl << w1 << endl << w2 << endl;
}