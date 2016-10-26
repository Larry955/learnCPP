#include<iostream>
using std::endl;

#include<string>
using std::string;

#include"Sales_data.h"

Sales_data::Sales_data(istream&is)
{
	is >> *this;
}

double Sales_data::avg_price()const
{
	if (unit_solds)
		return revenue / unit_solds;
	return 0;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	unit_solds += rhs.unit_solds;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	if (compareIsbn(lhs, rhs)){
		Sales_data sum = lhs;
		sum += rhs;
		return sum;
	}
	else{
		std::cerr << "can't add two different books" << std::endl;
		exit(0);
	}
}

istream& operator>>(istream &is, Sales_data &item)
{
	double price;	//no need to initialize,we'll read into price before we use it
	is >> item.bookNo >> item.unit_solds >> price;
	if (is)		//check that the inputs suceeds
		item.revenue = item.unit_solds * price;
	else
		item = Sales_data();	//input failed,give the object the default state
	return is;
}

ostream& operator<<(ostream& os, const Sales_data &item)
{
	os <<"isbn: "<< item.isbn() << "\t" <<"unit_solds: "<< item.unit_solds << "\trevenue: "
		<< item.revenue << "\tavg_price: " << item.avg_price();
	return os;
}

//operators replace these original functions
istream &read(istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.unit_solds >> price;
	item.revenue = item.unit_solds * price;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << "\t" << item.unit_solds << "\t"
		<< item.revenue << "\t" << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;	//copy data members from lhs to sum
	sum += rhs;	//add rhs into sum
	return sum;
}

