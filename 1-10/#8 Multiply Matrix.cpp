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

void MultiplyMatrix(int array[3][3], int array2[3][3], int MatrixResult[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			MatrixResult[i][j] = (array[i][j] * array2[i][j]);
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3], array2[3][3], MatrixResult[3][3];

	FillMatrix(array, 3, 3);
	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);

	FillMatrix(array2, 3, 3);
	cout << "Matrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);

	MultiplyMatrix(array, array2, MatrixResult, 3, 3);
	cout << "\nMultiply Matrix Result :" << endl;
	PrintMatrix(MatrixResult, 3, 3);

	system("pause>0");
}
