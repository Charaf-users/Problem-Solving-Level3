#include<iostream>
#include<string >
#include<vector>
#include<cctype>
#include<fstream>

using namespace std;


struct Sclient {
	string CodeClient;
	string CodePin;
	string NameClient;
	string Phone;
	double Balance;
};


vector<string> splitString(string S1, string Delim) {
	vector<string>VString;
	int pos = 0;
	string sword;

	while ((pos = S1.find(Delim)) != std::string::npos) {
		sword = S1.substr(0, pos);
		if (sword != "") {
			VString.push_back(sword);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "") {
		VString.push_back(S1);

	}
	return VString;
}
Sclient ConvertLinetoRecord(string line, string seperator = "#//#") {
	Sclient client;
	vector<string>VclientData;
	VclientData = splitString(line, seperator);
	client.CodeClient = VclientData[0];
	client.CodePin = VclientData[1];
	client.NameClient = VclientData[2];
	client.Phone = VclientData[3];
	client.Balance = stod(VclientData[4]);
	

	return client;
}
void PrintclientRecord(Sclient client) {
	cout << "\n\n the follloxing is the extracted client record :";
	cout << "\n Account Number :" << client.CodeClient;
	cout << "\n Pin code : " << client.CodePin;
	cout << "\n Full Name :" << client.NameClient;
	cout << "\n Phone   :" << client.Phone;
	cout << "\nAccount Balance:" << client.Balance;
}int main() {
	string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	cout << "\nLine Record is:\n";
	cout << stLine; Sclient Client = ConvertLinetoRecord(stLine);
	PrintclientRecord(Client);
	system("pause>0");
	return 0;
}