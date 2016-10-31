#include"Quote.h"

#include<iostream>
using std::endl; using std::cout;

#include<vector>
using std::vector;

#include<memory>
using std::shared_ptr; using std::make_shared;

int main()
{
	Quote base("000111", 50);
	Bulk_quote bulk("111000", 50, 10, 0.25);

	vector<Quote>basket;
	basket.push_back(base);
	//copies only the Bulk part of the object into basket
	basket.push_back(bulk);

	//calls version defined by Quote,prints 750
	cout << basket.back().net_price(15) << endl;

	//better approach, store share_ptr
	vector<shared_ptr<Quote>>basket2;
	basket2.push_back(make_shared<Quote>("000111", 50));
	basket2.push_back(
		make_shared<Bulk_quote>("111000", 50, 10, 0.25));
	//calls the version by Bulk_quote,prints 562.5
	cout << basket2.back()->net_price(15)<<endl;

	system("pause");
}