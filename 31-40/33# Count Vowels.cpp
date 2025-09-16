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

int CountVowel(string Word) {
	char VowelsChars[5] = { 'a', 'e', 'i', 'o', 'u' };

	int Counter = 0;
	for (char& Letter : Word) {
		if (checkVowel(VowelsChars, Letter))
			Counter++;
	}

	return Counter;
}

int main() {
	srand((unsigned)time(NULL));
	string Word = ReadString("Please Enter Your String?");

	cout << "\nNumber of vowels is: " << CountVowel(Word) << endl;

	system("pause>0");
}
