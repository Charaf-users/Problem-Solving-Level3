#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>

using namespace std;

const string clientFileNames = "clients.txt";

enum eMaineMenu {
	eshowClients = 1,
	eAddClients = 2,
	edeleteClients = 3,
	eUpdateClients = 4,
	eFindClienrs=5,
	eExitProgramme=6

};
struct sClient {

	string AccountNumber;
	string CodePin;
	string FullName;
	string phone;
	double balance;
	bool Markdelet = false;
};

vector<string> splingString(string s1, string delim) {

	vector<string>vString;

	short pos = 0;
	string sWord;

	while ((pos = s1.find(delim)) != std::string::npos) {
		if (sWord != " ") {

			vString.push_back(sWord);
		}
			
		s1.erase(0, pos + delim.length());
	 }
	if (s1 != " ") {

		vString.push_back(s1);
	}
	return vString;
	}
string convertLineToRecord(sClient client, string seperator = "#//#") {

	string lineRecord = "";

	lineRecord += client.AccountNumber+seperator;
	lineRecord += client.CodePin + seperator;
	lineRecord += client.FullName + seperator;
	lineRecord += client.phone + seperator;
	lineRecord += to_string(client.balance);

	return lineRecord;

}

sClient convertLineToRecordData(string line, string seperator = "#//#") {

	sClient client;

	vector<string>vDataClients;

	client.AccountNumber = vDataClients[0];
	client.CodePin = vDataClients[1];
	client.FullName = vDataClients[2];
	client.phone = vDataClients[3];
	client.balance = stod(vDataClients[4]);

	return client;
}

void AddRecordDataToFile(string FileName,string SDataLine) {

	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		cout << SDataLine << endl;
	}
	MyFile.close();

}

vector<sClient> LoadClientsDataClients(string NameFile) {
	fstream myFile;
	vector<sClient> vClients;

	myFile.open(NameFile, ios::in);
	if (myFile.is_open()) {
		string line;
		sClient client;

		while (getline(myFile, line)) {
			client = convertLineToRecordData(line);
			vClients.push_back(client);
		}
		myFile.close();
	}
	return vClients;
}
bool clientexistByAccountNumber(string AccountNumber, string NameFile) {
	vector<sClient>vClients;
	fstream MyFile;

	MyFile.open(NameFile, ios::in);
	if (MyFile.is_open()) {
		string line;
		sClient client;
		while(getline(MyFile,line))
		{
			client = convertLineToRecordData(line);

			if (client.AccountNumber == AccountNumber) {
				MyFile.close();
				return true;

			}
			vClients.push_back(client);
		}
		MyFile.close();
	}
	return false;
}



void printForOneClientCard(sClient client) {
	cout << "|" << setw(15) << left << client.AccountNumber;
	cout << "|" << setw(10) << left << client.CodePin;
	cout << "|" << setw(40) << left << client.FullName;
	cout << "|" << setw(12) << left << client.phone;
	cout << "|" << setw(12) << left << client.balance;
}

void printallclientsCards() {
	vector <sClient> vClients = LoadClientsDataClients(clientFileNames);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";    
	cout << "\n_______________________________________________________";   
	cout << "_________________________________________\n" << endl;     
	cout << "| " << left << setw(15) << "Accout Number";    
	cout << "| " << left << setw(10) << "Pin Code";     
	cout << "| " << left << setw(40) << "Client Name";     
	cout << "| " << left << setw(12) << "Phone";    
	cout << "| " << left << setw(12) << "Balance";    
	cout << "\n_______________________________________________________";    
	cout << "_________________________________________\n" << endl; 
		for (sClient client : vClients) {
			printForOneClientCard(client);        
	cout << endl; }   
	cout << "\n_______________________________________________________";    
	cout << "_________________________________________\n" << endl;
}

