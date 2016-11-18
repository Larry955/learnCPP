#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
using std::istream; using std::ostream;

#include<string>
using std::string;

class Sales_data{
	friend class std::hash < Sales_data > ;
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator<(const Sales_data&, const Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s){}
	Sales_data(const string &s,unsigned n,double p):
		bookNo(s), units_sold(n), revenue(n*p){}
	Sales_data(istream&);
	Sales_data& operator+=(const Sales_data&);
	string isbn()const{ return bookNo; }

private:
	double avg_price()const;
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

namespace std{
	template<>
	struct  hash<Sales_data>
	{
		typedef size_t return_type;
		typedef Sales_data argument_type;

		size_t operator()(const Sales_data&)const;
	};
}

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold&&
		lhs.revenue == rhs.revenue;
}
inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
inline
bool operator<(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo < rhs.bookNo;
}
#endif