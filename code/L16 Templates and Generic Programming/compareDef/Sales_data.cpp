#include"Sales_data.h"

#include<functional>
using std::hash;

namespace std{
	size_t hash<Sales_data>::operator()(const Sales_data &s)const
	{
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}

Sales_data::Sales_data(istream &is)
{
	is >> *this;		//read a transaction from input into this object
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

double Sales_data::avg_price()const
{
	if (units_sold)
		return revenue / units_sold;
	return 0;
}

ostream& operator<<(ostream &os, const Sales_data &item)
{
	os << "ISBN: " << item.isbn() << "\tunits_sold: "
		<< item.units_sold << "\trevenue: " << item.revenue;
	return os;
}

istream& operator>>(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

