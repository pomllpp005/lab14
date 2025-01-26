#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}
void showMatrix(const bool result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
void inputMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}
void findLocalMax(const double matrix[N][N], bool result[N][N]) {
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = false;
        }
    }

   
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            if (matrix[i][j] >= matrix[i - 1][j] && // Top
                matrix[i][j] >= matrix[i + 1][j] && // Bottom
                matrix[i][j] >= matrix[i][j - 1] && // Left
                matrix[i][j] >= matrix[i][j + 1]) { // Right
                result[i][j] = true;
            }
        }
    }
}