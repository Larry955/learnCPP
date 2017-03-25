#include<iostream>
using std::cout;
using std::endl;

//O(n^2)
void selectSort(int A[], int n)
{
	for (int i = 0; i != n - 1; ++i){	
		int smallest = i;		//set smallest as the smallest number's index
		for (int j = i + 1; j != n; ++j){	//for A[i+1...n-1]
			if (A[j] < A[smallest]){		//if A[j] is less than A[smallest]
				smallest = j;		//update smallest
			}
		}	
		//after the for loop,smallest holds the smallest number's iindex in A[i+1...n-1]
		//so exchange these two numbers to ensure that A[i] is the smallest number 
		int tmp = A[i];
		A[i] = A[smallest];
		A[smallest] = tmp;
	}
}

int main()
{
	int A[] = { 5, 8, 1, 6, 7, 9, 4, 7 };
	selectSort(A, sizeof(A) / sizeof(A[0]));
	for (int i = 0; i != sizeof(A) / sizeof(A[0]); ++i)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
}