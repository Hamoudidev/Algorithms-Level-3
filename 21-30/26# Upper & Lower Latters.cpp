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

void upperAllLatters(string Word) {
	cout << "\nString after upper:" << endl;
	for (char &Latter : Word) {
		Latter = toupper(Latter);
	}

	cout << Word << endl;
}

void lowerAllLatters(string Word) {
	cout << "\nString after lower:" << endl;
	for (char &Latter : Word) {
		Latter = tolower(Latter);
	}

	cout << Word << endl;
}

int main() {
	srand((unsigned)time(NULL));

	string Word = ReadWord("Please Enter Your String?");
	upperAllLatters(Word);
	lowerAllLatters(Word);

	system("pause>0");
}
