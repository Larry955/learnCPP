#include<iostream>
using std::cout; using std::endl;

struct Base
{
	Base() :mem(0){}
protected:
	int mem;

};

struct Derived:Base
{
	Derived(int i) :mem(i){}		//initializes Derived::mem to i
						//Base::mem is default initialized
	int get_mem(){ return mem; }	//return Derived::mem
	int get_base_mem(){ return Base::mem; }
protected:
	int mem;	//hides mem in the base
};

int main()
{
	Derived d(42);
	cout << d.get_mem() << endl;	//prints 42
	cout << d.get_base_mem() << endl;	//prints 0
	system("pause");
}