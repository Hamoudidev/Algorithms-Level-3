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

string ReplceString(string Word, string ReplaceFrom, string ReplaceTo) {
	string replacedWord = "";
	vector <string> Tokens = splitString(Word, " ");

	for (short i = 0; i < Tokens.size(); i++) {
		if (Tokens[i] == ReplaceFrom)
			Tokens[i] = ReplaceTo;

		replacedWord += Tokens[i] + " ";
	}

	replacedWord = replacedWord.substr(0, replacedWord.length() - 1);

	return replacedWord;
}

string BuiltInReplaceFunc(string Word, string ReplaceFrom, string ReplaceTo) {
	short Pos = Word.find(ReplaceFrom);

	while (Pos != string::npos) {
		Word = Word.replace(Pos, ReplaceFrom.length(), ReplaceTo);
		Pos = Word.find(ReplaceFrom);
	}

	return Word;
}

int main() {
	srand((unsigned)time(NULL));

	string Word = "Welcome To USA , USA is a nice country";
	string StringToReplace = "USA";
	string ReplaceTo = "Egypt";

	cout << "Original String :\n" << Word;
  
	cout << "\n\nString After Replace (Hand-Made) :";
	cout << endl << ReplceString(Word, StringToReplace, ReplaceTo) << endl;
  
	cout << "\nString After Replace (Built In) :";
	cout << endl << BuiltInReplaceFunc(Word, StringToReplace, ReplaceTo) << endl;
	system("pause>0");
}
