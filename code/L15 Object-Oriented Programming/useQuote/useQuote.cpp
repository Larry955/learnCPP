#include<iostream>
using std::cout; using std::endl;

#include"Quote.h"

int main()
{
	Quote base("000111", 50);
	print_total(cout, base, 10);	//calls Quote::net_price

	Bulk_quote bulk("000111", 50, 5, 0.19);
	print_total(cout, bulk, 10);	//calls Bulk_quote::net_price

	Quote *baseP = &bulk;
	cout << baseP->net_price(10) << endl;	//calls Bulk_quote::net_price

	cout << baseP->Quote::net_price(10) << endl;	//calls Quote::net_price
	system("pause");
}