#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void fillwithnumber(int arr[3][3], int rows, int cols) {
	int val = 1;
	cout << "The following 3x3 order matrix :" << endl;

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			arr[i][j] = val;
			val++;

			cout << setw(3) << val << "   ";
			
		}
		cout << "\n";
	}
}
void filltransportedmatrix(int arr[3][3],int arr1[3][3], int rows, int cols) {

	cout << "the following after transported matrix :" << endl;

	for (int j = 0; j < cols; j++) {

		for (int i = 0; i < rows; i++) {
			
			arr1[i][j]=arr[i][j] ;

			cout <<setw(3)<< arr1[i][j]<<"  ";

		}
		cout << "\n";
	}

}
int main() {
	int arr[3][3];
	int arr1[3][3];

	fillwithnumber(arr, 3, 3);

	filltransportedmatrix(arr,arr1, 3, 3);

	system("pause>0");
}