#include<string>
using std::string;
#include<iostream>

#include<utility>

class HasPtr{
	friend void swap(const HasPtr &, const HasPtr&);
public:
	//default constructor and constructor that takes a string
	HasPtr(const string s = string()):
		ps(new string(s)), i(0){ }
	
	//copy constructor
	HasPtr(const HasPtr &p):
		ps(new string(*p.ps)), i(p.i){ }

	//move constructor
	HasPtr(HasPtr &&p)noexcept : ps(new string(*p.ps)), i(p.i){ }

	//assignment operator is both the move- and copy-assignment operator 
	HasPtr operator=(const HasPtr &rhs){
		swap(*this, rhs); return *this; 
	}

	//destructor
	~HasPtr(){ delete ps; }
private:
	string *ps;
	int i;
};

inline
void swap(const HasPtr &lhs, const HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);		//swap the pointers, not the strings
	swap(lhs.i, rhs.i);			//swap the int numbers
}

int main()
{
	HasPtr hp("Hi,Larry");
	HasPtr hp2(hp);

	hp = hp2;		//hp2 is a lvalue,copy constructor used to copy hp2
	hp = std::move(hp2);	//move constructor moves hp2
}