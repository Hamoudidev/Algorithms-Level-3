#include <iostream>
#include <iomanip>

using namespace std;

void PrintFibonacci(short Count) {
	int Result = 0;
	int PrevOne = 1, PrevTwo = 0;
	cout << "1   ";
	for (int i = 2; i <= Count; i++) {
		Result = PrevOne + PrevTwo;
		cout << Result << "   ";

		PrevTwo = PrevOne;
		PrevOne = Result;
	}
}

int main() {
	srand((unsigned)time(NULL));

	PrintFibonacci(10); // 1 1 2 3 5 8 13 21 34 55

	system("pause>0");
	return 0;
}
