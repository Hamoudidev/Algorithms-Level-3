#include <iostream>
#include <iomanip>

using namespace std;

void FillOrderedMatrix(int array[3][3], short Rows, short Cols) {
	int Counter = 1;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			array[i][j] = Counter;
			Counter++;
		}
	}
}

void TranposeMatrix(int array[3][3], int arrTransposed[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arrTransposed[j][i] = array[i][j];
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

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];
	int arrTransposed[3][3];

	FillOrderedMatrix(array, 3, 3);
	cout << "Following Matrix With Ordered Numbers :" << endl;
	PrintMatrix(array, 3, 3);

	TranposeMatrix(array, arrTransposed, 3, 3);
	cout << "Following Matrix With Transposed Numbers :" << endl;
	PrintMatrix(arrTransposed, 3, 3);

	return 0;
}
