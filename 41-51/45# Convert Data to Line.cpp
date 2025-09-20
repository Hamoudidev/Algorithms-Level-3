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

string ConvertRecordToLine(stClients Clients, string spaceShape = "#//#") {
	string Word = "";

	Word += Clients.accNumber + spaceShape;
	Word += Clients.pinCode + spaceShape;
	Word += Clients.Name + spaceShape;
	Word += Clients.Phone + spaceShape;
	Word += to_string(Clients.accBalance);

	return Word;
}


int main() {
	srand((unsigned)time(NULL));

	cout << "\t== Enter the client data ==\t\n\n";

	cout << endl << ConvertRecordToLine(ReadClients(), "#//#") << endl;

	system("pause>0");
}
