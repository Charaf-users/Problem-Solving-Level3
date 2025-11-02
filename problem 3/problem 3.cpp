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
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}
void sumMatrixInArray(int arr[3][3],int arr1[3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {
		arr1[i] = RowSum(arr, i, Cols);
	}
}
void PrintMatrixInArray(int arr1[3], short Rows) {
	for (int i = 0; i < Rows; i++) {
		cout << "Sum row in array : "<<i+1<<": " << arr1[i] << endl;
	}
}



int main()
{
	
	srand((unsigned)time(NULL));
	int arr[3][3];
	
	FillMatrixWithRandomNumbers(arr, 3, 3);
	
	PrintMatrix(arr, 3, 3);
	int arr1[3];
	sumMatrixInArray(arr,arr1, 3, 3);
	PrintMatrixInArray( arr1, 3);
	system("pause>0");
}