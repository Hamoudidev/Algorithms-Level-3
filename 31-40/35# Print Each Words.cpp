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

	string delim = " ";
	short Pos = 0;
	string sWord;

	while ((Pos = Word.find(delim)) != string::npos) {
		sWord = Word.substr(0, Pos);
		if (sWord != "") {
			cout << sWord << endl;
		}

		Word.erase(0, Pos + delim.length());
	}

	if (Word != "") {
		cout << Word << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	PrintEachWord(ReadWord("Please Enter Your String?"));

	system("pause>0");
}
