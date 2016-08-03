#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 5, 3, 4 };

	int *pbeg = begin(arr);
	int *pend = end(arr);
	while (pbeg != pend && *pbeg >= 0){
		++pbeg;
	}
	cout << *pbeg << endl;
	system("Pause");
}