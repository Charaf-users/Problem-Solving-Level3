#include<iostream>
#include<string>
#include<iomanip>

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


bool IsNumberInMatrix (int arr[3][3], int Number, short Rows, short Cols) {
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

int main() {
	int arr[3][3] = { {10,22,56},{12,30,67},{33,68,90} };

	int number;

	PrintMatrix(arr, 3, 3);
	

	cout << "what is the number you want to find in matrix : ";
	cin >> number;

	if (IsNumberInMatrix(arr,number,3,3)) {
		cout << " Yes,the is there  thank you";
	}
	else {
		cout << "No, is not there Thank  you";
	}
	system("pause>0");
}