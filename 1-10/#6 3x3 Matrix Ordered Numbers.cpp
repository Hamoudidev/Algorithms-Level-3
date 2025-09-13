#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrix(int array[3][3], short Rows, short Cols) {
	int Counter = 1;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			array[i][j] = Counter;
			Counter++;
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

	FillMatrix(array, 3, 3);
	cout << "Following Matrix With Ordered Numbers :" << endl;
	PrintMatrix(array, 3, 3);

	return 0;
}
