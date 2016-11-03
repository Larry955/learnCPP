
#ifndef BASKET_H
#define BASKET_H

#include<iostream>
using std::ostream;

#include<memory>
using std::make_shared;
using std::shared_ptr;

#include<set>
using std::multiset;

#include<stdexcept>
#include<cstddef>
#include<utility>
#include"Quote.h"

//holds items being purchased
class Basket{
public:
	//Basket uses synthesized default constructor and copy-constructor assignment
	void add_item(const shared_ptr<Quote> &sale){
		items.insert(sale);
	}

	void add_item(const Quote &sale){		//copy the given object
		items.insert(shared_ptr<Quote>(sale.clone()));
	}

	void add_item(Quote &&sale){		//move the given object
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}

	//prints the total price for each book
	//and the overall total for all items in the basket
	double total_receipt(ostream&)const;

	//for debuging purposes.prints items in the basket
	void display(ostream&)const;
private:
	//function to compare shared_ptrs needed by the multiset member
	static bool compare(const shared_ptr<Quote> &lhs,
		const shared_ptr<Quote> &rhs){
		return lhs->isbn() < rhs->isbn();
	}
	//multiset to hold multiple quotes,ordered by the compare member
	multiset < shared_ptr<Quote>, decltype(compare)* >items{compare};
};
#endif
