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
short printEachWordOfString(string s1) {

	string define = " ";

	
	short pos = 0;
	short counter = 0;
	string sword;


	while ((pos = s1.find(define)) != std::string::npos) {
		sword = s1.substr(0, pos);
		if (sword != "") {
			
			counter++;
		}
		s1.erase(0, pos + define.length());
	}
	if (s1 != "") {
		counter++;
	}
	return counter;
}
int main() {

	string s1 = readString();

	cout << "you  number of each word of your string :";
	cout<<printEachWordOfString(s1);

	system("pause>0");
}
















