#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

string joinString(vector<string>Vstring, string Delim) {

	string s1="";

	for (string& s : Vstring) {
		s1 = s1 + s + Delim;
	}

	return s1.substr(0,s1.length() - Delim.length());

}


int main() {
	vector<string>Vstring = { "charaf","mohssine","mohamed","ahmed" };

	cout << "string after join :" << endl;
	cout << joinString(Vstring, "     wowo    ");

	system("pause>0");
}  