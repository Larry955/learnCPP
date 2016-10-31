#include"Quote.h"
#include<iostream>
using std::ostream;
using std::endl; using std::cout;

#include<cstddef>
using std::size_t;

#include<vector>
using std::vector;

#include<memory>
using std::make_shared;
using std::shared_ptr;

#include<algorithm>
using std::min;

double print_total(ostream &os, Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " #sold: " << n
		<< " total value " << ret << endl;
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
	double discounted = min(cnt, quantity);
	double undiscounted = cnt - discount;
	return discounted * (1 - discount) * price
		+ undiscounted * price;
}