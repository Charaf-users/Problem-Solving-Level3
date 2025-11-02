#include<iostream>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;
const string clientsFileName = "FileClients.txt";


struct Sclient {
	string CodeAccount;
	string CodePin;
	string Nameclient;
	string phone;
	double Ballance;
};

Sclient AddClient() {

	Sclient client;
	cout << "enter Code Account ?:\n";
	getline(cin>>ws, client.CodeAccount);
	cout << "enter Code Pin :\n";
	getline(cin, client.CodePin);
	cout << "enter your Full Name ? :\n";
	getline(cin, client.Nameclient);
	cout << "enter your number phone ?  :\n";
	getline(cin, client.phone);
	cout << "enter your balance :\n";
	cin >> client.Ballance;

	return client;
}

string ConvertToLineRecord(Sclient Client, string seperator = "#//#") {

	string stclient = "";
	stclient += Client.CodeAccount + seperator;
	stclient += Client.CodePin + seperator;
	stclient += Client.Nameclient + seperator;
	stclient += Client.Nameclient + seperator;
	stclient += to_string(Client.Ballance )+ seperator;

	return stclient;
}
void AddDataToFile(string FileName, string DataToLine) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << DataToLine << endl;
		MyFile.close();
	}
	
}

void AddNewClient() {
	Sclient client;
	client = AddClient();
	AddDataToFile(clientsFileName, ConvertToLineRecord(client));
}

void AddClients() {
	char More = 'Y';
	do {
		system("cls");
		cout << "Adding New Clients \n\n";
		AddNewClient();
		cout << "Do you want to add more clients :";
		cin >> More;
	} while (toupper(More == 'Y'));
}
int main() {

	AddClients();

	system("pause>0");
	return 0;
}