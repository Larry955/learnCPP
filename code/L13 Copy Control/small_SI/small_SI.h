#ifndef SMALL_SI_H
#define SMALL_SI_H

#include<string>
using std::string;

#include<iostream>
using std::endl; using std::cout;

class Sales_data{
public:
	Sales_data(const string &s = " ") :
		bookNo(s), unit_solds(0), revenue(0.0){
		cout << "defalut constructor"<<endl;
	}
	Sales_data(const string &book,unsigned int cnt,double price):
		bookNo(book), unit_solds(cnt), revenue(cnt * price){
		cout << "construcor" << endl;
	}
	Sales_data(const Sales_data &rhs):
		bookNo(rhs.bookNo), unit_solds(rhs.unit_solds), revenue(rhs.revenue){
		cout << "copy constructor" << endl;
	}
	
	Sales_data& operator=(const Sales_data&);
	
	~Sales_data(){ cout << "destructor" << endl; }
private:
	string bookNo;
	int unit_solds;
	double revenue;
};

Sales_data&
Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;			//calls the string::operator=
	unit_solds = rhs.unit_solds;	//uses the build-in int assignment
	revenue = rhs.revenue;			//uses the build-in double assignment
	return *this;					//return a reference to this object
}
#endif