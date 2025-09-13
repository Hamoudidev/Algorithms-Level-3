#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	int number = rand() % (To - From + 1) + From;

	return number;
}

void FillMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			array[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << array[i][j] << "\t";
		}
		cout << endl;
	}
}

int ColSum(int array[3][3], short Rows, short ColNum) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++) {
		Sum += array[i][ColNum];
	}
	return Sum;

}

void PrintEachColsSum(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Cols; i++) {
		cout << "Col " << i + 1 << " Sum = " << ColSum(array, Rows, i) << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Following Matrix Random Numbers :" << endl;
	PrintMatrix(array, 3, 3);
	cout << "Sum each cols in the Matrix :" << endl;
	PrintEachColsSum(array, 3, 3);

	return 0;
}
