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
			array[i][j] = RandomNumber(1, 10);
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

bool checkEqualTypical(int array[3][3], int array2[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (array[i][j] != array2[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void printCheck(bool isEqualTypical) {
	if (isEqualTypical)
		cout << "\nYes: Matrices are Equal Typical" << endl;
	else
		cout << "\nNo: Matrices are NOT Equal Typical" << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];
	int array2[3][3];

	FillMatrix(array, 3, 3);
	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);

	FillMatrix(array2, 3, 3);
	cout << "Matrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);

	printCheck(checkEqualTypical(array, array2, 3, 3));

	system("pause>0");
}
