#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string readcharacter() {
	string letter;
	cout << "please enter a character please? : " << endl;
	getline(cin, letter);
	return letter;
}
char inverstCaseCharacter(char letter1) {

	return isupper(letter1) ? tolower(letter1) : toupper(letter1);

}
string inverstedLetters(string letter) {
	cout << "the string after inverted letters\n";
	for (int i = 0; i < letter.length(); i++) {
		letter[i] = inverstCaseCharacter(letter[i]);
	}
	return letter;
}
int main() {
	string letter = readcharacter();
	letter = inverstedLetters(letter);
	cout << letter << endl;
	system("pause>0");
}