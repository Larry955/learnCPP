#include<iostream>
using std::cin; using std::cout;
using std::cerr; using std::endl;
using std::ostream;

#include<string>
using std::string;

#include<map>
using std::map;

#include<cstddef>
using std::size_t;

#include"debug_rep.h"
#include"Sales_data.h"

//function to end the recursion and print the last element
template<typename T>ostream& print(ostream &os, T t)
{
	return os << t;
}

template<typename T,typename ...Args>
ostream& print(ostream &os, const T &t, const Args&...rest)
{
	os << t<<",";
	return print(os, rest...);
}

//call debug_rep on each argument int the call to print
template<typename ...Args>
ostream& errorMsg(ostream &os, const Args&...args)
{
	//print(os,debug_rep(a1),debug_rep(a2),debug_rep(a3)...
	return print(os, debug_rep(args)...);
}

struct ErrorCode
{
	ErrorCode(size_t n) :e(n){}
	size_t num()const{ return e; }
	string lookup()const{ return errors[e]; }
	size_t e;
	static map<size_t, string>errors;
};

map<size_t, string> ErrorCode::errors = { { 42, "Error:42" } , { 1024, "Error:1024" } };

int main()
{
	Sales_data item("000111", 20, 5);
	string fcnName("itemProcess");
	ErrorCode code(42);
	string otherData("invalid ISBN");

	errorMsg(cerr, fcnName, code.num(),code.lookup(), otherData, "other", item);
	cout << endl;

	print(cerr, debug_rep(fcnName), debug_rep(code.num()), debug_rep(code.lookup()),
		debug_rep(otherData), debug_rep("other"), debug_rep(item));
	cout << endl;
	system("pause");
}