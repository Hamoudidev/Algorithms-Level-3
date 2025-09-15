#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum enWhatToCount { Small = 0, Capital = 1, All = 2 };

string ReadString(string Message) {
	string Word;

	cout << Message << endl;
	getline(cin >> ws, Word);

	return Word;
}

short CountLatters(string Word, enWhatToCount WhatToCount = enWhatToCount::All) {
	if (WhatToCount == enWhatToCount::All) {
		return Word.length();
	}

	short Counter = 0;
	for (char Latter : Word) {
		if (WhatToCount == enWhatToCount::Capital && isupper(Latter))
			Counter++;
		else if (WhatToCount == enWhatToCount::Small && islower(Latter))
			Counter++;
	}

	return Counter;
}

int main() {
	srand((unsigned)time(NULL));
	string Word = ReadString("Please Enter Your String?");
	cout << "\nString Length          = " << CountLatters(Word) << endl;
	cout << "Capital Latters Count  = " << CountLatters(Word, enWhatToCount::Capital) << endl;
	cout << "Small Latters Count    = " << CountLatters(Word, enWhatToCount::Small) << endl;

	system("pause>0");
}
