#include <iostream>
#include <string>
#include <vector>

using namespace std;

string joinString(vector <string> Elements, string delim) {
	string Word = "";

	for (string Element : Elements) {
		Word += Element + delim;
	}

	return Word.substr(0, Word.length() - delim.length());
}

int main() {
	srand((unsigned)time(NULL));

	vector <string> Elements = { "Ahmed", "Ali", "Mohamed", "Youssef", "Koko" };
	cout << joinString(Elements, " ");

	system("pause>0");
}
