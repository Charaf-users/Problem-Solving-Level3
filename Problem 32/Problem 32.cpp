#include<iostream>
#include<string>
#include<cctype>

using namespace std;

char readcharacter() {
	char letter;
	cout << "please enter a character ? :";
	cin >> letter;

	return letter;
}

bool isVowel(char letter) {
	letter = tolower(letter);
	
	return  (letter == ('a') || letter == ('e') || letter == ('i') || letter == ('o') || letter == ('u'));
						
				

}
int main() {
	char letter = readcharacter();
	if (isVowel(letter)) {
		cout << "Yes , is vowel letter ." << endl;
		
	}
	else {
		cout << "No,is not Vowel letter ." << endl;
	}
		
	

	system("pause>0");

}