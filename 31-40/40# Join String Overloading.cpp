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

string joinString(string Elements[], int Length, string delim) {
	string Word = "";

	for (short i = 0; i < Length; i++) {
		Word += Elements[i] + delim;
	}

	return Word.substr(0, Word.length() - delim.length());
}


int main() {
	srand((unsigned)time(NULL));

	vector <string> Elements = { "Ahmed", "Ali", "Mohamed", "Youssef" };
	string Elements2[] = { "Zakria", "Ibrahim", "Lolo", "Koko" };

	cout << "Vector after join:" << endl;
	cout << joinString(Elements, " _ ") << endl;

	cout << "\nArray after join:" << endl;
	cout << joinString(Elements2, 3, ", ");

	system("pause>0");
}
