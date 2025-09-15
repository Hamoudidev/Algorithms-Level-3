#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString(string Message) {
	string Word;

	cout << Message << endl;
	getline(cin >> ws, Word);

	return Word;
}

string InvertAllWord(string Word) {
	for (char& Latter : Word) {
		isupper(Latter) ? Latter = tolower(Latter) : Latter = toupper(Latter);
	}

	return Word;
}

void printInverted(string Word) {
	cout << "String after inverted all latters case:" << endl;
	cout << Word << endl;
}

int main() {
	srand((unsigned)time(NULL));

	printInverted(InvertAllWord(ReadString("Please Enter Your Sring?")));

	system("pause>0");
}
