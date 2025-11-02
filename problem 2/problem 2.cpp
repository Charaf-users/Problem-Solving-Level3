#include<iostream>
#include<iomanip>

using namespace std;

int randomnumber(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}

void randomMatrixNumber(int arr[3][3], short rows, short cols) {
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			arr[i][j] = randomnumber(1, 100);
		}
	}

}
void printRandomMatrixNumber(int arr[3][3], short rows, short cols) {

	cout << "the following 3x3 random matrix is : " << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			cout << setw(3) << arr[i][j] << "   ";
		}
		cout << "\n";
	}

}
int  sumofrows(int arr[3][3], short numrows, short cols) {
	int sum=0;

		for (int j = 0; j <= cols -1; j++) {
			
			 sum  += arr[numrows][j] ;
		}
		cout << "\n";
	
		return sum;
}
void printsumarray(int arr[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++) {
		cout << "the rows sum " << i + 1 << ":" << sumofrows(arr,i,cols)<<endl;
	}
	
}



int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];

	randomMatrixNumber(arr, 3, 3);
	printRandomMatrixNumber(arr, 3, 3);

	printsumarray(arr, 3, 3);



	system("pause>0");


}