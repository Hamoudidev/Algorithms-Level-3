#include <iostream>
#include <iomanip>

using namespace std;

int ReadNumber(string Message) {
	int Number;

	cout << Message;
	cin >> Number;

	return Number;
}

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

int main() {
	srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrix(array, 3, 3);
	cout << "Matrix :" << endl;
	PrintMatrix(array, 3, 3);

	int Target = ReadNumber("\nEnter the Number to count in Matrix?:  ");
	cout << "Number " << Target << " count in matrix is " << checkCount(array, 3, 3, Target) << endl;;

	system("pause>0");
}
