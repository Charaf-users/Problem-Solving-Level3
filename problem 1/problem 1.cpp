#include<iostream>
#include<iomanip>;

using namespace std;

int randomnumber(int from, int to) {

	int randnum = rand() % -(to - from+1 ) + from;

	return randnum;
}


void randomMatrixNimbers(int arr[3][3], int rows, int cols) {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			arr[i][j] = randomnumber(1, 100);
		}
	}
}
	void printMatrix(int arr[3][3], int rows, int cols){
		cout << "the following 3x3  random matrix :" << endl;

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				cout  << setw(3) << arr[i][j] << "    ";
			}
			cout << endl;
		}

	
	}

	int main() {
		srand((unsigned)time(NULL));

		int arr[3][3];
		
		randomMatrixNimbers(arr,3,3);

		printMatrix(arr, 3, 3);



		system("pause>0");

	}


	