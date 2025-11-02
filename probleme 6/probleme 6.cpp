#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void fillwithnumber(int arr[3][3], int rows, int cols) {
	int val = 1;
	cout << "The following 3x3 order matrix :" << endl;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(3) << val << "   ";
			val++;

		}
		cout << "\n";
		}
	

}
int main() {
	int arr[3][3];

	fillwithnumber(arr, 3, 3);
	system("pause>0");
}