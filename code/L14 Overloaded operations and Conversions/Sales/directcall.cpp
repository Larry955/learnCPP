#include"Sales_data.h"

#include<iostream>
using std::endl; using std::cout;

int main()
{
	Sales_data data1, data2;
	std::cin >> data1 >> data2;	//read Sales_data transactions
	cout << data1 + data2 << endl;	//write sum of Sals_data objects
	cout << "sum of ints: "<<42 + 5 << endl;	//write sum of ints

	//equivalent calls to nonmember operator functions
	data1 + data2;	//normal expressions
	operator+(data1, data2);	//equivalent function call
	cout << operator+(data1, data2) << endl;

	data1 += data2;
	data1.operator+=(data2);

	cout << data1 << endl;
	system("pause");
}	