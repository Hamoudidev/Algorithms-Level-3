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

const string FileName = "Clients.txt";

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

void PrintHeader(short Size) {
	cout << "\t\t\t== Client List (" << Size << ") Client(s). ==\t\t\t" << endl;
	cout << "----------------------------------------------------------------------------------------\n";
	cout << "| Account Number | PIN CODE  | Client Name               | Phone        | Balance      |" << endl;
	cout << "----------------------------------------------------------------------------------------\n";
}

void PrintClientsData(vector <stClients> ClientsData) {

	PrintHeader(ClientsData.size());
	for (stClients& Client : ClientsData) {
		cout << "| " << left << setw(15) << Client.accNumber; // Account Number
		cout << "| " << left << setw(10) << Client.pinCode; // PIN CODE
		cout << "| " << left << setw(26) << Client.Name; // Client Name
		cout << "| " << left << setw(14) << Client.Phone; // Phone
		cout << "| " << left << setw(12) << Client.accBalance << "|"; // Balance
		cout << endl; // New Line After Client.
	}
	cout << "----------------------------------------------------------------------------------------\n";

}

int main() {
	srand((unsigned)time(NULL));

	vector <stClients> ClientsData = LoadData(FileName);

	PrintClientsData(ClientsData);

	//system("pause>0");
	return 0;
}
