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

	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1== 'o') || (Ch1 == 'u'));
}

short countVowel(string s1) {
	int counter = 0;

	for (short i = 0; i < s1.length(); i++) {

		if (IsVowel(s1[i])) {

			counter++;
		}
	}
	return counter;
}

int main() {
	string s1 = readString();
	cout << "the vowel letters is : " << countVowel(s1) << endl;
	system("pause>0");
}