#include<iostream>
using std::endl; using std::cout;

#include<cstddef>
using std::size_t;

#include"Quote.h"	

int main()
{
	Quote base("000111", 45);
	Bulk_quote bulk("111000", 45, 3, 0.15);

	print_total(cout, base, 20);	//calls Quote version of net_price
	print_total(cout, bulk, 20);	//calls Bulk_quote version of net_price

	Quote basic("111000", 50);
	Bulk_quote derived("101000", 50, 5, 0.19);
	cout << derived.net_price(20);	//calls Bulk_quote::net_price
	cout << endl;

	base = derived;	//copies the Quote part of derived into base
	cout << base.net_price(20);
	cout << endl;

	Quote &item = derived;	//dynamic and static types of item differ
	cout << item.net_price(20) << endl;	//calls Bulk_quote::net_price

	cout<<"item.isbn(): "<<item.isbn()<<endl;	//calls Bulk_quote::isbn

	system("pause");
}