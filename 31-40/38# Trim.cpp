#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string Word){
	short Pos = 0;

	for (char Letter : Word) {
		if (Letter != ' ')
			break;
		Pos++;
	}

	Word.erase(0, Pos);

	return Word;
}

string TrimRight(string Word) {
	short Pos = 0;

	for (short i = Word.length() - 1; i >= 0; i--) {
		if (Word[i] != ' ')
			break;

		Pos--;
	}

	Word.erase(Word.length() + Pos, Word.length() - 1);

	return Word;
}

string Trim(string Word) {
	return TrimRight(TrimLeft(Word));
}

int main() {
	srand((unsigned)time(NULL));

	string Word = "       Ahmed Saied Mohamed                                ";

	cout << "String      = " << Word << endl << endl;
	cout << "Trim Left   = " << TrimLeft(Word) << endl;
	cout << "Trim Right  = " << TrimRight(Word) << endl;
	cout << "Trim        = " << Trim(Word);

	system("pause>0");
}
