#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
using std::string;

#include<iostream>
using std::istream; using std::ostream;

class Sales_data{
	friend class std::hash < Sales_data > ;
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend ostream& print(ostream&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s){}
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n){}
	Sales_data(istream&);
	string isbn()const{ return bookNo; }
	Sales_data& operator+=(const Sales_data&);
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
	double avg_price()const;
};

namespace std{
	template<>	//we are defining a specialization with the template parameter of Sales_data
	struct hash < Sales_data > {
		//the type used to hash an unordered container must define these type
		typedef size_t result_type;
		typedef Sales_data return_type;
		size_t operator()(const Sales_data&)const;

		//uses synthesize copy control and default constructor
		//other members as before
	};
}	//close the namespace

inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
istream& operator>>(istream&, Sales_data&);

#endif