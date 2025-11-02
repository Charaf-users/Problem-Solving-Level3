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

string  UpperFirstletterOfString(string name ) {

	bool istheFirstLetter = true;
	cout << "the string after conversion  : " << endl;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] != ' ' && istheFirstLetter) {
			name[i] = toupper(name[i]);
		}
		istheFirstLetter = (name[i] == ' ' ? true : false);
	}
	return name;
}
int main() {

	string name = readStringName();
	
	name = UpperFirstletterOfString(name);
	cout << name << endl;
	system("pause>0");
}