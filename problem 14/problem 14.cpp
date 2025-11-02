#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	cout << "the matrix 1 : " << endl;
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


bool checkScalare(int arr[3][3], short Rows, short Cols) {
	int checkScalare = arr[0][0];
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (i == j && arr[i][j] != checkScalare) {
				return false;
			}
			else if (i != j && arr[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	//int arr[3][3] = { {1,2,3} ,{ 4,5,6 },{7,8,9 } };
	int arr[3][3] = { {1,0,0 },{0,1,0},{0,0,3} };
	PrintMatrix(arr, 3, 3);

	if (checkScalare(arr, 3, 3)) {
		cout << "yes , this Marix is scalare " << endl;
	}
	else {
		cout << "No, this Matrix not scalare" << endl;
	}
	system("pause>0");
}