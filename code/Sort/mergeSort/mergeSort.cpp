#include<iostream>
using std::cout; using std::endl;

void merge(int A[], int, int, int);

//O(nlgn)
void merge_sort(int A[], int first, int last)
{
	if (first >= last)return;
	int mid = (first + last) / 2;
	merge_sort(A, first, mid);
	merge_sort(A, mid + 1, last);
	merge(A, first, mid, last);
}

void merge(int A[], int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int *B = new int[n1 + 1];
	int *C = new int[n2 + 1];
	int j = 0;
	int k = 0;
	for (int i = first; i != last + 1; ++i){
		if (i <= mid){	
			B[j] = A[i];
			++j;
		}
		else{
			C[k] = A[i];
			++k;
		}
	}
	B[n1] = 9999;
	C[n2] = 9999;
	/*for (int i = 0; i != n1 + 1; ++i){
		cout << "B: " << B[i] << " ";
	}
	cout << endl;
	for (int i = 0; i != n2 + 1; ++i)
		cout << "C: " << C[i] << " ";
	cout << endl;
*/
	int BIndex = 0;
	int CIndex = 0;
	for (int k = first; k != last + 1; ++k){
		if (B[BIndex] < C[CIndex]){
			A[k] = B[BIndex];
			++BIndex;
		}
		else{
			A[k] = C[CIndex];
			++CIndex;
		}
	}
	delete[] B;
	delete[] C;
}

int main()
{
	int A[] = { 4, 5, 1, 9, 7, 3, 8 };
	int size = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, size - 1);
	for (int i = 0; i != size; ++i)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
}