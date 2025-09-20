#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClients {
	string accNumber;
	string pinCode;
	string Name;
	string Phone;
	int accBalance;
};

vector <string> splitString(string Word, string delim) {
	vector <string> Tokens;

	short Pos = 0;
	string sWord;

	while ((Pos = Word.find(delim)) != string::npos) {
		sWord = Word.substr(0, Pos);
		if (sWord != "") {
			Tokens.push_back(sWord);
		}

		Word.erase(0, Pos + delim.length());
	}

	if (Word != "") {
		Tokens.push_back(Word);
	}

	return Tokens;
}

stClients ConvertLineToRecord(string Line, string spaceShape = "#//#") {
	vector <string> Record = splitString(Line, spaceShape);

	stClients Client;

	Client.accNumber = Record[0];
	Client.pinCode = Record[1];
	Client.Name = Record[2];
	Client.Phone = Record[3];
	Client.accBalance = stof(Record[4]);

	return Client;
}

void PrintRecord(stClients Client) {
	cout << "The following is the extracted client record:\n\n";

	cout << "Account Number  : " << Client.accNumber << endl;
	cout << "Pin Code        : " << Client.pinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.accBalance << endl;
}

int main() {
	srand((unsigned)time(NULL));

	string Line = "A100#//#1234#//#Ahmed Saied Mohamed#//#01019160091#//#2000";

	cout << "Line record is:\n";
	cout << Line << "\n\n";

	PrintRecord(ConvertLineToRecord(Line, "#//#"));

	system("pause>0");
}
