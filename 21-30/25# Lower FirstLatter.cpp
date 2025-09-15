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

void lowerFirstLatter(string Word) {
	bool isFirstLetter = true;
	cout << "\nString after conversion:" << endl;

	for (short i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ' && isFirstLetter) {
			Word[i] = tolower(Word[i]);
		}

		isFirstLetter = (Word[i] == ' ' ? true : false);
	}

	cout << Word << endl;
}

int main() {
	srand((unsigned)time(NULL));

	string Word = ReadWord("Please Enter Your String?");
	lowerFirstLatter(Word);

	system("pause>0");
}
