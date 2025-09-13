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

void SumRowsInMatrix(int array[3][3], int SumArray[3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		SumArray[i] = RowSum(array, i, Cols);
	};
}

void PrintEachRowSum(int SumArray[3], short Rows) {
	cout << "Sum each row in the Matrix :" << endl;
	for (short i = 0; i < Rows; i++) {
		cout << "Row " << i + 1 << " Sum = " << SumArray[i] << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];
	int SumArray[3];

	FillMatrix(array, 3, 3);
	cout << "Following Matrix Random Numbers :" << endl;
	PrintMatrix(array, 3, 3);

	SumRowsInMatrix(array, SumArray, 3, 3);

	PrintEachRowSum(SumArray, 3);

	return 0;
}
