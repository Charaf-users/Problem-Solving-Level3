#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>

using namespace std;
const string clientsFileName = "FileClient.txt";


struct Sclient {
	string CodeAccount;
	string CodePin;
	string Nameclient;
	string phone;
	double Ballance;
	bool MarkForDelete = false;
};

vector<string> splitstring(string s1, string Delim) {
	vector<string>vString;
	int pos = 0;
	string sWord;
	while ((pos = s1.find(Delim)) != std::string::npos) {
		sWord = s1.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		s1.erase(0, pos + Delim.length());
	}
	if (s1 != "") {
		vString.push_back(s1);
	}
	return vString;
}
Sclient AddclientToData(string line, string seperator = "#//#") {
	Sclient client;
	vector<string>vDataClient;
	vDataClient = splitstring(line, seperator);
	client.CodeAccount = vDataClient[0];
	client.CodePin = vDataClient[1];
	client.Nameclient = vDataClient[2];
	client.phone = vDataClient[3];
	client.Ballance = stod(vDataClient[4]);

	return client;

}
string RecordLineData(Sclient client, string seperator = "#//#") {
	string stRecordData;
	stRecordData += client.CodeAccount + seperator;
	stRecordData += client.CodePin + seperator;
	stRecordData += client.Nameclient + seperator;
	stRecordData += client.phone + seperator;
	stRecordData += to_string(client.Ballance) + seperator;

	return stRecordData;
}
vector<Sclient>LoadClientsDataDromFile(string FileName) {
	vector<Sclient>vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string line;
		Sclient client;

		while (getline(MyFile, line)) {
			client = AddclientToData(line);
			vClient.push_back(client);
		}
		MyFile.close();
	}
	return vClient;
}
string readAccountNumber() {
	string AccountNumber = "";
	cout << "\t\t     please enter account number ?: ";
	cin >> AccountNumber;

	return AccountNumber;
}

bool FindDataClientsFromfile(string AccountNumber, vector<Sclient>vClient, Sclient& client) {

	for (Sclient C : vClient) {
		if (C.CodeAccount == AccountNumber) {
			client = C;
			return true;

		}

	}
	return false;
}

void PrintclientsCard(Sclient client) {

	cout << "\t\t the following are the client details :" << endl;
	cout << "\t\tAccount Number : " << client.CodeAccount << endl;
	cout << "\t\tCode Pin       : " << client.CodePin << endl;
	cout << "\t\tFull Name      : " << client.Nameclient << endl;
	cout << "\t\tphone number   :" << client.phone << endl;
	cout << "\t\tbalance        :" << client.Ballance << endl;
}
Sclient ChangeClientAccount(string AccountNumber) {
	Sclient client;
	client.CodeAccount = AccountNumber;
	cout << "\n\n";
	cout << "enter code Pin: ";
	getline(cin >> ws, client.CodePin);
	cout << "enter your full Name: ";
	getline(cin, client.Nameclient);
	cout << "enter your phone : ";
	getline(cin, client.phone);
	cout << "enter balance : ";
	cin >> client.Ballance;
	return client;
}
vector<Sclient> SaveClientDataToFile(string FileName, vector<Sclient>vClient) {

	fstream MyFile;
	string DataLine;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		for (Sclient C : vClient) {

			if (C.MarkForDelete == false) {

				DataLine = RecordLineData(C);

				MyFile << DataLine << endl;

			}
		}

		MyFile.close();

	}
	return vClient;
}
bool updateClientByAccountNumber(string AccountNumber, vector<Sclient>& vClient) {
	Sclient client;
	char answer = 'n';

	if (FindDataClientsFromfile(AccountNumber, vClient, client)) {
		PrintclientsCard(client);
		cout << "\n\ndo you want update the account (y/n)";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			for (Sclient& C : vClient) {
				if (C.CodeAccount == AccountNumber) {
					C = ChangeClientAccount(AccountNumber);
					break;
				}
			}
			SaveClientDataToFile(clientsFileName, vClient);
			cout << "the update is done" << endl;
			return true;
		}
	}
	else {
		cout << "the code account (" << AccountNumber << ") is not found :(" << endl;
		return false;
	}
}
int main() {
	vector<Sclient>vClient = LoadClientsDataDromFile(clientsFileName);
	string AccountNumber= readAccountNumber();
	
	updateClientByAccountNumber(AccountNumber, vClient);
	system("pause>0");
	return 0;
}