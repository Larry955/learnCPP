#include"Quote.h"

#include<iostream>
using std::endl; using std::cout;

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "sold: " << n
		<< "total due: " << ret << endl;
	return ret;
}

double Bulk_quote::net_price(size_t cnt)const
{
	if (cnt > quantity)
		return (1 - discount) * price * cnt;
	else
		return price * cnt;
}

double Lim_quote::net_price(size_t cnt)const
{
	double discounted = cnt < quantity ? cnt : quantity;
	double undiscounted = cnt - discounted;
	return discounted * (1 - discount) * price
		+ undiscounted * price;
}
