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

bool checkPalindromeMatrix(int array[3][3], short Rows, short Cols) {
	short ColsSize = Cols / 2;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < ColsSize; j++) {
			if (array[i][j] != array[i][Cols - 1 - j])
				return false;
		}
	}
	return true;
}

void printCheck(bool isPalindrome) {
	if (isPalindrome)
		cout << "Matrix is palindrome" << endl;
	else
		cout << "Matrix is NOT palindrome" << endl;
}

int main() {
	srand((unsigned)time(NULL));
	int array[3][3] = { {1,2,1}, {5, 5, 5}, {2, 1, 2} };
	int array2[3][3] = { {1,2,3}, {5, 5, 5}, {2, 1, 2} };

	cout << "Matrix 1 :" << endl;
	PrintMatrix(array, 3, 3);
	printCheck(checkPalindromeMatrix(array, 3, 3)); // Matrix 1 is palindrome

	cout << "\nMatrix 2 :" << endl;
	PrintMatrix(array2, 3, 3);
	printCheck(checkPalindromeMatrix(array2, 3, 3)); // Matrix 2 is NOT palindrome

	system("pause>0");
	return 0;
}
