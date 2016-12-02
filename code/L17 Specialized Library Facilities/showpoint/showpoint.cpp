#include<iostream>
using std::cin; using std::cout; using std::endl;
using std::showpoint; using std::noshowpoint;

int main()
{
	cout << 10.0 << endl;		//prints 10
	cout << showpoint << 10.0		//prints 10.0000
		<< noshowpoint << endl;	//revert to default format

	cout << 10.0 << endl;	//prints 10
	system("pause");
}