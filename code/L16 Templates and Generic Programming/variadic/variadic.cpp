#include<initializer_list>
using std::initializer_list;

#include<algorithm>
using std::min;

#include<iostream>
using std::cout; using std::endl;

#include"Sales_data.h"

//function to end the recursion and print the last element
//this version must be defined before the variadic version of print is defined
template<typename T>
ostream& print(ostream &os, const T &t)
{
	return os << t;
}

//this version will be called for all but the last element in the pack
template<typename T,typename... Args>
ostream& print(ostream &os, const T &t,const Args&...rest)
{
	os << t <<",";	//print the first element
	return print(os, rest...);	//resursive call, print the rest elements
}

template<typename T>
bool bigger(const T &t, initializer_list<T>i1)
{
	if (i1.size() == 0)
		return false;
	auto b = i1.begin();
	while (b != i1.end())
	{
		if (*b < t)
			return true;
		else
			++b;
	}
	return false;
}

//elements in the list must have the same type
template<typename T>
T min_elem(initializer_list<T>i1)
{
	if (i1.size() == 0)
		throw "empty";
	auto b = i1.begin();
	T ret(*b++);	//start off with the first element as the smallest
	while (b != i1.end())	//till we run out of elements
	{
		ret = min(ret, *b++);	//update ret if we find a smaller value
	}
	return ret;	//return the value we found
}

template<typename T>
T min_elem(const T &t)
{
	return t;
}

template<typename T,typename... Args>
T min_elem(T val, Args... args)
{
	//resursive call
	T val2 = min_elem(args...);

	//requires that the type of val and val2 are comparable using <
	return val < val2 ? val : val2;
}

int main()
{
	//no braces, so calls variadic version of min_elem
	cout << min_elem(1, 2, 3, 4, 5, 6, 7, 8, 9)<<endl;
	//calls min_elem that takes a single argument 
	//of type initializer_list<int>
	cout << min_elem({ 1, 2, 3, 5, 9, 7, 5, 9, 4 })<<endl;

	int i = 5;
	cout << bigger(i, { 1, 2, 3, 4, 5, 9, 7, 9, 4 })<<endl;

	string s("hello,larry");
	print(cout, i, s, 42);	//two parameters in the pack
	cout << endl;
	print(cout, i, s);	//one
	cout << endl;
	print(cout, i);	//none
	cout << endl;

	//Sales_data must define its own < operator
	Sales_data item1("000111", 20, 5), item2("111000", 200, 10);
	Sales_data item3("000011", 10, 20), item4("010101", 12, 15);
	cout << min_elem(item1, item2, item3, item4)<<endl;

	system("pause");
}

