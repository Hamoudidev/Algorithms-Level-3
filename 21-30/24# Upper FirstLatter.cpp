#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadWord(string Message) {
	string Word;
	cout << Message << endl;
	getline(cin, Word);
	return Word;
}

void upperFirstLatter(string Word) {
	bool isFirstLetter = true;
	cout << "\nString after conversion:" << endl;

	for (short i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ' && isFirstLetter) {
			Word[i] = toupper(Word[i]);
		}

		isFirstLetter = (Word[i] == ' ' ? true : false);
	}

	cout << Word << endl;
}

int main() {
	srand((unsigned)time(NULL));

	string Word = ReadWord("Please Enter Your String?");
	upperFirstLatter(Word);

	system("pause>0");
}
