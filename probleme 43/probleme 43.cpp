#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string>SpliteString(string s1, string Delim) {

	vector<string>vString;
	short pos = 0;
	string word;
	while ((pos = s1.find(Delim)) != std::string::npos) {
		word = s1.substr(0, pos);
		if (word != "") {
			vString.push_back(word);

		}
		s1.erase(0, pos + Delim.length());
	}
	if (s1 != " ") {
		vString.push_back(s1);
	}

	return vString;


}
string joinString(vector<string> vString, string Delim) {
	string s1;
	for (string& s : vString) {
		s1 = s1 + s + Delim;
	}
	return s1.substr(0, s1.length() - Delim.length());
}
string LowerAllString(string s1) {
	for (short i = 0; i < s1.length(); i++) {
		s1[i] = tolower(s1[i]);
	}
	return s1;
}

string ReplaceWordInStringUsingSplit(string s1, string StringToReplace, string RepalceTo, bool MatchCase = true) {
	vector<string>vString = SpliteString(s1, " ");

	for (string& s : vString) {
		if (MatchCase) {
			if (s == StringToReplace) {
				s = RepalceTo;
			}
		}
		else {
			if (LowerAllString(s) == LowerAllString(StringToReplace)) {
				s = RepalceTo;
			}
		}
	}
	return joinString(vString, " ");
 }
int main() {
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";  


	cout << "\nOriginal String:\n" << S1;   
	cout << "\n\nReplace with match case: ";  
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);   
	cout << "\n\nReplace with dont match case: ";     
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);   
	system("pause>0");
}