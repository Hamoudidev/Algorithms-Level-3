#include <iostream>
#include <string>

using namespace std;

string ReadWord(string Message) {
	string Word;
	cout << Message << endl;
	getline(cin, Word);
	return Word;
}

void PrintCountEachWord(string Word) {
	string delim = " ", sWord;
	short Pos = 0, Counter = 0;

	while ((Pos = Word.find(delim)) != string::npos) {
		sWord = Word.substr(0, Pos);
		if (sWord != "") {
			Counter++;
		}

		Word.erase(0, Pos + delim.length());
	}

	if (Word != "") {
		Counter++;
	}

	cout << "\nNumber of words in your string is : " << Counter << endl;
}

int main() {
	srand((unsigned)time(NULL));

	PrintCountEachWord(ReadWord("Please Enter Your String?"));

	system("pause>0");
}
