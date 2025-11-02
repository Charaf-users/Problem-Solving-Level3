#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

string joinString(vector<string>Vstring, string Delim) {

	string s1 = "";

	for (string& s : Vstring) {
		s1 = s1 + s + Delim;
	}

	return s1.substr(0, s1.length() - Delim.length());

}

string joinString(string arr[],short length, string Delim) {
	string s1 = "";

	for (int i = 0; i < length; i++) {
		s1 = s1 + arr[i] + Delim;
	}
	return s1.substr(0, s1.length() - Delim.length());
}


int main() {
	vector<string>Vstring = { "charaf","mohssine","mohamed","ahmed" };
	string arr[] = {"charaf","mohssine","mohamed","ahmed"};

	cout << "Vector after join :" << endl;
	cout << joinString(Vstring, "  ") << endl;

	cout << "Array after join :" << endl;
	cout << joinString(arr,4, " ,");

	system("pause>0");
}