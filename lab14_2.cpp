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

//Do not modify source code above this line 

void inputMatrix(double A[N][N])
{
	for(int current_row = 0 ; current_row < N ; current_row++)
	{
		cout << "Row " << current_row+1 << ": " ;
		for(int current_col = 0 ; current_col < N ; current_col++)
		{
			cin >> A[current_row][current_col] ;
		}
	}
}

void showMatrix(const bool B[N][N])
{
	for(int current_row = 0 ; current_row < N ; current_row++)
	{
		for(int current_col = 0 ; current_col < N ; current_col++)
		{
			cout << B[current_row][current_col] << " ";
		}
		cout << endl ;
	}
}

void findLocalMax(const double A[N][N], bool B[N][N])
{
	for(int i = 0; i < N; i++)
    {
		for(int j = 0; j < N; j++)
		{
			B[i][j] = false;
		}
	}
	for(int current_row = 1 ; current_row < N-1 ; current_row++)
	{
		for(int current_col = 1 ; current_col < N-1 ; current_col++)
		{
			if(A[current_row][current_col] >= A[current_row-1][current_col] && A[current_row][current_col] >= A[current_row+1][current_col] && A[current_row][current_col] >= A[current_row][current_col-1] && A[current_row][current_col] >= A[current_row][current_col+1])
			{
				B[current_row][current_col] = true ;
			}
			else B[current_row][current_col] = false ;
		}
	}
}
