#include<iostream>
using std::cout; using std::endl; using std::ostream;

#include<map>
using std::map;

#include<functional>
using std::function;

#include<string>
using std::string;

//ordinary function
int add(int i, int j){ return i + j; }

//lambda,which generates an unnamed function-object class
auto mod = [](int i, int j){return i % j; };

struct divide{
	int operator()(int denominator, int divisior){ return denominator / divisior; }
};

int main()
{
	function<int(int, int)>f1 = add;	//function pointer
	function<int(int, int)>f2 = divide();	//callable class type
	function<int(int, int)>f3 = [](int i, int j)
					{return i * j;};	//lambda
	
	cout << f1(4, 2) << endl;	//prints 6
	cout << f2(4, 2) << endl;	//prints 2
	cout << f3(4, 2) << endl;	//prints 8

	//table of callable objects corresponding to each binary operator
	//all the callables must be two ints and return a int
	//an element can be a function pointer,function object,or lambda
	map<string, function<int(int, int)>>binops = 
	{
		{ "+", add },	//function pointer
		{ "-", std::minus<int>() },	//library function object
		{ "/", divide() },	//user-defined function object
		{ "*", [](int i, int j){return i * j; } },	//unnamed lambda
		{ "%", mod }	//named lambda
	};
	cout << binops["+"](10, 5) << endl;	//calls add(10,5)
	cout << binops["-"](10, 5) << endl;		//use the call operator of the minus<int> object
	cout << binops["*"](10, 5) << endl;		//calls the lambda function object
	cout << binops["/"](10, 5) << endl;		//use the calll operator of the divide object
	cout << binops["%"](10, 5) << endl;	////calls the lambda function object

	system("pause");
}