#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int randomNumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void fillMatrixWithRandomnumber(int arr[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = randomNumber(1, 10);
		}
	}
}
void printmatrix(int arr[3][3], int rows, int cols) {
	cout << "the folowing 3x3 random matrix: " << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%0*d    ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}
int sumofMatrix(int arr[3][3], int rows, int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum =sum +arr[i][j];
		}
		cout << "\n";
	}
	return sum;
}
void printsummatrix(int arr[3][3] , int rows, int cols) {
	cout <<"the sum of matrix is :" << sumofMatrix(arr, rows, cols) << endl;
}





int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];
	
	fillMatrixWithRandomnumber(arr, 3, 3);

	printmatrix(arr, 3, 3);
	sumofMatrix(arr,  3, 3);	
	printsummatrix(arr , 3, 3);

	system("pause>0");
}