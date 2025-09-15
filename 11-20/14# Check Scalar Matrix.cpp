#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf(" %0*d   ", 2, array[i][j]);
		}
		cout << endl;
	}
}

bool checkScalarMatrix(int array[3][3], short Rows, short Cols) {
	int firstValue = array[0][0];
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (i == j && array[i][j] != firstValue)
				return false;
			if (i != j && array[i][j] != 0)
				return false;
		}
	}
	return true;
}

void printCheck(bool isEqualTypical) {
	if (isEqualTypical)
		cout << "\nYes: Matrix is Scalar" << endl;
	else
		cout << "\nNo: Matrix is NOT Scalar" << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3] = { {7,0,0}, {0,7,0}, {0,0,7} };
	int array2[3][3] = { {7,0,0}, {0,7,0}, {0,0,5} };

	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);
	printCheck(checkScalarMatrix(array, 3, 3)); // Matrix 1 is Scalar

	cout << "Matrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);
	printCheck(checkScalarMatrix(array2, 3, 3)); // Matrix 2 is NOT Scalar

	system("pause>0");
}
