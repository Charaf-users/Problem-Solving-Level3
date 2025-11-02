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

bool IsMatrixPalindrome(int arr[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols / 2; j++) {
			if (arr[i][j] != arr[i][Cols - 1 - j])
			{
				return false;
			}
		}
	}
	return true;
}

int main() {
	int arr[3][3] = { {1, 2, 1},
		{5, 5, 5},
		{7, 3, 7} };


	cout << "matrix 1 : " << endl;
	PrintMatrix(arr, 3, 3);
	if (IsMatrixPalindrome(arr, 3, 3)) {
		cout << "yes ,  is palidrome" << endl;
	}
	else {
		cout << "No, is not palidrome number" << endl;
	}


	system("pause>0");

}