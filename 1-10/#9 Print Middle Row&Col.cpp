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

void PrintMiddleRow(int array[3][3], short Rows, short Cols) {
	short MiddleRow = Rows / 2;

	for (short i = 0; i < Rows; i++) {
		printf(" %0*d   ", 2, array[i][MiddleRow]);
	}
}

void PrintMiddleCol(int array[3][3], short Rows, short Cols) {
	short MiddleCol = Cols / 2;

	for (short i = 0; i < Cols; i++) {
		printf(" %0*d   ", 2, array[MiddleCol][i]);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Matrix :" << endl;
	PrintMatrix(array, 3, 3);

	cout << "\nMiddle Row of Matrix :\n";
	PrintMiddleRow(array, 3, 3);

	cout << "\nMiddle Col of Matrix :\n";
	PrintMiddleCol(array, 3, 3);

	system("pause>0");
}
