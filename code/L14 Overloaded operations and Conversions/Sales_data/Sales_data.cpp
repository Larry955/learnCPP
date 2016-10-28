#include"Sales_data.h"

Sales_data&	Sales_data::operator+=(const Sales_data &rhs)
{
	unit_solds += rhs.unit_solds;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price()const
{
	if (unit_solds)
		return revenue / unit_solds;
	else
		return 0;
}

Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

istream& operator>>(istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.unit_solds >> price;
	if (is)
		item.revenue = item.unit_solds * price;
	else
		item = Sales_data();
	return is;
}

ostream& operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.unit_solds << " " <<
		item.revenue << " " << item.avg_price();
	return os;
}

istream& read(istream& is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.unit_solds >> price;
	item.revenue = item.unit_solds * price;
	return is;
}

ostream& print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.unit_solds << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}	