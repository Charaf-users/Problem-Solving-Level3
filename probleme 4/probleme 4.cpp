#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int randomnumber(int from, int to) {
	int randomnum = rand() % (to - from + 1) + from;
	return randomnum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = randomnumber(1, 100);
		}
	}
}
void PrintMatrix(int arr[3][3], int rows, int cols) {
	cout << "the following 3x3 random number is :" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(3) << arr[i][j] << "  ";
		}
		cout << endl;
	}
}
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short i = 0; i <= RowNumber - 1; i++)
	{
		Sum += arr[i][Cols];
	}
	return Sum;
}
void printColsmatrix(int arr[3][3], short RowNumber, short Cols) {
	for (int j = 0; j < Cols ; j++) {
		cout << "sum of cols " << j + 1 << ": " << RowSum(arr, RowNumber, j) << endl;
	}
}

int main()
{

	srand((unsigned)time(NULL));
	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	PrintMatrix(arr, 3, 3);
	printColsmatrix(arr, 3, 3);
	
	system("pause>0");
}