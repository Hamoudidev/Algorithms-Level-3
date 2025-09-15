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


short CountTargetLatter(string Word, char Target) {
	short Counter = 0;
	for (char Latter : Word) {
		if (Latter == Target)
			Counter++;
	}

	return Counter;
}

int main() {
	srand((unsigned)time(NULL));
	string Word = ReadString("Please Enter Your String?");
	char TargetCharacter = ReadChar("\nPlease Enter a Character?");

	cout << "\nLatter '" << TargetCharacter << "' Count = " << CountTargetLatter(Word, TargetCharacter) << endl;

	system("pause>0");
}
