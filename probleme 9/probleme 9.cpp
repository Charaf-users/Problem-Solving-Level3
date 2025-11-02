#include<iostream>
#include<string>

using namespace std;

int randomNumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}

void fillMatrixWithRandomnumber(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			arr[i][j] = randomNumber(1, 10);
		}
	}

}
void printMatrix(int arr[3][3], int Rows, int Cols) {
	cout << "the following matrix is : " << endl;

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			printf("%0*d   ",2, arr[i][j]);

		}
		cout << "\n";
	}
	cout << "\n\n";
}
void printMidleRows(int arr[3][3], int Rows) {
	short midlerows = Rows / 2;

	cout << "the midle rows of matrix 1 :" << endl;


	for (int j = 0; j < 3; j++) {

		printf("%0*d    ", 2, arr[midlerows][j]);
	}
	cout <<"\n\n";

}
void printMidleCols(int arr[3][3], int Cols) {
	short midlecols = Cols / 2;
	cout << "the midle Cols of matrix 1 :" << endl;

	for (int i = 0; i < 3;i++) {

		printf("%0*d    ", 2, arr[i][midlecols]);

	}
	

}


int main() {

	srand((unsigned)time(NULL));

	int arr[3][3];

	fillMatrixWithRandomnumber(arr, 3, 3);
	printMatrix(arr, 3, 3);

	printMidleRows(arr, 3);
	printMidleCols(arr, 3);

	system("pause>0");


}