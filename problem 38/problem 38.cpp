#include<iostream>
#include<string>
#include<cctype>


using namespace std;

string readString() {
	string s1;
	cout << " string      =  ";
	getline(cin, s1);

	return s1;
}
string trimLeft(string s1) {
	
	for (short i = 0; i < s1.length(); i++) {
		if (s1[i]!=' ')
	return 	s1.substr(i,s1.length()-1);
	}

	return "";
}
string trimRight(string s1) {
	for (int i = s1.length() - 1; i >= 0;i--) {
		return s1.substr(0, i + 1);
	}
	return "";
}
string Trim(string s1) {
	return trimLeft(trimRight(s1));
}

int main() {
	string s1 = "    Charaf Eddin   ";
	cout << "trim left   = " << trimLeft(s1) << endl;
	cout << "trim right  = " << trimRight(s1) << endl;
	cout << "trim        = " << Trim(s1) << endl;
	 system("pause>0");

}