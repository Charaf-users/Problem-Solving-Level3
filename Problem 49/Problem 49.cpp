#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>

using namespace std;
const string clientsFileName = "FileClients.txt";


struct Sclient {
	string CodeAccount;
	string CodePin;
	string Nameclient;
	string phone;
	double Ballance;
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

bool FindDataClientsFromfile(string AccountNumber, Sclient& client) {
	vector<Sclient>vClient = LoadClientsDataDromFile(clientsFileName);
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

int main() {
	Sclient client;
	string AccountNumber = readAccountNumber();
	if (FindDataClientsFromfile(AccountNumber, client)) {
		PrintclientsCard(client);
	}
	else {
		cout << "Sorry the Account number ("<<AccountNumber<<") not found or incorrect !";
	}
	system("pause>0");
	return 0;
}