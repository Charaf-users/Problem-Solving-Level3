#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int randomnumber(int from, int to) {

	int randnum = rand() % (to - from + 1) + from;

	return randnum;
}

void fillMatrixWithRandomNumber(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = randomnumber(1, 10);
		}
	}
}

void printMatrix1(int arr[3][3], int Rows, int Cols) {
	cout << "the Matrix 1 :" << endl;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			printf("%0*d    ", 2 ,arr[i][j]);
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void fillMatrix2WithRandomNumber(int arr1[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr1[i][j] = randomnumber(1, 10);
		}
	
}
	
}

void printMatrix2(int arr1[3][3], int Rows, int Cols) {
	cout << "the Matrix 2 :" << endl;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			printf("%0*d    ", 2, arr1[i][j]);
		}
		cout << "\n";
	}
	cout << "\n\n";
}


void MutiplyTwoMatrix(int arr1[3][3],int result[3][3], int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			result[i][j] = arr[i][j] * arr1[i][j];
		}
		
	}
	
}

void printMituplyResult(int arr1[3][3], int result[3][3], int arr[3][3], int Rows, int Cols) {
	cout << "the Result is :" << endl;

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {

			cout << setw(3) << result[i][j] << "  ";

		}
		cout << "\n";
	}
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arr1[3][3];
	int result[3][3];

	fillMatrixWithRandomNumber(arr, 3, 3);
	printMatrix1(arr, 3, 3);


	fillMatrix2WithRandomNumber(arr1, 3, 3);
	printMatrix2(arr1, 3, 3);
	
	MutiplyTwoMatrix(arr1, result, arr, 3, 3);
	printMituplyResult(arr1, result, arr, 3, 3);


	system("pause>0");

}