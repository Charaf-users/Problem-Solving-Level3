#include<iostream>
#include<string>


using namespace std;

string readStringName() {
	string name;
	cout << "please enter Your String ?" << endl;
	getline(cin, name);
	cout << "\n\n";
	return name;

}

void  PrintFirstletterOfString(string name) {

	bool istheFirstLetter = true;
	cout << "he first letter is there : " << endl;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] != ' ' && istheFirstLetter) {
			cout << name[i] << endl;
		}
		istheFirstLetter = (name[i] == ' ' ? true : false);
	}

}
int main() {
	
	PrintFirstletterOfString(readStringName());
	
	system("pause>0");
}