#include <iostream>
#include <string>

using namespace std;

string ReadWord(string Message) {
	string Word;
	cout << Message << endl;
	getline(cin, Word);
	return Word;
}

void PrintEachWord(string Word) {
	cout << "\nYour string words are :\n" << endl;

	char LastChar = 'a';
	for (short i = 0; i < Word.length(); i++) {
		if (Word[i] != ' ') {
			cout << Word[i];
		}
		else if(Word[i] == ' ' && LastChar != ' ')
			cout << endl;

		LastChar = Word[i];

	}
}

int main() {
	srand((unsigned)time(NULL));

	PrintEachWord(ReadWord("Please Enter Your String?"));

	system("pause>0");
}
