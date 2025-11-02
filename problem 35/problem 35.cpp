#include<iostream>
#include<string>
#include<cctype>

using namespace std;


string readString() {
	string s1;
	cout << "Please enter a string ?";
	getline(cin, s1);

	return s1;
}
void printEachWordOfString(string s1) {

	string define = " ";

	cout << "you each word of your string :" << endl;

	short pos = 0;
	string sword;

	while ((pos = s1.find(define)) != std::string::npos) {
		sword = s1.substr(0, pos);

		if (sword != "") {

			cout << sword << endl;

		}
		s1.erase(0, pos + define.length());
	}
	if (s1 != "") {

		cout << s1 << endl;
	}
}
int main() {


	printEachWordOfString(readString());

	system("pause>0");
}
















