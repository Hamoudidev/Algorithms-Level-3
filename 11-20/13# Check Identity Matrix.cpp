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

bool checkIdentityMatrix(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (i == j && array[i][j] != 1)
				return false;
			if (i != j && array[i][j] != 0)
				return false;
		}
	}
	return true;
}

void printCheck(bool isEqualTypical) {
	if (isEqualTypical)
		cout << "\nYes: Matrix is Identity" << endl;
	else
		cout << "\nNo: Matrix is NOT Identity" << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };
	int array2[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);
	printCheck(checkIdentityMatrix(array, 3, 3)); // Matrix 1 is Identity

	cout << "\nMatrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);
	printCheck(checkIdentityMatrix(array2, 3, 3)); // Matrix 2 is NOT Identity

	system("pause>0");
}
