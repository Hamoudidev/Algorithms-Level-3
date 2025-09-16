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

bool checkVowel(char VowelsChars[5], char Target) {
	for (short i = 0; i < 5; i++) {
		if (tolower(VowelsChars[i]) == tolower(Target))
			return true;
	}

	return false;
}

void PrintVowels(string Word) {
	char VowelsChars[5] = { 'a', 'e', 'i', 'o', 'u' };

	for (char& Letter : Word) {
		if (checkVowel(VowelsChars, Letter))
			cout << Letter << "   ";
	}
}

int main() {
	srand((unsigned)time(NULL));
	string Word = ReadString("Please Enter Your String?");

	cout << "\nVowels in string are: ";
	PrintVowels(Word);

	system("pause>0");
}
