#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadCharacter(string Message) {
	char Character;

	cout << Message << endl;
	cin >> Character;

	return Character;
}

char InvertLatter(char Latter) {
	return isupper(Latter) ? tolower(Latter) : toupper(Latter);
}

void printInverted(char Latter) {
	cout << "Char after inverting case:" << endl;
	cout << Latter << endl;
}

int main() {
	srand((unsigned)time(NULL));

	printInverted(InvertLatter(ReadCharacter("Please Enter a Character?")));

	system("pause>0");
}
