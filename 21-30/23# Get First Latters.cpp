#include <iostream>
#include <string>

using namespace std;

string ReadWord(string Message) {
	string Word;
	cout << Message << endl;
	getline(cin, Word);
	return Word;
}

void getFirstLetter(string Word) {
	bool isFirstLetter = true;
	cout << "First letters of this string:" << endl;

	for (short i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ' && isFirstLetter) {
			cout << Word[i] << endl;
		}

		isFirstLetter = (Word[i] == ' ' ? true : false);
	}
}

int main() {
	srand((unsigned)time(NULL));

	string Word = ReadWord("Please Enter Your String?");
	getFirstLetter(Word);

	system("pause>0");
}
