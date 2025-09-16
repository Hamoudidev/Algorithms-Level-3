#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

string lowerAllLatters(string Word) {
	for (char& Latter : Word) {
		Latter = tolower(Latter);
	}
	return Word;
}

string joinString(vector <string> Elements, string delim) {
	string Word = "";

	for (string Element : Elements) {
		Word += Element + delim;
	}

	return Word.substr(0, Word.length() - delim.length());
}

string ReplceString(string Word, string ReplaceFrom, string ReplaceTo, bool matchCase = true) {
	vector <string> Tokens = splitString(Word, " ");

	for (short i = 0; i < Tokens.size(); i++) {
		if (matchCase) {
			if (Tokens[i] == ReplaceFrom)
				Tokens[i] = ReplaceTo;
		}
		else {
			if (lowerAllLatters(Tokens[i]) == lowerAllLatters(ReplaceFrom))
				Tokens[i] = ReplaceTo;
		}
	}

	return joinString(Tokens, " ");
}

int main() {
	srand((unsigned)time(NULL));

	string Word = "Welcome To egypt , Egypt is a nice country";
	string StringToReplace = "Egypt";
	string ReplaceTo = "USA";

	cout << "Original String :\n" << Word;

	cout << "\n\nString After Replace (With Match Case) :";
	cout << endl << ReplceString(Word, StringToReplace, ReplaceTo) << endl;

	cout << "\n\nString After Replace (Without Match Case) :";
	cout << endl << ReplceString(Word, StringToReplace, ReplaceTo, false) << endl;
	system("pause>0");
}
