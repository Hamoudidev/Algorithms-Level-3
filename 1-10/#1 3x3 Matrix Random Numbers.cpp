#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	int number = rand() % (To - From + 1) + From;

	return number;
}

void FillMatrix(int array[3][3], short Rows, short Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			array[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int array[3][3], short Rows, short Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			cout << setw(3) << array[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Following Matrix Random Numbers :" << endl;
	PrintMatrix(array, 3, 3);
	return 0;
}
