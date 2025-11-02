#include<iostream>
#include<string>
using namespace std;

void PrintFibonacciSeries(short Number) {
	short number = 0;
	int Prevs = 1, Prevs2 = 0;
	cout << "1  ";
	for (int i = 2; i <= Number; i++) {
		number = Prevs + Prevs2;
		cout << number << "    ";
		Prevs2 = Prevs;
		Prevs = number;


	}
}
int main() {
	PrintFibonacciSeries(10);
	system("pause>0");

}