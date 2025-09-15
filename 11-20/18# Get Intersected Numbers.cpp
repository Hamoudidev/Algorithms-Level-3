#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int RandomNumber(int From, int To) {
	int number = rand() % (To - From + 1) + From;

	return number;
}

void FillMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			array[i][j] = RandomNumber(0, 10);
		}
	}
}

void PrintMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf(" %0*d   ", 2, array[i][j]);
		}
		cout << endl;
	}
}

bool checkNumberIsIn(int array[3][3], short Rows, short Cols, int Target) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (array[i][j] == Target)
				return true;
		}
	}
	return false;
}

vector <int> checkIntersectedNumbers(int array[3][3], int array2[3][3], short Rows, short Cols, vector <int> & intersectedArray) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (checkNumberIsIn(array2, 3, 3, array[i][j]))
				intersectedArray.push_back(array[i][j]);
		}
	}
	return intersectedArray;
}

void printNumbers(vector <int> intersectedArray) {
	cout << "\nIntersected Numbers are :" << endl;
	for (int Number : intersectedArray) {
		cout << Number << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];
	int array2[3][3];
	vector <int> intersectedArray;

	FillMatrix(array, 3, 3);
	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);

	FillMatrix(array2, 3, 3);
	cout << "Matrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);

	printNumbers(checkIntersectedNumbers(array, array2, 3, 3, intersectedArray));

	system("pause>0");
}
