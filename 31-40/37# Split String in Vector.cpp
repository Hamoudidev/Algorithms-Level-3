#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadWord(string Message) {
	string Word;
	cout << Message << endl;
	getline(cin, Word);
	return Word;
}

vector <string> splitString(string Word, string delim){
	vector <string> Tokens;

	short Pos = 0;
	string sWord;

	while ((Pos = Word.find(delim)) != string::npos) {
		sWord = Word.substr(0, Pos);
		if (sWord != "") {
			Tokens.push_back(sWord);
		}

		Word.erase(0, Pos + delim.length());
	}

	if (Word != "") {
		Tokens.push_back(Word);
	}

	return Tokens;
}

void printTokens(vector <string> Tokens) {
	cout << "\nTokens = " << Tokens.size() << endl;
	for (string Token : Tokens) {
		cout << Token << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	string Word = ReadWord("Please Enter Your String?");

	printTokens(splitString(Word, " "));

	system("pause>0");
}
