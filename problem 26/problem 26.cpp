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

string lowerFirstletterOfString(string name) {

	
	cout << "after toupper letters  : " << endl;
	for (int i = 0; i < name.length(); i++) {
		
			name[i] = toupper(name[i]);
		
		
	}
	return name;
}
string  UpperFirstletterOfString(string name) {


	cout << "after tolower letters  : " << endl;
	for (int i = 0; i < name.length(); i++) {

		name[i] = tolower(name[i]);


	}
	return name;
}
int main() {

	string name = readStringName();
	name = lowerFirstletterOfString(name);
	cout << name << endl;

	name = UpperFirstletterOfString(name);
	cout << name << endl;


	
	system("pause>0");
}