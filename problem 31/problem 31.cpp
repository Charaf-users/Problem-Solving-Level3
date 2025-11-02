#include<iostream>
#include<string >
#include<cctype>

using namespace std;

string readString()
{
	string s1;
	cout << "please enter  a string ? : " << endl;
	getline(cin, s1);

	return s1;

}

char readcharacter() {
	char letter;
	cout << "please enter a character ? : " << endl;
	cin >> letter;

	return letter;
}
char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}
short CountLetter(string s1, char letter, bool matchcase = true) {
	short counter = 0;
	for (short i = 0; i < s1.length(); i++) {
		if (matchcase) {
			if (s1[i] == letter) {
				counter++;
			}
			else
			{
				if (tolower(s1[i]) == tolower(letter))
					counter++;
			}
		}
	}
	return counter;
}

int main() {
	string  s1 = readString();
	char letter = readcharacter();

	cout << "\nLetter \'" << letter << "\' Count = " <<
		CountLetter(s1, letter);
	cout << "\nLetter \'" <<letter << "\' ";
	cout << "Or \'" << InvertLetterCase(letter) << "\' ";
	
	cout << " Count = " << CountLetter(s1, letter, true);
	system("pause>0");
}
