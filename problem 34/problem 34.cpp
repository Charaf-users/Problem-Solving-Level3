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
bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);

	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

void PrintAllVowel(string s1) {
	
	cout << "the vowel letters are : ";

	for (short i = 0; i < s1.length(); i++) {

		if (IsVowel(s1[i])) 

			cout << s1[i]<<"    ";
		
	}
	
}

int main() {
	string s1 = readString();

	 PrintAllVowel(s1);


	system("pause>0");
}