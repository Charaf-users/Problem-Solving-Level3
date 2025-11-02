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
short countnumber(int arr[3][3],short number, short Rows, short Cols) {

	int counter=0;
	
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == number)
			counter++;
		}
		cout << "\n";
	}
	
	return counter;
}



int main() {

	int arr[3][3] = { {1,9,9 },{9,1,1},{3,3,3} };
	short number;
	PrintMatrix(arr, 3, 3);
	cout << "what the number in matrix you want to count ? :  ";
	cin >> number;
	cout << "number is : " << countnumber(arr, number, 3, 3) << endl;;

	system("pause>0");
}