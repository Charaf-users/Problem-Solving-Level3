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
	string sWord ;
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
Sclient AddclientToData(string line, string seperator="#//#") {
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

void PrintClientData(Sclient client) {
	cout << "|" << setw(15) << left << client.CodeAccount;
	cout << "|" << setw(10) << left << client.CodePin;
	cout << "|" << setw(40) << left << client.Nameclient;
	cout << "|" << setw(12) << left << client.phone;
	cout << "|" << setw(12) << left << client.Ballance;
}

void PrintALLClients(vector<Sclient>vClient) {
	cout << "\n\t\t\t\tclients list(" << (vClient.size()) << ") client(s).";
	cout << "\n______________________________________________________";
	cout << "__________________________________________\n" << endl;
	cout << "|" << left << setw(15) << "Account Code";
	cout << "|" << left << setw(10) << "Code Pin";
	cout << "|" << left << setw(40) <<  "Name Client";
	cout << "|" << left << setw(12) << "phone number";
	cout << "|" << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";    
	cout << "_________________________________________\n" << endl;
	for (Sclient client : vClient) {
		PrintClientData(client);
		cout << endl;
	}
	cout << "\n_______________________________________________________";     
	cout << "_________________________________________\n" << endl;
}
int main() {
	vector<Sclient> vClient = LoadClientsDataDromFile(clientsFileName);
	PrintALLClients(vClient);
	system("pause>0");
	return 0;
}