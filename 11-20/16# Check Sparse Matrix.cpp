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

int checkCount(int array[3][3], short Rows, short Cols, int Target) {
	short Count = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (array[i][j] == Target)
				Count++;
		}
	}
	return Count;
}

bool checkSparcseMatrix(int array[3][3], short Rows, short Cols) {
	short MatrixSize = Rows * Cols;
	return checkCount(array, 3, 3, 0) >= (MatrixSize / 2);
}

void printCheckSparse(bool isSparse) {
	if (isSparse)
		cout << "\nYes: Matrix is Sparse" << endl;
	else
		cout << "\nNo: Matrix is NOT Sparse" << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3] = { {0,0,0}, {0, 2, 0}, {5, 6, 7} };
	int array2[3][3] = { {0,4,0}, {3, 2, 2}, {5, 6, 7} };

	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);
	printCheckSparse(checkSparcseMatrix(array, 3, 3)); // Matrix 1 is Sparse ( Count of zero is highthan another numbers count )

	cout << "Matrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);
	printCheckSparse(checkSparcseMatrix(array2, 3, 3)); // Matrix 1 is NOT Sparse ( Count of zero is lowerthan another numbers count )

	system("pause>0");
}
