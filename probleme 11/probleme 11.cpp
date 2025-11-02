#include<iostream>
#include<string>

using namespace std;

int randonumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}
void FillMatrixWithRandomnumber(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr[i][j] = randonumber(1, 10);
		}
	}

}
void printmatrix1(int arr[3][3], int Rows, int Cols) {
	cout << "the following 3x3 random matrix 1:" << endl;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			printf("%0*d     ", 2, arr[i][j]);

		}
		cout << "\n";
	}
	cout << "\n\n";

}
void FillMatrix1WithRandomnumber(int arr1[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			arr1[i][j] = randonumber(1, 10);
		}
	}
}
void printmatrix2(int arr1[3][3], int Rows, int Cols) {
	cout << "the following 3x3 random matrix 2:" << endl;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			printf("%0*d     ", 2, arr1[i][j]);

		}
		cout << "\n";
	}
	cout << "\n\n";
}
int sumofmatrix1(int arr[3][3], int Rows, int Cols) {
	int sum = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
int sumofmatrix2(int arr1[3][3], int Rows, int Cols) {
	int sum1 = 0;

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			sum1 += arr1[i][j];
		}
	}
	return sum1;
}
void comparetwoMatrix(int arr[3][3], int arr1[3][3], int Rows, int Cols) {
	string result;
	result = (sumofmatrix1(arr, Rows, Cols) == sumofmatrix2(arr1, Rows, Cols)) ? "yes:  this matrixe eaqual " : "No: this matrixe not equal";
	cout << result << endl;
}





int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arr1[3][3];


	FillMatrixWithRandomnumber(arr, 3, 3);
	printmatrix1(arr, 3, 3);

	FillMatrix1WithRandomnumber(arr1, 3, 3);
	printmatrix2(arr1, 3, 3);

	sumofmatrix1(arr, 3, 3);
	sumofmatrix2(arr1, 3, 3);

	comparetwoMatrix(arr, arr1, 3, 3);


	system("pause>0");



}