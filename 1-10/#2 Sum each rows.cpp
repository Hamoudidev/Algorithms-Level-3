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

int RowSum(int array[3][3], short RowNum, short Cols) {
	int Sum = 0;
	for (short i = 0; i < Cols; i++) {
		Sum += array[RowNum][i];
	}
	return Sum;

}

void PrintEachRowSum(int array[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		cout << "Row " << i + 1 << " Sum = " << RowSum(array, i, Cols) << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Following Matrix Random Numbers :" << endl;
	PrintMatrix(array, 3, 3);
	cout << "Sum each row in the Matrix :" << endl;
	PrintEachRowSum(array, 3, 3);

	return 0;
}
