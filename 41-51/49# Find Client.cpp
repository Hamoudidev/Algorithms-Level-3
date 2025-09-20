#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct stClients {
	string accNumber;
	string pinCode;
	string Name;
	string Phone;
	int accBalance;
};

string ReadString(string Message) {
	string Reply = "";

	cout << Message;
	getline(cin >> ws, Reply);

	return Reply;
}

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

vector <stClients> LoadData(string FileName) {
	vector <stClients> vFileContent;

	fstream MyFile;

	MyFile.open(FileName, ios::in);//read Mode

	if (MyFile.is_open()) {
		string Line;

		while (getline(MyFile, Line)) {
			vFileContent.push_back(ConvertLineToRecord(Line, "#//#"));
		}

		MyFile.close();
	}

	return vFileContent;
}

bool FindAccount(string TargetAccountNumber, stClients& Client) {
	vector <stClients> ClientsData = LoadData("Clients.txt");

	for (stClients C : ClientsData) {
		if (C.accNumber == TargetAccountNumber) {
			Client = C;
			return true;
		}
	}

	return false;
}

void PrintAccount(stClients Client) {
	cout << "\nThe following is the extracted client record:\n\n";

	cout << "Account Number  : " << Client.accNumber << endl;
	cout << "Pin Code        : " << Client.pinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.accBalance << endl;
}

int main() {
	srand((unsigned)time(NULL));

	stClients Client;

	string accNum = ReadString("Please enter AccountNumber?: ");

	if (!FindAccount(accNum, Client))
		cout << "\nClient with AccountNumber (" << accNum << ") NOT Found." << endl;
	else
		PrintAccount(Client);

	//system("pause>0");
	return 0;
}
