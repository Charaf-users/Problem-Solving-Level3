#include<iostream>
#include<string>
#include<cctype>

using namespace std;


string RemovePunctuation( string& input) {
    string result = "";

    for (short i = 0; i < input.length(); i++) {

        if (!ispunct(input[i])) {

            result += input[i];
        }
   }
    return result;
}
int main() {
    string input = "Hello , my name is charaf eddine ; from Morroco!";
   

    cout << "the original : \n" << input << endl;
    cout << "after the remove : \n" << RemovePunctuation(input);

    system("pause>0");
}