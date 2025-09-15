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

int MinNumber(int array[3][3], short Rows, short Cols) {
	int Number = array[0][0];
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (array[i][j] < Number)
				Number = array[i][j];
		}
	}
	return Number;
}

int MaxNumber(int array[3][3], short Rows, short Cols) {
	int Number = array[0][0];
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (array[i][j] > Number)
				Number = array[i][j];
		}
	}
	return Number;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Matrix :" << endl;
	PrintMatrix(array, 3, 3);

	cout << "\nMinimum Number is: " << MinNumber(array, 3, 3) << endl;
	cout << "Max Number is: " << MaxNumber(array, 3, 3) << endl;

	system("pause>0");
}
