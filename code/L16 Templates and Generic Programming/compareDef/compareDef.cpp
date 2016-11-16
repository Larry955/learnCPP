#include"Sales_data.h"

#include<functional>
using std::less;

#include<iostream>
using std::cout; using std::cin; using std::endl;
template<typename T,typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
	if (f(v1, v2))return 1;
	if (f(v2, v1))return -1;
	return 0;
}

int main()
{
	cout << compare(0, 42) << endl;

	Sales_data item1(cin), item2(cin);
	cout << compare(item1, item2, compareIsbn);
	system("pause");
}