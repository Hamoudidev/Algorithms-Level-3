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

char ReadChar(string Message) {
	char Character;

	cout << Message << endl;
	cin >> Character;

	return Character;
}

char InvertLatter(char Latter) {
	return isupper(Latter) ? Latter = tolower(Latter) : Latter = toupper(Latter);
}

short CountTargetLatter(string Word, char Target, bool MatchCase = true) {
	short Counter = 0;
	for (char Latter : Word) {
		if (MatchCase) {
			if (Latter == Target)
				Counter++;
		}
		else {
			if (tolower(Latter) == tolower(Target))
				Counter++;
		}
	}

	return Counter;
}

int main() {
	srand((unsigned)time(NULL));
	string Word = ReadString("Please Enter Your String?");
	char TargetCharacter = ReadChar("\nPlease Enter a Character?");

	cout << "\nLatter '" << TargetCharacter << "' Count = " << CountTargetLatter(Word, TargetCharacter) << endl;
	cout << "\nLatter '" << TargetCharacter << "' OR ";
	cout << "'" << InvertLatter(TargetCharacter) << "' Count = " << CountTargetLatter(Word, TargetCharacter, false) << endl;

	system("pause>0");
}
