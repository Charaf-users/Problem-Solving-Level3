#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;


string readString() {
	string s1;

	cout << "Please enter a string ?"<<endl  ;

	getline(cin, s1);

	return s1;
}

short countEachword(string s1) {
	string define = " ";

	cout << "token is : ";

	short pos = 0;
	short counter = 0;
	string sword;

	while ((pos = s1.find(define)) != std::string::npos) {

		sword = s1.substr(0, pos);

		if (sword != "") {

			counter++;

		}
		s1.erase(0, pos + define.length());
	}
	if (s1 != "") {
		
		counter++;
	}
	return counter;

}
vector <string>  printEachWordOfString(string s1) {

	vector <string> ssplit;

	string define = " ";


	short pos = 0;
	short counter = 0;
	string sword;


	while ((pos = s1.find(define)) != std::string::npos) {

		sword = s1.substr(0, pos);


		if (sword != "") {

			ssplit.push_back(sword);
			
		}
		s1.erase(0, pos + define.length());
	}
	if (s1 != "") {
		ssplit.push_back(s1);

		
	}
	return ssplit;
}
int main() {
	string s1 = readString();

	vector<string>split= printEachWordOfString(s1);


	cout << countEachword(s1) << endl;


	for (string ssplit :split ) {

		cout << ssplit << endl;
	}
	


	system("pause>0");
}
