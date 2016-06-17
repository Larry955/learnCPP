#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void bubbleSort(int a[],int n)			//冒泡排序
{
	for (size_t i = 1; i != n; ++i){
		for (size_t j = n - 1; j >= i; --j){
			if (a[j - 1] > a[j]){
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

bool sorted(int a[], int n)		//判断数组是否有序
{
	for (size_t i = 0; i != n - 1; ++i){
		if (a[i] <= a[i + 1])
			continue;
		else
			return false;
	}
	return true;
}
int main()
{
	srand(time(0));		//初始化随机计数器

	const int n = 10;
	int a[n];
	for (size_t i = 0; i != n; ++i)
		a[i] = rand() % 10 + 1;	//生成1-10的数
	cout << "Print those random numbers:\n";
	for (size_t i = 0; i != n; ++i)
		cout << a[i] << " ";		//打印该组随机数

	cout << sorted(a, n) << endl;		//判断该组随机数是否有序
	
	bubbleSort(a, n);		//将该组随机数按非递减顺序排列

	cout << "\n\nAfter sorted,the array is sorted or not sorted?";
	cout << "\nsorted return 1,otherwise return 0:	";
	cout << sorted(a, n) << endl;;

	for (size_t i = 0; i != n; ++i)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
}