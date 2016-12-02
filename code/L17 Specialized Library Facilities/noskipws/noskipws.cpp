#include<iostream>
using std::cin; using std::cout; using std::endl;
using std::noskipws; using std::skipws;

int main()
{
	cin >> noskipws;
	char ch;
	while (cin >> ch)
		cout << ch;
	cin >> skipws;
	system("pause");
}