#include<iostream>
#include<string >
#include<cctype>

using namespace std;

string readString() {
	string s1;
	cout << "Please enter your string ? :" << endl;
	getline(cin, s1);
	return s1;
}

int CountCapitalLetter(string s1) {
	int counter=0;
	for (int i = 0; i < s1.length(); i++) {
		if (isupper(s1[i])) {
			counter++;
		}
	}
	return counter;
}
int CountSmallLetter(string s1) {
	int counter = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (islower(s1[i])) {
			counter++;
		}
	}
	return counter;
}



int main() {
	string s1 = readString();
	
	cout << "the string length : " << s1.length() << endl;;
	cout << "the Capital letters is : " << CountCapitalLetter(s1) << endl;
	cout << "the small letters is :" << CountSmallLetter(s1);

	
	 system("pause>0");
}