void printClientCard(sClient client) {
	cout << "___________________________________________________";
	cout << "the following client card details :" << endl;
	cout << "\nAccount Number :" << client.AccountNumber;
	cout << "\nCode Pin       :" << client.CodePin;
	cout << "\nFull Name      :" << client.FullName;
	cout << "\nphone          :" << client.phone;
	cout << "\nbalance        :" << client.balance;
	cout << "_____________________________________________________";
}
sClient ReadNewClients() {

	sClient client;
	cout << "enter Account number ?:";
	getline(cin >> ws, client.AccountNumber);
	cout << "  enter code Pin ? : ";
	getline(cin, client.CodePin);
	cout << "enter your ful Name ?:";
	getline(cin, client.FullName);
	cout << "enter your phone number ? :";
	getline(cin, client.phone);
	cout << "enter your balance you want to add ? :";
	cin >> client.balance;

	return client;
}
void addNewClients() {
	sClient client;
	client = ReadNewClients();
	AddRecordDataToFile(clientFileNames, convertLineToRecord(client));
}
void addClient() {
	char addMore = 'Y';
	do {
		system("cls");
		cout << "Adding New Clients :" << endl;
		addNewClients();

		cout << "client added succcefuly .do you want to add more ? (y/n) :";
		cin >> addMore;

	} while (toupper(addMore) == 'Y');
}
bool findClientbyAccountNumber(string AccountNumber, vector<sClient>vClients, sClient& client) {

	

	for (sClient C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			client = C;
			return true;
		}
	}
	return false;
}
bool MarkClientForDeletByAccountNumber(string AccountNumber, vector<sClient>& vClients) {

	for (sClient& C : vClients) {

		if (C.AccountNumber == AccountNumber) {

			C.Markdelet = true;
			return true;
		}
	}
	return false;
}
vector<sClient>SaveClientsDataToFile(string FileName, vector<sClient>vClients) {
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	string dataLine;


	if (MyFile.is_open()) {

		for (sClient C : vClients) {

			if (C.Markdelet == false) {

				dataLine = convertLineToRecord(C);
				MyFile << dataLine << endl;
			}
		}

		MyFile.close();

	}
	return vClients;
}
bool DeletClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
	sClient client;
	char Answer = 'n';
	if (findClientbyAccountNumber(AccountNumber, vClients, client)) {
		printClientCard(client);
		cout << "\n Are you sure do you want delete this  client account ? (y/n) :";
		cin >> Answer;
		if (  Answer=='y'||Answer == 'Y') {

			MarkClientForDeletByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(clientFileNames, vClients);
			vClients = LoadClientsDataClients(clientFileNames);

			cout << "\n client delete Successfuly";
			return true;
		}
	}
	else {
		cout << "client with Account Number (" << AccountNumber << ") is not found :(";
		return false;
	}
}
sClient changeClientrecord(string AccountNumber) {
	sClient client;
	client.AccountNumber == AccountNumber;
	cout << "\n enter your New Code pin : ";
	getline(cin, client.CodePin);
	cout << "\nenter your New Name :";
	getline(cin, client.FullName);
	cout << "\nenter your New number phone :";
	getline(cin, client.phone);
	cout << "entre your New Balance :";
	cin >> client.balance;

	return client;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
	sClient client;
	char Answer = 'n';
	if (findClientbyAccountNumber(AccountNumber, vClients, client)) {

		printClientCard(client);
		cout << "\nAre you sure do you want update this client (y/n):";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			for (sClient& C : vClients) {
				if (C.AccountNumber == AccountNumber) {
					C = changeClientrecord(AccountNumber);
					break;
				}
			}
			SaveClientsDataToFile(clientFileNames, vClients);
			cout << "\n\n Client update succesfuly";
			return true;
		}
	}
	else {
		cout << "\nClient with this Account number (" << AccountNumber << ") is not found :(";
		return false;
	}
}
string ReadAccountNumber() {
	string AccountNumber = "";
	cout << "enter Account number ?:";
	cin >> AccountNumber;
	return AccountNumber;
}
void showAddingNewclient() {
	cout << "\n-------------------------------\n";
	cout << "\t Adding New client section ";
	cout << "\n---------------------------------\n";
	addClient();
}
void showdeleteClient() {
	cout << "\n-------------------------------\n";
	cout << "\tDelete  client section ";
	cout << "\n---------------------------------\n";
	vector<sClient>vClients = LoadClientsDataClients(clientFileNames);
	string AccountNumber = ReadAccountNumber();
	DeletClientByAccountNumber(AccountNumber, vClients);
}
void showUpdateClient() {
	cout << "\n-------------------------------\n";
	cout << "\tUpdate client section ";
	cout << "\n---------------------------------\n";
	vector<sClient>vClients = LoadClientsDataClients(clientFileNames);
	string AccountNumber = ReadAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}
void showFindclient() {
	sClient client;
	cout << "\n-------------------------------\n";
	cout << "\tFind  client section ";
	cout << "\n---------------------------------\n";
	vector<sClient>vClients = LoadClientsDataClients(clientFileNames);
	string AccountNumber = ReadAccountNumber();
	if (findClientbyAccountNumber(AccountNumber, vClients,client)) {
		printClientCard(client);
	}
	else {
		cout << "this Account Number (" << AccountNumber << ") is not found :(";
	}
}
void showEndPrograme() {
	cout << "\n-------------------------------\n";
	cout << "\tEnd Program :)";
	cout << "\n---------------------------------\n";
}
void backToMainMenu() {
	cout << "press any key to go back to main menu ....";
	system("pause>0");
	
}



short choseMainMenuOptions() {
	short choice = 0;
	cout << "chose what you want to do [1 to 6 ]:";
	cin >> choice;
	return choice;
}

void mainmenu(eMaineMenu mainmenu) {
	switch (mainmenu) {
	case eMaineMenu::eshowClients:
		system("cls");
		printallclientsCards();
		backToMainMenu();
		break;
	case eMaineMenu::eAddClients:
		system("cls");
		showAddingNewclient();
		backToMainMenu();
		break;
	case eMaineMenu::edeleteClients:
		system("cls");
		showdeleteClient();
		backToMainMenu();
		break;
	case eMaineMenu::eUpdateClients:
		system("cls");
		showUpdateClient();
		backToMainMenu();
		break;
	case eMaineMenu::eFindClienrs:
		system("cls");
		showFindclient();
		backToMainMenu();
		break;
	case eMaineMenu::eExitProgramme:
		system("cls");
		showEndPrograme();
		backToMainMenu();
		break;
	}
}
void MainMenu() { 
	system("cls");     
	cout << "===========================================\n";   
	cout << "\t\tMain Menue Screen\n";     
	cout << "===========================================\n";     
	cout << "\t[1] Show Client List.\n";   
	cout << "\t[2] Add New Client.\n";     
	cout << "\t[3] Delete Client.\n";    
	cout << "\t[4] Update Client Info.\n";     
	cout << "\t[5] Find Client.\n";     
	cout << "\t[6] Exit.\n";    
	cout << "===========================================\n"; 
	mainmenu((eMaineMenu)choseMainMenuOptions()); 
}

int main() {
	while (true) {
		MainMenu();
	}
	system("pause>0");
	return 0;
}