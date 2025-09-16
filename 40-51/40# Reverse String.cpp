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

vector <string> splitString(string Word, string delim) {
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

string reverseString(vector <string> Tokens) {
	string reversedWord = "";

	for (short i = Tokens.size() - 1; i >= 0; i--) {
		reversedWord += Tokens[i] + " ";
	}

	reversedWord = reversedWord.substr(0, reversedWord.length() - 1);

	return reversedWord;
}

int main() {
	srand((unsigned)time(NULL));

	string Word = ReadWord("Please Enter Your String?");

	cout << "\nString after reversing word :" << endl;
	cout << reverseString(splitString(Word, " ")) << endl;

	system("pause>0");
}
