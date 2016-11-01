#include"Quote.h"

#include<iostream>
using std::cout; using std::endl;

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " sold total: "
		<< n << " total due: " << ret << endl;
	return ret;
}

double Bulk_quote::net_price(size_t cnt)const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

double Lim_quote::net_price(size_t cnt)const
{
	double discounted = cnt > quantity ? quantity : cnt;
	double undiscounted = cnt - quantity;
	return discounted * (1 - discount) * price
		+ undiscounted * price;
}