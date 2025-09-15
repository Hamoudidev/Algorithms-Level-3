#include <iostream>
#include <iomanip>

using namespace std;

void PrintFibonacci(short Count, int PrevOne, int PrevTwo) {
	if (Count > 0) {
		int Result = 0;

		Result = PrevOne + PrevTwo;
		cout << Result << "   ";

		PrevTwo = PrevOne;
		PrevOne = Result;
		Count--;
		PrintFibonacci(Count, PrevOne, PrevTwo);
		
	}
}

int main() {
	srand((unsigned)time(NULL));

	PrintFibonacci(10, 0, 1);

	system("pause>0");
	return 0;
}
