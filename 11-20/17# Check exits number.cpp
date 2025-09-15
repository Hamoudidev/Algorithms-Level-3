#include <iostream>
#include <iomanip>

using namespace std;

int ReadNumber(string Message) {
	int Number;

	cout << Message;
	cin >> Number;

	return Number;
}

int RandomNumber(int From, int To) {
	int number = rand() % (To - From + 1) + From;

	return number;
}

void FillMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			array[i][j] = RandomNumber(0, 100);
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

void printCheck(bool isIn) {
	if (isIn)
		cout << "\nYes it is there" << endl;
	else
		cout << "\nNo it is not there" << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Matrix :" << endl;
	PrintMatrix(array, 3, 3);

	int Target = ReadNumber("Please enter the number to look for in matrix?:  ");
	printCheck(checkNumberIsIn(array, 3, 3, Target));

	system("pause>0");
}
