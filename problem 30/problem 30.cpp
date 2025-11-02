#include<iostream>
#include<string >
#include<cctype>

using namespace std;

string readString() {
	string s1;
	cout << "please your String ?" << endl;
	getline(cin, s1);

	return s1;


}

char readCharacter()
{
	char letter;
	cout << "please enter a character : " << endl;
	cin >> letter;

	return letter;
}

short counterCharacterLetter(string s1, char letter) {
	short counter = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == letter) {
			counter++;
		}
	}
	return counter;
}

int main() {
	string s1 = readString();
	char letter = readCharacter();
	cout << "the letter ' " << letter << "' count = " << counterCharacterLetter(s1, letter);
	system("pause>0");

}