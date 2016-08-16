#include<string>
using std::string;

#include<vector>
using std::vector;

#include<iostream>
using std::istream; using std::ostream;
using std::endl; using std::cin; using std::cout;

#include"Foo.h"


//factory returns a pointer to a dynamically allocated object
Foo* factory(T arg)
{
	//process arg as appropriate
	return new Foo(arg);	//caller is responisible for deleting this memory
}

Foo* use_factory(T arg)
{
	Foo *p = factory(arg);
	print(cout, *p);
	cout << endl;
	//use p
	return p;		//caller must delete the memory
}

int main()
{
	T arg;
	while (cin >> arg){
		auto p = use_factory(arg);
		delete p;		//remember delete memory from use_factory
	}
	getchar();
}