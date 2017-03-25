#include<iostream>
using std::cout; using std::endl;

void insertSort(int A[], int n)
{
	for (int i = 1; i != n; ++i){		//for A[i...n-1]
		int j = i - 1;	//for A[0...i-1]
		int key = A[i];	
		while (j >= 0 && A[j] > key){	//if A[i](key) is less than A[j]
			A[j + 1] = A[j];	//move A[j...i-1]to A[j+1...i] 
			--j;
		}
		//j minus one before quiting while loop,so we need to add one
		A[j + 1] = key;
	}
}

int main()
{
	int A[] = { 2, 9, 8, 7, 5, 6, 4, 7, 3, 1 };
	insertSort(A, sizeof(A) / sizeof(A[0]));
	for (int i = 0; i != sizeof(A) / sizeof(A[0]); ++i)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
}