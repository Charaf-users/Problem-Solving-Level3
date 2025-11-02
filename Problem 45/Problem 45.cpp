#include<iostream>
#include<string>
#include<cctype>

using namespace std;


struct Sclient {
	string clientCode;
	string CodePin;
	string ClientName;
	string Phone;
	double Balance;
};

Sclient ReadingInformation() {
	Sclient client;
	cout << "Enter Client Code ?  ";
	getline(cin, client.clientCode);

	cout << "enter Code Pin ?  ";
	getline(cin, client.CodePin);

	cout << " enter you full Name ?  ";

	getline(cin, client.ClientName);
	cout << " enter your phone number ?   ";
	getline(cin, client.Phone);

	cout << "Enter your Balance ?       ";
	cin >> client.Balance;
	return client;
}
string ConvertRecordToLine(Sclient client, string seperator = "#//#") {
	string stclient = "";
	stclient += client.clientCode + seperator;
	stclient += client.CodePin + seperator;
	stclient += client.ClientName + seperator;
	stclient += client.Phone + seperator;
	stclient += to_string(client.Balance) + seperator;


	return stclient;
}
int main() {
	cout << " Please enter Client Data : \n\n";
	Sclient  client;
	client = ReadingInformation();

	cout << "\n\n";
	cout << "Client Record  for saving is :\n" << ConvertRecordToLine(client);
	system("pause>0");
		
}