#include<utility>
#include<iostream>

class Foo{
public:
	Foo() = default;	//defalut constructor needed because Foo has a copy constructor

	Foo(const Foo&);	//copy constructor
};

Foo::Foo(const Foo&){ std::cout << "foo copy ctor " << std::endl; }

int main()
{
	Foo x;
	Foo y(x);		//copy constructor,x is a lvalue

	Foo z(std::move(x));	//copy constructor,because there is no move constructor
	getchar();
}