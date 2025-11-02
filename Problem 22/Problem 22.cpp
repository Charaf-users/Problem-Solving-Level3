#include<iostream>
#include<string >

using namespace std;

void PrintNumbersWithRecursion(short Number, int Prevs, int Prevs2) {
	int number = 0;
	if (Number > 0) {
		number = Prevs + Prevs2;
		Prevs2 = Prevs;
		Prevs = number;
		cout << number << "    ";
		PrintNumbersWithRecursion(Number - 1, Prevs, Prevs2);
	}
}
int main() {
	PrintNumbersWithRecursion(10, 0, 1);

	system("pause>0");
}