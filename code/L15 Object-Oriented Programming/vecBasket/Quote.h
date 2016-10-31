#ifndef QUOTE_H
#define QUOTE_H

#include<iostream>
using std::ostream; using std::istream;

#include<memory>

#include<string>
using std::string;

#include<cstddef>
using std::size_t;

//Item sold at a undiscounted price
//derived classes will define various discounted strategies
class Quote{
	friend ostream& operator<<(ostream &, const Quote&);
	friend istream& operator>>(istream &, Quote&);
public:
	Quote() = default;

	Quote(const string &book,double sales_price):
		bookNo(book), price(sales_price){}

	//virtual destrutor needed
	//if a base pointer pointing to a derived object which is deleted 
	virtual ~Quote() = default;	//dynamic binding for the destructor
	
	string isbn()const { return bookNo; }
	
	//returns the total sale price for the specified number of items
	//derived classes will override and apply different discounted strategies
	virtual double net_price(size_t n)const { return price * n; }

	//virtual function to return a dynamically allocated copy of itself

#ifdef REFMEMS
	virtual Quote* clone()const &{return new Quote(*this);}
	virtual Quote* clone()&&{return new Quote(std::move(*this));}
#else
	virtual Quote* clone()const{ return new Quote(*this); }
#endif

private:
	string bookNo;	//ISBN of this item
protected:
	double price = 0.0;	//normal,undiscounted price
};

//abstract base class to hold the discount rate and quantity
//derived classes will implement pricing strategies using these data
class Disc_quote:public Quote{
public:
	//other members as before
	Disc_quote() = default;
	Disc_quote(const string &book,double price,size_t qty,double disc):
		Quote(book, price), quantity(qty), discount(disc){}

	double net_price(size_t)const = 0;

	std::pair<std::size_t, double> discount_policy()const{
		return{ quantity, discount };
	}
protected:
	size_t quantity = 0;	//purchase size for the discount to apply
	double discount = 0.0;	//fractional discount to apply
};

//the discount kicks in when a specified number of copies of the same book are sold
//the discount is expressed as a fraction used to reduce the normal price
class Bulk_quote :public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const string &s,double p,size_t q,double dis):
		Disc_quote(s, p, q, dis){}

	double net_price(size_t)const override;
#ifdef REFMEMS
	Bulk_quote* clone()const &{return new Bulk_quote(*this);}
	Bulk_quote* clone()&&{return new Bulk_quote(std::move(*this));}
#else
	Bulk_quote* clone()const{ return new Bulk_quote(*this); }
#endif
};

//discount for a specified number of copies,
//additional copies sold at normal price
class Lim_quote :public Disc_quote{
public:
	//Lim_quote() = default;
	Lim_quote(const string &book = " ", double sales_price = 0,
		size_t quantity = 0, double discount = 0):
		Disc_quote(book, sales_price, quantity, discount){}

	//overrides base version so as to implement limted discounted policy
	double net_price(size_t)const;
#ifdef REFMEMS
	Lim_quote* clone()const &{return new Lim_quote(*this);}
	Lim_quote* clone()&&{return new Lim_quote(std::move(*this));}
#else
	Lim_quote* clone()const{ return new Lim_quote(*this); }
#endif
};

double print_total(ostream&, Quote&, size_t);
#endif