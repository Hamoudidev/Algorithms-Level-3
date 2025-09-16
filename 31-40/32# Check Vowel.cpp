#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadChar(string Message) {
	char Character;

	cout << Message << endl;
	cin >> Character;

	return Character;
}

char InvertLatter(char Latter) {
	return isupper(Latter) ? Latter = tolower(Latter) : Latter = toupper(Latter);
}

bool checkVowel(char VowelsChars[5], char Target) {
	for (short i = 0; i < 5; i++) {
		if (tolower(VowelsChars[i]) == tolower(Target))
			return true;
	}

	return false;
}

int main() {
	srand((unsigned)time(NULL));
	char VowelsChars[5] = { 'a', 'e', 'i', 'o', 'u' };
	char TargetCharacter = ReadChar("Please Enter a Character?");

	if (checkVowel(VowelsChars, TargetCharacter))
		cout << "\nYES: Letter '" << TargetCharacter << "' is vowel" << endl;
	else
		cout << "\nNO: Letter '" << TargetCharacter << "' is NOT vowel" << endl;

	system("pause>0");
}
