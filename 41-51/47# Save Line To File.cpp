#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

int ReadNumber(string Message) {
	int Reply = 0;

	cout << Message;
	cin >> Reply;

	return Reply;
}

stClients ReadClients() {
	stClients Client;

	Client.accNumber = ReadString("Enter Account Number?: ");
	Client.pinCode = ReadString("Enter PinCode?: ");
	Client.Name = ReadString("Enter Name?: ");
	Client.Phone = ReadString("Enter Phone?: ");
	Client.accBalance = ReadNumber("Enter Account Balance?: ");

	return Client;
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

void SaveLine(stClients Client) {
	string Line = ConvertRecordToLine(Client, "#//#");
	fstream ClientsData;

	ClientsData.open("Clients.txt", ios::out | ios::app);

	if (ClientsData.is_open()) {
		ClientsData << Line << "\n";
	}
}

void AddClient() {
	stClients Client = ReadClients();
	SaveLine(Client);
}

void AddClients() {
	char addMore = 'y';

	do {
		cout << "\n\t== Enter the client data ==\t\n\n";

		AddClient();

		cout << "\nClient successfully added, Do you want to add more?: [Y/N]: ";
		cin >> addMore;
	} while (tolower(addMore) == 'y');
}

int main() {
	srand((unsigned)time(NULL));

	AddClients();

	//system("pause>0");
	return 0;
}
