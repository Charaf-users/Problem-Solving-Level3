#include<iostream>
#include<string>
#include<cctype>

using namespace std;

char readcharacter() {
	char letter;
	cout << "please enter a character please? : " << endl;
	cin >> letter;
	return letter;
}
char inverstCaseCharacter(char letter) {
	cout << "\n the letter after inverted case :\n";
	return isupper(letter) ? tolower(letter) : toupper(letter);

}
int main() {
	char letter = readcharacter();
	letter = inverstCaseCharacter(letter);
	cout << letter << endl;
	system("pause>0");
}