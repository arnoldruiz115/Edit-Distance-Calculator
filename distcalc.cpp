#include "distcalc.h"
#include <algorithm>
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
	eMatrix[0][0] = 0;
	for (int i = 1; i < rows; ++i){
		eMatrix[i][0] = i;
	}
	for (int i = 1; i < cols; ++i){
		eMatrix[0][i] = i;
	}
	
	//adding one character to both words to match table
	string word1 = "-" + w1;
	string word2 = "-" + w2;
	
	//Fill in matrix
	for(int i = 1; i < rows; ++i){
		for(int j = 1; j < cols; ++j){
			if(word1[i]==word2[j]){
				eMatrix[i][j] = eMatrix[i-1][j-1];
			}
			else{
				eMatrix[i][j] = min({eMatrix[i-1][j-1], 
				eMatrix[i][j-1], eMatrix[i-1][j]})+1;
			}
		}
	}
	
	//Display the matrix
	cout << "Matrix: \n";
	string temp1 = "-" + w1;
	string temp2 = " -" + w2;
	for(int i = 0; i < cols+1; ++i){
			cout << setw(2) << left << temp2[i] << " | ";
		}
	for(int i = 0; i < rows; ++i){
		cout << endl;
		cout << setw(2) << left << temp1[i] << " | ";
		for(int j = 0; j < cols; ++j)
			cout << setw(2) << left << eMatrix[i][j] << " | ";
	}
	cout << endl;
	
	cout << "\nEdit distance is: " << eMatrix[rows-1][cols-1] << endl;
	
	//Finding Alignment
	int i = rows-1;
	int j = cols-1;
	int tempMin, diag, top, left;
	bool diagMin = false;
	string align1 = "";
	string align2 = "";
	while((i != 0) || (j != 0)){
		//in case traversal is along the edge, dont check out of bounds		
		if(j == 0){diag = 999; left = 999;}
		else if(i == 0){diag = 999; top = 999;}
		else{
			diag = eMatrix[i-1][j-1];
			top =  eMatrix[i-1][j];
			left = eMatrix[i][j-1];
		}
		tempMin = min({diag, top, left});
		if(tempMin == diag){
			 diagMin = true;
			 //Diagonal is Minimum
			 align1 += word1[i];
			 align2 += word2[j];
			 i--;
			 j--;
		 }
		 if(!diagMin){
			 if(tempMin == top) {
				 //top is minimum
				 align1 += word1[i];
				 align2 += "_";
				 i--;
		 }
		 else{
			 //left is minimum
			 align2 += word2[j];
			 align1 += '_';
			 j--;
			}
		 }
		 diagMin = false;
	}
	reverse(align1.begin(), align1.end());
	reverse(align2.begin(), align2.end());
	cout << "\nAlignment: \n" << align1 << endl << align2;
}
