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
	double accBalance;
	bool isDeleted = false;
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

stClients ConvertLineToRecord(string Line, string spaceShape) {
	vector <string> Record = splitString(Line, spaceShape);

	stClients Client;

	Client.accNumber = Record[0];
	Client.pinCode = Record[1];
	Client.Name = Record[2];
	Client.Phone = Record[3];
	Client.accBalance = stod(Record[4]);

	return Client;
}

vector <stClients> LoadData(string FileName) {
	vector <stClients> vFileContent;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		string Line;

		while (getline(MyFile, Line)) {
			vFileContent.push_back(ConvertLineToRecord(Line, "#//#"));
		}

		MyFile.close();
	}

	return vFileContent;
}

bool FindAccount(vector <stClients>& ClientsData, string TargetAccountNumber, stClients& Client) {
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

string ConvertRecordToLine(stClients Clients, string spaceShape) {
	string Word = "";

	Word += Clients.accNumber + spaceShape;
	Word += Clients.pinCode + spaceShape;
	Word += Clients.Name + spaceShape;
	Word += Clients.Phone + spaceShape;
	Word += to_string(Clients.accBalance);

	return Word;
}

void SaveNewClients(string FileName, vector <stClients>& vClients) {
	fstream ClientsData;

	ClientsData.open(FileName, ios::out);

	if (ClientsData.is_open()) {
		for (stClients Client : vClients) {
			if (Client.isDeleted) continue;

			string Line = ConvertRecordToLine(Client, "#//#");
			ClientsData << Line << "\n";
		}

		ClientsData.close();
	}
}

void DeleteAccount(vector <stClients>& vClients, string TargetAccountNumber) {
	stClients Client;
	char ConfirmDelete = 'n';

	if (FindAccount(vClients, TargetAccountNumber, Client)) {
		PrintAccount(Client);

		do {
			cout << "\nAre you sure you want to delete this client? [Y/N]:  ";
			cin >> ConfirmDelete;
		} while (tolower(ConfirmDelete) != 'y' && tolower(ConfirmDelete) != 'n');

		if (ConfirmDelete == 'y') {
			for (stClients& Client : vClients) {
				if (Client.accNumber == TargetAccountNumber) {
					Client.isDeleted = true;
				}
			}

			SaveNewClients("Clients.txt", vClients);

			vClients = LoadData("Clients.txt");

			cout << "\nClient Deleted Successfully.\n";
		}

	}
	else {
		cout << "\nClient with AccountNumber (" << TargetAccountNumber << ") NOT Found." << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	vector <stClients> ClientsData = LoadData("Clients.txt");;

	string accNum = ReadString("Please enter AccountNumber?: ");

	DeleteAccount(ClientsData, accNum);

	//system("pause>0");
	return 0;
}
