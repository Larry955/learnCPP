#ifndef QUOTE_H
#define QUOTE_H

#include<iostream>
using std::ostream; using std::istream;

#include<string>
using std::string;

#include<cstddef>
using std::size_t;

#include<memory>

class Quote{
	friend ostream& operator<<(ostream&, const Quote&);
	friend istream& operator>>(istream&, Quote&);

public:
	Quote() = default;

	Quote(const string &book,double sales_price):
		bookNo(book), price(sales_price){}

	virtual ~Quote() = default;

	string isbn()const{ return bookNo; }
	virtual double net_price(size_t n)const{ 
		return n * price; 
	}

protected:
	double price = 0.0;
private:
	string bookNo;
};

class Disc_quote:public Quote{
public:
	Disc_quote() = default;
	Disc_quote(const string &book,double sales_price,
		size_t qty,double dis):
		Quote(book, sales_price), quantity(qty), discount(dis){}

	double net_price(size_t n) const = 0;

	std::pair<size_t, double> discount_polcy(){
		return{ quantity, discount };
	}
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote :public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book,double sales_price,
		size_t qty,double dis):
		Disc_quote(book, sales_price, qty, dis){}
	double net_price(size_t n)const override;
};

class Lim_quote :public Disc_quote{
public:
	Lim_quote(const string &book,double sales_price,
		size_t qty,double dis):
		Disc_quote(book, sales_price, qty, dis){}
	double net_price(size_t n)const;
};

double print_total(ostream&, const Quote&,size_t);
#endif


