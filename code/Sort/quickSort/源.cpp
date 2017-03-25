#include<iostream>
using std::cout; using std::endl;

int partition(int A[], int, int);

//O(nlgn)
void quickSort(int A[], int first, int last)
{
	if (first >= last)
		return;
	int part = partition(A, first, last);
	quickSort(A, first, part - 1);
	quickSort(A, part + 1, last);
}

int partition(int A[], int first, int last)
{
	//static int num = 0;
	int q = first;	
	for (int u = first; u != last; ++u){
		if (A[u] <= A[last]){
			int tmp = A[q];
			A[q] = A[u];
			A[u] = tmp;
			++q;
		}
	}
	int tmp = A[q];
	A[q] = A[last];
	A[last] = tmp;
	/*++num;
	cout << "num" << num<<" ";
	for (int i = first; i <= last; ++i)
		cout << A[i] << " ";
	cout << endl;*/
	return q;
}
int main()
{
	int A[] = { 5, 1, 6, 7, 4, 15, 9, 8 };
	int size = sizeof(A) / sizeof(A[0]);
	quickSort(A, 0, size - 1);
	for (int i = 0; i != size; ++i)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
}