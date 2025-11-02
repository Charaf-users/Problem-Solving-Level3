#include<iostream>
#include<string>
#include<vector>
#include<cctype>


using namespace std;


string ReplacestringToWord(string s1, string word, string replaceWord) {


	short pos = s1.find(word);

	while (pos != std::string::npos) {
		s1 = s1.replace(pos, word.length(), replaceWord);
		pos = s1.find(word);
	}

	return s1;


}
int main() {
	string s1 = "welcome to morroco,morroco is good country";
	string word = "morroco";
	string replaceWord = "USA";

	cout << "the original string :" << endl;

	cout << s1 << endl;

	cout << "the string after :" << endl;

	cout << ReplacestringToWord(s1, word, replaceWord
	);

	system("pause>0");



}