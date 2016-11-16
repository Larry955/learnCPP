#include"Sales_data.h"

#include<iostream>
using std::istream; using std::ostream;

//define the hash interface for Sales_data
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
	is >> *this;		//read a transaction from is into this object
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price()const
{
	if (units_sold)return revenue / units_sold;
	return 0;
}

ostream& operator<<(ostream &os, const Sales_data &s)
{
	os << "ISBN: " << s.isbn() << "\tunits_sold: "
		<< s.units_sold << "\trevenue: " << s.revenue;
	return os;
}

istream& operator>>(istream &is, Sales_data &s)
{
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	if (is)		//check that the inputs succeeded
		s.revenue = s.units_sold * price;
	else
		s = Sales_data();	//unput filed,give the object the default status
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

ostream& print(ostream &os, const Sales_data &item)
{
	os << "ISBN: " << item.isbn() << "\tunits_sold: "
		<< item.units_sold << "\trevenue: " << item.revenue;
	return os;
}

istream& read(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}