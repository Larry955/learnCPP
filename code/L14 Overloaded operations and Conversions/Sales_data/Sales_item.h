#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include<iostream>
using std::istream; using std::ostream;

#include<string>
using std::string;

class Sales_item{
	friend istream& operator>>(istream&, Sales_item&);
	friend ostream& operator<<(ostream&, const Sales_item&);
	friend bool operator<(const Sales_item&, const Sales_item&);
	friend bool operator==(const Sales_item&, const Sales_item&);
public:
	Sales_item() = default;
	Sales_item(const string &s) :bookNo(s){}
	Sales_item(istream&is){ is >> *this; }

	Sales_item &operator+=(const Sales_item&);
	string isbn()const { return bookNo; }
	double avg_price()const;
private:
	string bookNo;
	unsigned unit_solds = 0;
	double revenue = 0.0;
};

inline
bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

inline
bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.unit_solds == rhs.unit_solds &&
		lhs.revenue == rhs.revenue;
}

inline 
bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
	return !(lhs == rhs);
}

Sales_item& Sales_item::operator+=(const Sales_item &rhs)
{
	unit_solds += rhs.unit_solds;
	revenue += rhs.revenue;
	return *this;
}
Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
	Sales_item sum(lhs);
	sum += rhs;
	return sum;
}

istream& operator>>(istream &in, Sales_item &item)
{
	double price = 0.0;
	in >> item.bookNo >> item.unit_solds >> price;
	if (in)
		item.revenue = item.unit_solds * price;
	else
		item = Sales_item();
	return in;
}

ostream& operator<<(ostream &out, const Sales_item &item)
{
	out << item.isbn() << " " << item.unit_solds
		<< " " << item.revenue << " " << item.avg_price();
	return out;
}

double Sales_item::avg_price() const 
{
	if (unit_solds)
		return revenue / unit_solds;
	else
		return 0;
}
#endif