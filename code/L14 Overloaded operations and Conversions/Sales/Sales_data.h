#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
using std::istream; using std::ostream;

#include<string>
using std::string;

class Sales_data{  
	friend ostream &operator<<(ostream&, const Sales_data&);
	friend istream &operator>>(istream&, Sales_data&);

	friend bool operator==(const Sales_data&, const Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);
	friend istream &read(istream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s){}
	Sales_data(const string &s,unsigned n,double p):
		bookNo(s), unit_solds(n), revenue(p*n){}
	Sales_data(istream&);
	
	string isbn()const{ return bookNo; }
	Sales_data& operator+=(const Sales_data&);
private:
	double avg_price()const;
	string bookNo;
	unsigned unit_solds = 0;
	double revenue = 0.0;
};

//non-member Sales_data operators
inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.unit_solds == rhs.unit_solds &&
		lhs.revenue == rhs.revenue;
}

inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

//old versions
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream &, const Sales_data&);
istream &read(istream&, Sales_data&);

//new versions
Sales_data operator+(const Sales_data&, const Sales_data&);
ostream &operator<<(ostream&, const Sales_data&);
istream &operator>>(istream&, Sales_data&);

#endif