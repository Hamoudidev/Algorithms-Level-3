#include <iostream>
#include <string>
#include <vector>

using namespace std;

string RemovePuncts(string Word) {
	string TempWord = "";

	for (char &Letter : Word) {
		if (!ispunct(Letter))
			TempWord += Letter;
	}

	return TempWord;
}

int main() {
	srand((unsigned)time(NULL));

	string Word = "Welcome To egypt , Egypt is a nice country; OMG!";

	cout << "Original String :\n" << Word;

	cout << "\n\nString After remove puncts:";
	cout << endl << RemovePuncts(Word) << endl;
	system("pause>0");
}
