#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//printf(" %0*d ", 2, arr[i][j]);
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
bool IsNumberInMatrix(int arr[3][3], int Number, short Rows,short Cols)
{
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == Number)
			{
				return true;
			};
		}
	}
	return false;
}
void PrintIntersectedNumbers(int arr[3][3], int arr1[3][3], short Rows, short Cols) {
	int num;
	cout << "Intersected Numbers are :" << endl;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			num = arr[i][j];
			if (IsNumberInMatrix(arr1, num, Rows, Cols)) {
				cout << "     " << num;
			}
		}
	}

}



int main() {
	int arr[3][3] = { {10,12,3,},{4,53,61} ,{ 57,18,19 } };
	int arr1[3][3] = { {10,11,12 },{13,4,15},{16,17,18} };

	cout << "matrix 1 : " << endl;
	PrintMatrix(arr, 3, 3);
	cout << "matrix 2 : " << endl;
	PrintMatrix(arr1, 3, 3);

	PrintIntersectedNumbers(arr, arr1, 3, 3);

	system("pause>0");

}